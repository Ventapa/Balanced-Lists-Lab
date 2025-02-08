#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Fisher-Yates Shuffle
void fisherYatesShuffle(vector<int>& arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

// Check if a sequence is a well-balanced list
bool isWellBalanced(const vector<int>& arr) {
    int prefixSum = 0;
    for (int num : arr) {
        prefixSum += num;
        if (prefixSum < 0) return false;  // Must remain non-negative
    }
    return (prefixSum == 0); // Ensure full balance
}

// Run the experiment and compute the proportion of well-balanced lists
void runExperiment(int n, int trials) {
    srand(time(0));  // Seed for randomness
    int validCount = 0;
    
    for (int i = 0; i < trials; ++i) {
        vector<int> arr(2 * n, -1);
        fill(arr.begin(), arr.begin() + n, 1); // Fill first n elements with 1
        fisherYatesShuffle(arr);
        if (isWellBalanced(arr)) {
            ++validCount;
        }
    }
    
    cout << "Total Trials: " << trials << endl;
    cout << "Well-Balanced Lists: " << validCount << endl;
    cout << "Proportion: " << static_cast<double>(validCount) / trials << endl;
}

int main() {
    int n = 4;  // Example size (adjust as needed)
    int trials = 10000;  // Number of random trials
    runExperiment(n, trials);
    return 0;
}
