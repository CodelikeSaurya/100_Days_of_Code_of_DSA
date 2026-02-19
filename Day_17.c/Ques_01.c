# Read size of array
n = int(input("Enter number of elements: "))

# Read array elements
arr = list(map(int, input("Enter elements: ").split()))

# Initialize max and min
maximum = arr[0]
minimum = arr[0]

# Traverse the array
for i in range(1, n):
    if arr[i] > maximum:
        maximum = arr[i]
    if arr[i] < minimum:
        minimum = arr[i]

# Print results
print("Max:", maximum)
print("Min:", minimum)
