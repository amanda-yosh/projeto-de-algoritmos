#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SUMS 1000 // Define um limite máximo para armazenar somas únicas

int main() {
    int set_size;
    scanf("%d", &set_size);

    int set[set_size];
    for (int i = 0; i < set_size; i++) {
        scanf("%d", &set[i]);
    }

    int totalSubsets = (int)pow(2, set_size) - 1; // Calcula 2^n - 1
    
    int uniqueSums[MAX_SUMS] = {0};
    int uniqueCount = 0;
    
    for (int mask = 1; mask < (1 << set_size); mask++) { // Percorre todas as combinações exceto o conjunto vazio
        int sum = 0;

        for (int i = 0; i < set_size; i++) {
            if (mask & (1 << i)) { // Verifica se o bit está ativado
                sum += set[i];
            }
        }
        
        // Verifica se a soma já foi registrada
        int isNew = 1;
        for (int i = 0; i < uniqueCount; i++) {
            if (uniqueSums[i] == sum) {
                isNew = 0;
                break;
            }
        }
        if (isNew) {
            uniqueSums[uniqueCount++] = sum;
        }
    }
    
    printf("%d\n", uniqueCount);
    return 0;
}
