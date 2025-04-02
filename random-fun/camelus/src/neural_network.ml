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

(* Create a neural network with a given number of neurons in each layer *)
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


(* Forward pass through the network *)
let forward (network : t) (input : matrix) : matrix =
  let rec forward_layers layers input_matrix =
    match layers with
    | [] -> input_matrix
    | layer :: rest ->
      (* Print input matrix dimensions *)
      Printf.printf "Input to layer: %d x %d\n" (Array.length input_matrix) (Array.length input_matrix.(0));

      let weighted_input = Matrix.dot input_matrix layer.weights in
      Printf.printf "After dot product: %d x %d\n" (Array.length weighted_input) (Array.length weighted_input.(0));

      let output_with_bias = Matrix.add_scalar weighted_input 1.0 in
      Printf.printf "Before activation: %d x %d\n" (Array.length output_with_bias) (Array.length output_with_bias.(0));

      let activated_output = Matrix.apply_activation layer.activation_fn output_with_bias in
      (* Print the size after activation *)
      Printf.printf "After activation: %d x %d\n" (Array.length activated_output) (Array.length activated_output.(0));

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


let backward_propagate nn activations expected_output learning_rate =
  let num_layers = List.length nn.layers in

  (* Calculate the error at the output layer *)
  let errors = ref [Matrix.sub (List.nth activations num_layers) expected_output] in

  (* Backpropagate errors through the layers *)
  List.iteri (fun i _ ->
    let index = num_layers - i - 1 in
    if index > 0 then
      (* Get the activation from the previous layer *)
      let prev_activation = List.nth activations (index - 1) in
      Printf.printf "Prev activation size: %d x %d\n" (Array.length prev_activation) (Array.length prev_activation.(0));

      (* Compute delta for this layer (error * derivative of activation function) *)
      let delta = Matrix.hadamard (List.hd !errors) (Matrix.apply_activation Activation.sigmoid_derivative prev_activation) in
      errors := delta :: !errors;
      Printf.printf "Delta size: %d x %d\n" (Array.length delta) (Array.length delta.(0))
  ) (List.rev nn.layers);

  (* Update weights and biases for each layer *)
  List.iteri (fun i layer ->
    let delta = List.nth !errors i in
    let prev_activation = List.nth activations i in
    Printf.printf "Updating layer %d with prev activation size: %d x %d and delta size: %d x %d\n"
      i (Array.length prev_activation) (Array.length prev_activation.(0)) (Array.length delta) (Array.length delta.(0));

    if (Array.length prev_activation) = (Array.length delta) then
      let prev_activation_T = Matrix.transpose prev_activation in

      (* Update weights: prev_activation_T (N x 1) dot delta (1 x M) => weight_update (N x M) *)
      let weight_update = Matrix.dot prev_activation_T delta in
      Printf.printf "Weight update size: %d x %d\n" (Array.length weight_update) (Array.length weight_update.(0));

      (* Update weights and biases using the learning rate *)
      layer.weights <- Matrix.sub layer.weights (Matrix.scalar_mul learning_rate weight_update);
      layer.biases <- Matrix.sub layer.biases (Matrix.scalar_mul learning_rate delta)
    else
      Printf.printf "Skipping weight update due to dimension mismatch: prev_activation size (%d x %d) and delta size (%d x %d)\n"
        (Array.length prev_activation) (Array.length prev_activation.(0)) (Array.length delta) (Array.length delta.(0));
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




