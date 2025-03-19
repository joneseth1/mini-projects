(* src/neural_network.ml *)

open Matrix

type layer = {
  weights : matrix;  
  biases : matrix;   
  activation_fn : (float -> float);  
}

type t = {
  layers : layer list;  
}

(** Create a neural network with a given number of neurons in each layer. *)
let create (layer_sizes : int list) activation_fn =
  let layers = 
    let rec create_layers sizes =
      match sizes with
      | input_size :: output_size :: rest ->
        let weights = Matrix.random input_size output_size in
        let biases = Matrix.random 1 output_size in
        let layer = { weights; biases; activation_fn } in
        layer :: create_layers (output_size :: rest)  
        | _ -> []  
    in
    create_layers layer_sizes
  in
  { layers }

(** Forward pass through the network. *)
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



