#include <iostream>
#include <vector>
#include <cassert>
#include "balanced_lists.h"

void testPrefixSum() {
    std::vector<int> valid = {1, -1, 1, -1};
    assert(isWellBalanced(valid) == true);
    
    std::vector<int> invalid = {1, 1, -1, -1};
    assert(isWellBalanced(invalid) == false);

    std::cout << "Prefix sum tests passed.\n";
}

void testShuffle() {
    std::vector<int> arr = {1, 1, -1, -1};
    fisherYatesShuffle(arr);
    std::cout << "Shuffle test completed.\n";
}

int main() {
    testPrefixSum();
    testShuffle();
    std::cout << "All tests passed successfully.\n";
    return 0;
}
