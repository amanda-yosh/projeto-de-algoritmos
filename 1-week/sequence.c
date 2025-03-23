#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char query[30];
    int id;
    int interval;
    int aux;
} Query;

int comparar(const void *a, const void *b) {
    return ((Query *)a)->id - ((Query *)b)->id;
}

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mdcVet(int arr[], int tamanho) {
    int resultado = arr[0];

    for (int i = 1; i < tamanho; i++) {
        resultado = mdc(resultado, arr[i]);
        if (resultado == 1) {
            return 1;
        }
    }

    return resultado;
}

int main() {
    int numberOfQueries;
    scanf("%d", &numberOfQueries);

    Query queries[numberOfQueries];

    for (int i = 0; i < numberOfQueries; i++) {
        scanf(" %s %d %d", queries[i].query, &queries[i].id, &queries[i].interval);
        queries[i].aux = queries[i].interval;
    }

    qsort(queries, numberOfQueries, sizeof(Query), comparar);

    int printQuerysKTimes;
    scanf("%d", &printQuerysKTimes);

    int mdcValue = mdcVet((int *)queries, numberOfQueries);
    int step = mdcValue;

    int count = 0;

    while (count < printQuerysKTimes) {
        for (int x = 0; x < numberOfQueries; x++) {
            if (step == queries[x].aux) {
                printf("%d\n", queries[x].id);
                queries[x].aux += queries[x].interval;
                count++;

                if (count == printQuerysKTimes) {
                    break;
                }
            }
        }

        step += mdcValue;
    }

    return 0;
}
