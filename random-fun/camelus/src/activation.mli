(* src/activation.mli *)

(* Sigmoid activation function: takes a float and returns a float *)
val sigmoid : float -> float

(* Apply a given activation function to a matrix *)
val apply_activation : (float -> float) -> Matrix.matrix -> Matrix.matrix
