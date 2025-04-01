#include <stdio.h>
#include <stdbool.h>

#define MAX_SUM 100000000

int set_size;
bool hashTable[MAX_SUM] = {false};
int uniqueCount = 0;

void backtracking(int v[], int k, int current_sum) {
    if (k == set_size) {
        if (current_sum > 0 && !hashTable[current_sum]) {
            hashTable[current_sum] = true;
            uniqueCount++;
        }
        return;
    }

    // Inclui o elemento atual na soma
    backtracking(v, k + 1, current_sum + v[k]);

    // Exclui o elemento atual da soma
    backtracking(v, k + 1, current_sum);
}

int main() {
    scanf("%d", &set_size);

    int set[set_size];
    for (int i = 0; i < set_size; i++) {
        scanf("%d", &set[i]);
    }

    backtracking(set, 0, 0);

    printf("%d\n", uniqueCount);
    return 0;
}
