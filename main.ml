let rec list_init l n =
    if n = 0 then l else list_init ((n - 1) :: l) (n - 1)

let solve () =
    let n = read_int () in
    if n = 1 then (print_int 3; print_newline ())
    else
    (let minp = List.fold_left (fun minp i ->
        if minp = 0 && (n land (1 lsl i)) != 0 then (1 lsl i) else minp)
        0 (list_init [] 31) in
    let ans = if n = minp then minp + 1 else minp in
    print_int ans; print_newline ())


let () = 
let t = read_int () in
for i = 1 to t do
    solve ()
done