(* Define basic arithmetic functions *)
let add x y = x + y
let subtract x y = x - y
let multiply x y = x * y
let divide x y = 
  if y = 0 then failwith "Division by zero" 
  else x / y

(* Function to read an integer from the user *)
let read_int prompt =
  print_endline prompt;
  int_of_string (read_line ())

(* Main function *)
let () =
  print_endline "Simple Calculator";
  let a = read_int "Enter the first number:" in
  let b = read_int "Enter the second number:" in
  print_endline "Choose an operation: +, -, *, /";
  let op = read_line () in
  let result = match op with
    | "+" -> add a b
    | "-" -> subtract a b
    | "*" -> multiply a b
    | "/" -> divide a b
    | _ -> failwith "Unknown operation"
  in
  Printf.printf "The result is: %d\n" result

