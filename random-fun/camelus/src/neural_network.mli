(* src/neural_network.mli *)

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
val create : int list -> (float -> float) -> t

(** Forward pass through the network. *)
val forward : t -> matrix -> matrix
