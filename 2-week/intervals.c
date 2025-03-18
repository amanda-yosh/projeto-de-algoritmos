#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para armazenar os pares (x, y)
typedef struct {
    int x, y;
} Par;

// Função de comparação para ordenar os pares pelo valor de x
int comparar(const void *a, const void *b) {
    return ((Par*)a)->x - ((Par*)b)->x;
}

int main() {
    int n;
    scanf("%d", &n);
    
    Par *v = (Par*) malloc(n * sizeof(Par));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].x, &v[i].y);
    }
    
    qsort(v, n, sizeof(Par), comparar);
    
    int intervals = 1;
    int lastBiggestY = v[0].y;

    for (int j = 1; j < n; j++) {
        if (v[j].x < v[j-1].y && v[j].y > lastBiggestY) {
            lastBiggestY = v[j].y;
        }
        
        if (v[j].x > v[j-1].y && v[j].x > lastBiggestY) {
            intervals++;
        }
    }

    printf("%d\n", intervals);

    free(v);
    
    return 0;
}
