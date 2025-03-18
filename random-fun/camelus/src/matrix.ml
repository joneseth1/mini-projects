(* src/matrix.ml *)



type t = float array array 

let create rows cols init_val = 
    Array.make_matrix rows cols init_val

let random rows cols = 
    Array.init rows (fun _ -> Array.init cols (fun _ -> Random.float 1.0 -. 0.5))

let dot a b = 
    let rows_a = Array.length a in 
    let cols_b = Array.length b.(0) in 
    let result = create rows_a cols_b 0.0 in 
    for i = 0 to rows_a - 1 do 
        for j = 0 to cols_b - 1 do 
            for k = 0 to Array.length b - 1 do 
                result.(i).(j) <- result.(i).(j) +. (a.(i).(k) *. b.(k).(j))
            done 
        done
    done;
    result

let add_scalar matrix scalar = 
    Array.map (fun row -> Array.map (fun x -> x +. scalar) row) matrix

let apply_activation matrix activation_fn = 
    Array.map (fun row -> Array.map activation_fn row) matrix

