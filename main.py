arr = [1, 2, 4, 3, 5, 6, 7, 8, 9, 0]
n = len(arr)

# Check if the array is sorted or not
isSorted = all(arr[i] <= arr[i+1] for i in range(n-1)

# Check if the array has only one element or not
if n == 1:
    print("The array contains only one element")
elif not isSorted:
    print("The array does not contain consecutive elements")
else:
    print("The array contains consecutive elements")
