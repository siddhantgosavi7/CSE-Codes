#include <stdio.h>

struct Item {

    int id;

    float weight;

    float value;

    float ratio;

};

void sortItems(struct Item items[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (items[j].ratio < items[j + 1].ratio) {

                struct Item temp = items[j];

                items[j] = items[j + 1];

                items[j + 1] = temp;

            }

        }

    }

}

void fractionalKnapsack(struct Item items[], int n, float W) {

    for (int i = 0; i < n; i++) {

        items[i].ratio = items[i].value / items[i].weight;

    }

    sortItems(items, n);

    float currentCapacity = W;

    float totalValue = 0.0;

    printf("Selected Items:\n");

    for (int i = 0; i < n; i++) {

        if (items[i].weight <= currentCapacity) {

            currentCapacity -= items[i].weight;

            totalValue += items[i].value;

            printf("Item %d: 100%% taken (Weight: %.2f, Value: %.2f)\n",

                   items[i].id, items[i].weight, items[i].value);

        } else {

            float fraction = currentCapacity / items[i].weight;

            totalValue += items[i].value * fraction;

            printf("Item %d: %.2f%% taken (Weight: %.2f, Value: %.2f)\n",

                   items[i].id, fraction * 100, currentCapacity, items[i].value * fraction);

            currentCapacity = 0;

            break;

        }

    }

    printf("\nMaximum Total Value in Knapsack = %.2f\n", totalValue);

}

int main() {

    struct Item items[] = {

        {1, 10, 60, 0},

        {2, 20, 100, 0},

        {3, 30, 120, 0}

    };

    int n = 3;

    float capacity = 50.0;

    fractionalKnapsack(items, n, capacity);

    return 0;

}
