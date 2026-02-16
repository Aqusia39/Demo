#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

// Function to perform binary search
// Returns the index of the target if found, otherwise -1
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid to prevent overflow

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // Target not found in the array
    return -1;
}

int main() {
    std::vector<int> numbers = {5, 1, 9, 3, 7, 2, 8, 4, 6};
    int target = 7;

    // Binary search requires a sorted array
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int result = binarySearch(numbers, target);

    if (result != -1) {
        std::cout << "Target " << target << " found at index: " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    // Test with a target not in the array
    target = 10;
    result = binarySearch(numbers, target);
    if (result != -1) {
        std::cout << "Target " << target << " found at index: " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}
