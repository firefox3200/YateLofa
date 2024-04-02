#include <vector>
#include "sorting.hpp"
#include <iostream>
#include <fstream>



int main() {
    std::cout << "\nChecking MergeSort" << std::endl;
    testing_sort(sorting::MergeSort);
    std::cout << "\nChecking SelectionSort" << std::endl;
    testing_sort(sorting::SelectionSort);



    int K[10] = { 5600000, 215000, 23000, 1500, 114, 80, 50, 26, 16, 13 };
    int N[10] = { 100, 1000, 10000, 100000, 1000000, 1500000, 2000000, 4500000, 6500000, 8000000 };
    //merge sort benchmarks
    for (int i = 0; i < 10; i++) {
        out << N[i] << '\t' << "MergeSort" << '\t';

        double ms = benchmark(sorting::MergeSort, N[i], generateVectorRandom, K[i]);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::MergeSort, N[i], generateVector, K[i]*3);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::MergeSort, N[i], generateVectorReverse, K[i]*3);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::MergeSort, N[i], generateVectorFunny, K[i]);
        if (ms > 30000) {
            break;
        }
        out << ms << '\n';

    }

    int K[10] = { 2600000, 35000, 1050, 10, 3, 2, 2, 2, 1, 1 };
    int N[10] = { 100, 1000, 10000, 100000, 200000, 250000, 300000, 310000, 320000, 320100 };
    //selection sort benchmarks
    for (int i = 0; i < 10; i++) {
        out << N[i] << '\t' << "SelectionSort" << '\t';

        double ms = benchmark(sorting::SelectionSort, N[i], generateVectorRandom, K[i]);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::SelectionSort, N[i], generateVector, K[i]*1.5);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::SelectionSort, N[i], generateVectorReverse, K[i]*1.5);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::SelectionSort, N[i], generateVectorFunny, K[i]);
        if (ms > 30000) {
            break;
        }
        out << ms << '\n';
    }

    int K[10] = { 5600000, 215000, 23000, 1500, 114, 80, 50, 26, 16, 13 };
    int N[10] = { 100, 1000, 10000, 100000, 1000000, 1500000, 2000000, 4500000, 6500000, 8000000 };
    //std::sort benchmarks
    for (int i = 0; i < 10; i++) {
        out << N[i] << '\t' << "std::sort" << '\t';

        double ms = benchmark(sorting::DefaultSort, N[i], generateVectorRandom, K[i]);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::DefaultSort, N[i], generateVector, K[i]*2);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::DefaultSort, N[i], generateVectorReverse, K[i]*2);
        if (ms > 30000) {
            break;
        }
        out << ms << '\t';

        ms = benchmark(sorting::DefaultSort, N[i], generateVectorFunny, K[i]);
        if (ms > 30000) {
            break;
        }
        out << ms << '\n';
    }
    out.close();
}