function fibonacci(n)
    if n <= 1
        return n
    else
        return fibonacci(n - 1) + fibonacci(n - 2)
    end
end

function generate_fibonacci_sequence(count)
    fibonacci_sequence = Int64[]
    for i in 0:count-1
        push!(fibonacci_sequence, fibonacci(i))
    end
    return fibonacci_sequence
end


count = 10
fibonacci_sequence = generate_fibonacci_sequence(count)

println("Fibonacci sequence up to $count numbers: ", fibonacci_sequence)
