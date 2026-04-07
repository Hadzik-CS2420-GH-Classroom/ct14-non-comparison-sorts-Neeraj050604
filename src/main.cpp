#include "NonComparisonSorts.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== CT14: Non-Comparison Sorts ===\n\n";

    // --- Counting Sort ---
    std::vector<int> data1 = { 4, 2, 7, 1, 9, 3, 5, 8, 2, 6 };
    print_vector(data1, "Before counting sort");
    counting_sort(data1);
    print_vector(data1, "After counting sort ");
    std::cout << "\n";

    // --- Bucket Sort ---
    std::vector<int> data2 = { 42, 15, 73, 28, 91, 5, 64, 37, 50, 19 };
    print_vector(data2, "Before bucket sort  ");
    bucket_sort(data2);
    print_vector(data2, "After bucket sort   ");
    std::cout << "\n";

    // --- Radix Sort ---
    std::vector<int> data3 = { 170, 45, 75, 90, 802, 24, 2, 66 };
    print_vector(data3, "Before radix sort   ");
    radix_sort(data3);
    print_vector(data3, "After radix sort    ");

    return 0;
}