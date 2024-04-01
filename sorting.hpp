#pragma once
#include <vector>
#include <chrono>
#include <functional>


namespace sorting {
    //Selection sort part
    void SelectionSort(std::vector<int>& values);
    std::vector<int>::iterator FindMin(std::vector<int>::iterator startPos, std::vector<int>::iterator endPos);

    //Merge sort part
    void _MergeSortImpl(std::vector<int>& values, std::vector<int>& buffer, int left, int right);
    void MergeSort(std::vector<int>& values);

    // std::sort realization
    void DefaultSort(std::vector<int>& values);
}

void print(std::vector<int> const& input);
std::vector<int> generateVectorRandom(int size);
std::vector<int> generateVector(int size);
std::vector<int> generateVectorReverse(int size);
std::vector<int> generateVectorFunny(int size);
double benchmark(std::function<void(std::vector<int>& values)> S, int N, std::function<std::vector<int>(int)> G, int K);
void testing_sort(std::function<void(std::vector<int>& values)> S);