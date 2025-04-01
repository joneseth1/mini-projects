(* src/neural_network.ml *)

open Matrix

type layer = {
  mutable weights : matrix;  
  mutable biases : matrix;   
  activation_fn : (float -> float);  
}

type t = {
  layers : layer list;  
}

(** Create a neural network with a given number of neurons in each layer *)
let create_nn (layer_sizes : int list) activation_fn =
  let layers = 
    let rec create_layers sizes =
      match sizes with
      | [_] -> []  (* No more layers to create after the last layer *)
      | input_size :: output_size :: rest ->
        let weights = Matrix.random input_size output_size in
        let biases = Matrix.random 1 output_size in
        let layer = { weights; biases; activation_fn } in
        layer :: create_layers (output_size :: rest)  (* Recurse with the rest of the sizes *)
      | _ -> failwith "Invalid network size"
    in
    create_layers layer_sizes  (* Start creating layers from the given sizes *)
  in
  { layers }


(** Forward pass through the network *)
let forward (network : t) (input : matrix) : matrix =
  let rec forward_layers layers input_matrix =
    match layers with
    | [] -> input_matrix  
    | layer :: rest ->
      let weighted_input = Matrix.dot input_matrix layer.weights in
      let output_with_bias = Matrix.add_scalar weighted_input 1.0 in
      let activated_output = Matrix.apply_activation layer.activation_fn output_with_bias in
      forward_layers rest activated_output  
  in
  forward_layers network.layers input

(* Perform a forward pass and store activations for backpropagation *)
let forward_propagate nn input =
  let activations = ref [input] in
  let current_input = ref input in
  List.iter (fun layer ->
    let z = Matrix.dot !current_input layer.weights in
    let z = Matrix.add_matrix z layer.biases in
    let a = Matrix.apply_activation layer.activation_fn z in
    activations := a :: !activations;
    current_input := a
  ) nn.layers;
  List.rev !activations

(* Compute backward pass and update weights *)
let backward_propagate nn activations expected_output learning_rate =
  let num_layers = List.length nn.layers in
  let errors = ref [Matrix.sub (List.nth activations num_layers) expected_output] in

  (* Backpropagate errors *)
  List.iteri (fun i _ ->
    let index = num_layers - i - 1 in
    if index > 0 then
      let prev_activation = List.nth activations (index - 1) in
      let delta = Matrix.hadamard (List.hd !errors) (Matrix.apply_activation  Activation.sigmoid_derivative prev_activation) in
      errors := delta :: !errors
  ) (List.rev nn.layers);

  (* Update weights and biases *)
  List.iteri (fun i layer ->
    let delta = List.nth !errors i in
    let prev_activation = List.nth activations i in
    let weight_update = Matrix.dot (Matrix.transpose prev_activation) delta in
    layer.weights <- Matrix.sub layer.weights (Matrix.scalar_mul learning_rate weight_update);
    layer.biases <- Matrix.sub layer.biases (Matrix.scalar_mul learning_rate delta)
  ) nn.layers

(* Train the network *)
let train nn training_data learning_rate epochs =
  for epoch = 1 to epochs do
    List.iter (fun (input, expected_output) ->
      let activations = forward_propagate nn input in
      backward_propagate nn activations expected_output learning_rate
    ) training_data;
    Printf.printf "Epoch %d complete\n%!" epoch
  done




