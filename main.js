let arr = [1, 2, 4, 3, 5, 6, 7, 8, 9, 0];
let n = arr.length;

// Check if the array is sorted or not
let isSorted = true;
for (let i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
        isSorted = false;
        break;
    }
}

// Check if the array has only one element or not
if (n === 1) {
    console.log("The array contains only one element");
} else if (!isSorted) {
    console.log("The array does not contain consecutive elements");
} else {
    console.log("The array contains consecutive elements");
}
