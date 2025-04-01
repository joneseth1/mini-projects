(* src/matrix.ml *)

type matrix = float array array

(* Convert a 1D array to a 2D matrix *)
let of_array arr = arr

(* Create a [rows × cols] matrix initialized with a given value *)
let create rows cols init_val = 
    Array.make_matrix rows cols init_val

(* Generate a random [rows × cols] matrix with values in the range [-0.5, 0.5] *)
let random rows cols = 
    Array.init rows (fun _ -> Array.init cols (fun _ -> Random.float 1.0 -. 0.5))

(* Perform matrix multiplication (dot product). *)
let dot a b =
    let rows_a = Array.length a in
    let cols_a = Array.length a.(0) in  
    let cols_b = Array.length b.(0) in  
  
    if Array.length b != cols_a then
        failwith "Matrix dimensions do not match for multiplication";  (* throw error if dimensions don't match *)

    let result = Array.init rows_a (fun _ -> Array.make cols_b 0.0) in  (* initialize the result matrix *)
    for i = 0 to rows_a - 1 do
        for j = 0 to cols_b - 1 do
            for k = 0 to cols_a - 1 do  
                result.(i).(j) <- result.(i).(j) +. (a.(i).(k) *. b.(k).(j))
            done
        done
    done;

  result

(* Add a scalar to each element of the matrix *)
let add_scalar matrix scalar = 
    Array.map (fun row -> Array.map (fun x -> x +. scalar) row) matrix

(* Apply an activation function to each element of the matrix *)
let apply_activation activation_fn matrix = 
    Array.map (fun row -> Array.map activation_fn row) matrix

(* Matrix addition *)
let add_matrix m1 m2 =
    Array.map2 (fun row1 row2 -> Array.map2 ( +. ) row1 row2) m1 m2

(* Element-wise subtraction of two matrices *)
let sub (a: matrix) (b: matrix) : matrix =
    let rows = Array.length a in
    let cols = Array.length a.(0) in
    Array.init rows (fun i -> 
        Array.init cols (fun j -> 
        a.(i).(j) -. b.(i).(j)))

(* Element-wise (Hadamard) multiplication of two matrices *)   
let hadamard (a: matrix) (b: matrix) : matrix =
    let rows = Array.length a in
    let cols = Array.length a.(0) in
    Array.init rows (fun i -> 
        Array.init cols (fun j -> 
        a.(i).(j) *. b.(i).(j)))

(* Transpose a matrix *)        
let transpose (m : matrix) : matrix =
    let rows = Array.length m in
    let cols = Array.length m.(0) in
    Array.init cols (fun j -> Array.init rows (fun i -> m.(i).(j)))

(* Multiply a matrix by a scalar *)
let scalar_mul (s : float) (m : matrix) : matrix =
    Array.map (fun row -> Array.map (fun x -> s *. x) row) m
            

