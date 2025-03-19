(* src/matrix.mli *)



(* 2d array of floats *)
type matrix = float array array 


(* Creates a [n,m] matrix *)
val create : int -> int -> float -> matrix

(* Creates a random [n,m] matrix *)
val random: int -> int -> matrix

(* dot product *)
val dot : matrix -> matrix -> matrix

(* Scalar and matrix add *)
val add_scalar : matrix -> float -> matrix

(* Apply activation *)
val apply_activation : (float -> float) -> matrix -> matrix





