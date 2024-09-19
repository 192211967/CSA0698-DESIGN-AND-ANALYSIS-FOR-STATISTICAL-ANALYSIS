#include <stdio.h>

typedef struct {
    int weight;
    int value;
} Item;

void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float ratio1 = (float)items[i].value / items[i].weight;
            float ratio2 = (float)items[j].value / items[j].weight;
            if (ratio1 < ratio2) {
                // Swap items[i] and items[j]
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float knapsack(Item items[], int n, int capacity) {
    sortItems(items, n);

    int currentWeight = 0;
    float totalValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float maxValue = knapsack(items, n, capacity);

    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
