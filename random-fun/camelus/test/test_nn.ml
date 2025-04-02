(* test/test_nn.ml *)


 
open Camelus.Neural_network
open Camelus.Activation
open Camelus.Matrix



let test_xor () =
  let layer_sizes = [2; 3; 1] in  
  let activation_fn = sigmoid in  (* Use sigmoid activation function *)
  let nn = create_nn layer_sizes activation_fn in
  
  let xor_data = [
    ([| 0.0; 0.0 |], [| 0.0 |]);
    ([| 0.0; 1.0 |], [| 1.0 |]);
    ([| 1.0; 0.0 |], [| 1.0 |]);
    ([| 1.0; 1.0 |], [| 0.0 |])
  ] in
  
  List.iter (fun (input, expected_output) ->

    let output_matrix = forward nn [| input |] in
    let output_value = output_matrix.(0).(0) in

    Printf.printf "Input: [%f, %f] -> Output: [%f] (Expected: [%f])\n"
      input.(0) input.(1) output_value expected_output.(0)

  ) xor_data


let () =
  let layer_sizes = [2; 3; 1] in  (* Correct layer sizes *)
  let activation_fn = sigmoid in  (* Use the sigmoid activation function *)
  let nn = create_nn layer_sizes activation_fn in
  let xor_data = [
    (of_array [| [| 0.0; 0.0 |] |], of_array [| [| 0.0 |] |]);
    (of_array [| [| 0.0; 1.0 |] |], of_array [| [| 1.0 |] |]);
    (of_array [| [| 1.0; 0.0 |] |], of_array [| [| 1.0 |] |]);
    (of_array [| [| 1.0; 1.0 |] |], of_array [| [| 0.0 |] |])
  ] in
  (* Print training data dimensions *)
  List.iter (fun (x, y) -> 
    Printf.printf "Training data input shape: %d x %d, output shape: %d x %d\n"
      (Array.length x) (Array.length x.(0)) (Array.length y) (Array.length y.(0));
  ) xor_data;

  train nn xor_data 0.1 1000

let () = test_xor ()


