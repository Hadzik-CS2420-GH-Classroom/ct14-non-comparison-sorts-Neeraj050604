#include "NonComparisonSorts.h"
#include <iostream>
#include <algorithm>

// ---------------------------------------------------------------------------
// Counting Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #1 -- Steps 1a, 1b, 1c (Count Phase)
// ? SEE DIAGRAM: cpp_diagrams.md #2 -- Step 2 (Placement Phase)
//
void counting_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;

    int max_val = *std::max_element(data.begin(), data.end());

    std::vector<int> count(max_val + 1, 0);

    // count
    for (int num : data) {
        count[num]++;
    }

    // overwrite
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            data[index++] = i;
            count[i]--;
        }
    }
}

// ---------------------------------------------------------------------------
// Bucket Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #3 -- Steps 1a, 1b (Distribution Phase)
// ? SEE DIAGRAM: cpp_diagrams.md #4 -- Steps 2-3 (Sort + Concatenate)
//
void bucket_sort(std::vector<int>& data, int num_buckets) {
    if (data.size() <= 1) return;

    int max_val = *std::max_element(data.begin(), data.end());

    std::vector<std::vector<int>> buckets(num_buckets);

    // distribute
    for (int num : data) {
        int index = num * num_buckets / (max_val + 1);
        buckets[index].push_back(num);
    }

    // sort buckets
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    // merge
    int i = 0;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            data[i++] = num;
        }
    }
}
// ---------------------------------------------------------------------------
// Radix Sort (LSD)
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #5 -- Step 0 + Pass 1 Detail
// ? SEE DIAGRAM: cpp_diagrams.md #6 -- Passes 2-3 (Stability in Action)
//
void radix_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;

    int max_val = *std::max_element(data.begin(), data.end());

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        std::vector<int> output(data.size());
        std::vector<int> count(10, 0);

        // count digits
        for (int i = 0; i < data.size(); i++) {
            int digit = (data[i] / exp) % 10;
            count[digit]++;
        }

        // prefix sum
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // build output (RIGHT TO LEFT → important!)
        for (int i = data.size() - 1; i >= 0; i--) {
            int digit = (data[i] / exp) % 10;
            output[count[digit] - 1] = data[i];
            count[digit]--;
        }

        // copy back
        data = output;
    }
}


// ---------------------------------------------------------------------------
// Utility
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) std::cout << label << ": ";
    std::cout << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i + 1 < data.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}