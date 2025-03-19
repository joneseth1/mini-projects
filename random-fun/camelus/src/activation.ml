(* src/activation.ml *)

(* Sigmoid activation function *)
let sigmoid (x: float) : float = 1.0 /. (1.0 +. exp (-.x))

(* Apply a given activation function to a matrix *)
let apply_activation (activation_fn: float -> float) (matrix: Matrix.matrix) : Matrix.matrix =
  Array.map (fun row -> Array.map activation_fn row) matrix
