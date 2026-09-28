#include <stdio.h>


int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}


int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }

    return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    
    int nums[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 23;

    int idx = binarySearch(nums, n, target);

    if (idx != -1) {
        printf("Found %d at index %d\n", target, idx);
    } else {
        printf("%d is not in the array\n", target);
    }

    return 0;
}
