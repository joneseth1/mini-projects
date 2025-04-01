(* src/loss.ml *)



let mse predicted expected =
  let n = Array.length predicted in
  let sum = ref 0.0 in
  for i = 0 to n - 1 do
    let diff = predicted.(i) -. expected.(i) in
    sum := !sum +. (diff *. diff)
  done;
  !sum /. float_of_int n