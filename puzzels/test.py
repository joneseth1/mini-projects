from itertools import product

def find_combinations(spots, target_sum):
    numbers = list(range(18))

    # Use a generator to iterate through combinations one at a time
    combinations = product(numbers, repeat=spots)

    # Filter and yield combinations that sum to the target_sum
    for combo in combinations:
        if sum(combo) == target_sum:
            yield combo

# Find and print the valid combinations for the first list with sum 3
print("Combinations for the first list with sum 3:")
for combo in find_combinations(7, 3):
    print(combo)

# Find and print the valid combinations for the second list with sum 9
print("\nCombinations for the second list with sum 9:")
for combo in find_combinations(7, 9):
    print(combo)

print("\nCombinations for the second list with sum 9:")
for combo in find_combinations(7, 9):
    print(combo)