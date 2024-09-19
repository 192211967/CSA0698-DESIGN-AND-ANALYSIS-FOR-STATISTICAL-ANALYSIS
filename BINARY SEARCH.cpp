#include <stdio.h>
int binarySearch(int arr[], int n, int target)
 {
    int left = 0;
    int right = n - 1;
    while (left <= right)
	 {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main() {
    int arr[] = {2, 4, 7, 10, 14, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }
    return 0;
}
