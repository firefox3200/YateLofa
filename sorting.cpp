#include <vector>
#include <limits>
#include <functional>
#include <iostream>
#include <chrono>
#include <algorithm>


namespace sorting {
    void MergeSortImpl(std::vector<int> &values, std::vector<int> &buffer, int left, int right) {
        if (left < right) {
            int m = (left + right) / 2;
            MergeSortImpl(values, buffer, left, m);
            MergeSortImpl(values, buffer, m + 1, right);

            int k = left;
            for (int i = left, j = m + 1; i <= m || j <= right;) {
                if (j > right || (i <= m && values[i] < values[j])) {
                    buffer[k] = values[i];
                    ++i;
                } else {
                    buffer[k] = values[j];
                    ++j;
                }
                ++k;
            }
            for (int i = left; i <= right; ++i) {
                values[i] = buffer[i];
            }
        }
    }

    void MergeSort(std::vector<int> &values) {
        if (!values.empty()) {
            std::vector<int> buffer(values.size());
            MergeSortImpl(values, buffer, 0, values.size() - 1);
        }
    }

// Find min elem in vector
    std::vector<int>::iterator FindMin(std::vector<int>::iterator startPos, std::vector<int>::iterator endPos) {
        int minVal = std::numeric_limits<int>::max();
        std::vector<int>::iterator minPos;

        while (startPos != endPos) {
            if (*startPos < minVal) {
                minPos = startPos;
                minVal = *startPos;
            }
            startPos++;
        }
        return minPos;
    }

//From min to max by elem
    void SelectionSort(std::vector<int> &values) {
        for (auto i = values.begin(); i != values.end(); ++i) {
            auto minVal = FindMin(i, values.end());
            std::swap(*i, *minVal);
        }
    }

    void DefaultSort(std::vector<int> &values) {
        std::sort(values.begin(), values.end());
    }
}

// Print vector
void print(std::vector<int> const& input) {
    for (int i : input) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

//Generate pseudo-random vector<int> with seed = 10. From 0 to N/5. Len = n
std::vector<int> generateVectorRandom(int size) {
    std::vector<int> result;
    result.reserve(size);
    srand(10);
    for (int i = 0; i < size; i++) {
        result.push_back(rand() % ((size / 5) + 1));
    }
    return result;
}

// Generate vector in normal order
std::vector<int> generateVector(int size) {
    std::vector<int> result;
    result.reserve(size);
    for (int i = 1; i <= size; i++) {
        result.push_back(i);
    }
    return result;
}

// Generate vector in reverse order
std::vector<int> generateVectorReverse(int size) {
    std::vector<int> result;
    result.reserve(size);
    for (int i = size; i > 0; i--) {
        result.push_back(i);
    }
    return result;
}

// Generate vector from 1 to size, which size/10 count replace with random position
std::vector<int> generateVectorFunny(int size) {
    auto result = generateVector(size);
    srand(10);
    for (int i = 0; i < size / 10; i++) {
        int pos1 = rand() % size;
        int pos2 = rand() % size;
        std::swap(result[pos1], result[pos2]);
    }
    return result;
}

// Benchmark. Return average time for function in ms.
double benchmark(std::function<void(std::vector<int>& values)> S, int N, std::function<std::vector<int>(int)> G, int K) {
    using Time = std::chrono::time_point<std::chrono::high_resolution_clock>;
    using Diff = std::chrono::milliseconds;

    Time time_start = std::chrono::high_resolution_clock::now();
    std::vector<int> unsort_values = G(N);
    for (int i = 0; i < K; i++) {
        std::vector<int> values;
        values.insert(values.begin(), unsort_values.begin(), unsort_values.end());
        S(values);
        
        if (i == 0) {
            Time t = std::chrono::high_resolution_clock::now();
            if (std::chrono::duration_cast<Diff>(t - time_start).count() > 30000) return std::chrono::duration_cast<Diff>(t - time_start).count();
        }
    }
    Time time_end = std::chrono::high_resolution_clock::now();
    Diff diff = std::chrono::duration_cast<Diff>(time_end - time_start);
    std::cout << "Count ints: " << N << " Count repeats: " << K << " || " << "All time: " << diff.count() << " ms. Average time: " << diff.count() / (K + 0.0) << " ms" << std::endl;
    return diff.count() / (K + 0.0);
}

void testing_sort(std::function<void(std::vector<int>& values)> S) {
    //tetsting working
    std::vector<int> testArray = generateVector(10);
    std::vector<int> testArray1 = generateVectorReverse(10);
    std::vector<int> testArray2 = generateVectorRandom(10);
    std::vector<int> testArray3 = generateVectorFunny(10);

    std::cout << "Initial values: " << std::endl;
    print(testArray);
    print(testArray1);
    print(testArray2);
    print(testArray3);

    S(testArray);
    S(testArray1);
    S(testArray2);
    S(testArray3);

    std::cout << "Sorted values: " << std::endl;
    print(testArray);
    print(testArray1);
    print(testArray2);
    print(testArray3);

    //correctness check
    testArray = generateVector(100000);
    testArray1 = generateVectorReverse(100000);
    testArray2 = generateVectorRandom(100000);
    testArray3 = generateVectorFunny(100000);

    //copy arrays
    std::vector<int> testArrayCopy = testArray;
    std::vector<int> testArray1Copy = testArray1;
    std::vector<int> testArray2Copy = testArray2;
    std::vector<int> testArray3Copy = testArray3;

    S(testArray);
    S(testArray1);
    S(testArray2);
    S(testArray3);

    std::sort(testArrayCopy.begin(), testArrayCopy.end());
    std::sort(testArray1Copy.begin(), testArray1Copy.end());
    std::sort(testArray2Copy.begin(), testArray2Copy.end());
    std::sort(testArray3Copy.begin(), testArray3Copy.end());

    if (testArray != testArrayCopy) {
        std::cout << "Error in testArray" << std::endl;
    }
    if (testArray1 != testArray1Copy) {
        std::cout << "Error in testArray1" << std::endl;
    }
    if (testArray2 != testArray2Copy) {
        std::cout << "Error in testArray2" << std::endl;
    }
    if (testArray3 != testArray3Copy) {
        std::cout << "Error in testArray3" << std::endl;
    }

    std::cout << "Correctness check completed" << std::endl;
}

