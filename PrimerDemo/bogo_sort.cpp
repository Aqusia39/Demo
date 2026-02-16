#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // For std::is_sorted, std::shuffle

// Function to check if the vector is sorted
bool isSorted(const std::vector<int>& arr) {
    return std::is_sorted(arr.begin(), arr.end());
}

// Function to shuffle the vector
void shuffle(std::vector<int>& arr) {
    // Use a random device to seed the random number generator
    std::random_device rd;
    // Use the default random engine
    std::default_random_engine rng(rd());
    std::shuffle(arr.begin(), arr.end(), rng);
}

// Bogo Sort function
void bogoSort(std::vector<int>& arr) {
    while (!isSorted(arr)) {
        shuffle(arr);
    }
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6};

    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorting array using Bogo Sort..." << std::endl;
    bogoSort(arr);

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
