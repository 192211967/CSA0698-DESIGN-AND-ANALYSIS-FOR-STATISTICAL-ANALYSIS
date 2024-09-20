#include <stdio.h>
#define MAX_ITEMS 100

void containerLoading(int items[], int n, int containerCapacity) {
    int containers = 1, currentCapacity = containerCapacity;

    for (int i = 0; i < n; i++) {
        if (items[i] <= currentCapacity) {
            currentCapacity -= items[i];
        } else {
            containers++;
            currentCapacity = containerCapacity - items[i];
        }
    }
    
    printf("Total containers needed: %d\n", containers);
}

int main() {
    int items[MAX_ITEMS] = {10, 20, 30, 40, 50}; // Example item sizes
    int n = 5;
    int containerCapacity = 60;

    containerLoading(items, n, containerCapacity);
    
    return 0;
}
