(* src/neural_network.mli *)

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
val create_nn : int list -> (float -> float) -> t

(* Forward pass through the network *)
val forward : t -> matrix -> matrix


val train : 
  t -> (* Neural network *)
  (Matrix.matrix * Matrix.matrix) list -> (* Training data: list of (input, expected output) *)
  float -> 
  int -> 
  unit
