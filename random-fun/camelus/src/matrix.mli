(* src/matrix.mli *)




type t = float array array 


(* Creates a [n,m] matrix *)
val create : int -> int -> float -> t

(* Creates a random [n,m] matrix *)
val random: int -> int -> t

(* dot product *)
val dot : t -> t-> t

(* Scalar and matrix add *)
val add_scalar : t -> float -> t

(* Apply activation *)
val apply_activation : t -> (float -> float) -> t





