package main

import "fmt"

func main() {
    arr := []int{1, 2, 4, 3, 5, 6, 7, 8, 9, 0}
    n := len(arr)

    // Check if the array is sorted or not
    isSorted := true
    for i := 0; i < n-1; i++ {
        if arr[i] > arr[i+1] {
            isSorted = false
            break
        }
    }

    // Check if the array has only one element or not
    if n == 1 {
        fmt.Println("The array contains only one element")
    } else if !isSorted {
        fmt.Println("The array does not contain consecutive elements")
    } else {
        fmt.Println("The array contains consecutive elements")
    }
}
