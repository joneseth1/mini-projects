(* test/test_nn.ml *)


 
open Camelus.Neural_network
open Camelus.Activation



let test_xor () =
  let layer_sizes = [2; 3; 1] in  
  let activation_fn = sigmoid in  
  let nn = create layer_sizes activation_fn in 
  
  
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


let () = test_xor ()



