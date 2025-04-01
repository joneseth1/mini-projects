(* src/matrix.mli *)



(* 2d array of floats *)
type matrix = float array array 

(* Creates a [n,m] matrix from a 2d array of floats *)
val of_array : float array array -> matrix

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

(* Matrix addition *)
val add_matrix : matrix -> matrix -> matrix

(* Element-wise subtraction of two matrices *)
val sub : matrix -> matrix -> matrix

(* Element-wise (Hadamard) multiplication of two matrices *)
val hadamard : matrix -> matrix -> matrix

(* Transpose a matrix *)
val transpose : matrix -> matrix

(* Multiply a matrix by a scalar *)
val scalar_mul : float -> matrix -> matrix








