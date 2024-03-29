let arr = [1, 2, 4, 3, 5, 6, 7, 8, 9, 0];
let n = arr.length;

// Function to check if array has only unique elements
function hasUniqueElements(array) {
    return new Set(array).size === array.length;
}

// Check if the array is sorted or not
let isSorted = arr.every((val, index) => index === 0 || val >= arr[index - 1]);

// Check if the array has only one element or not
if (n === 1) {
    console.log("The array contains only one element");
} else if (!isSorted) {
    console.log("The array is not sorted");
} else {
    console.log("The array is sorted");
}

// Check if the array has only unique elements or not
if (hasUniqueElements(arr)) {
    console.log("The array contains only unique elements");
} else {
    console.log("The array contains duplicate elements");
}
