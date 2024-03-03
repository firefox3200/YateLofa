#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,2,4,3,5,6,7,8,9,0};
    int n = sizeof(arr) / sizeof(arr[0];
    
    // Check if the array is sorted or not
    bool isSorted = true;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            isSorted = false;
            break;
        }
    }
    
    // Check if the array has only one element or not
    if (n == 1) {
        cout << "The array contains only one element" << endl;
    } else if (!isSorted) {
        cout << "The array does not contain consecutive elements" << endl;
    } else {
        cout << "The array contains consecutive elements";
    }
    
    return 0;
}