(* test/test_nn.ml *)



open Camelus.Matrix 

let print_matrix m = 
    Array.iter (fun row -> 
        Array.iter (fun x -> Printf.printf "%f " x) row;
        print_newline ()
    ) m;
    print_newline ()


let test_create () =
    let m = create 2 3 0.0 in 
    print_endline "Testing create: ";
    print_matrix m


let test_random () = 
    let m = random 2 3 in 
    print_endline "Testing random matrix: ";
    print_matrix m


let test_dot () = 
    let a = [| [| 1.0; 2.0 |]; [| 3.0; 4.0 |] |] in 
    let b = [| [| 5.0; 6.0 |]; [| 7.0; 8.0 |] |] in 
    let result = dot a b in 
    print_endline "testing dot product: ";
    print_matrix result


let test_add_scalar () = 
    let m = [| [| 1.0; 2.0 |]; [| 3.0; 4.0 |] |] in 
    let result = add_scalar m 1.0 in 
    print_endline "Testing add scalar: ";
    print_matrix result


let () = 
    test_create ();
    test_random ();
    test_dot (); 
    test_add_scalar ();
    print_endline "All tests finished!" 
