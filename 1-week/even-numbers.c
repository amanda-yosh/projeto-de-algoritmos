#include <stdio.h>

int numberOfPairs(int n, int s, int* v) {
    int numberOfPairs = 0;
    int hashTable[10001] = {0};

    for (int i = 0; i < n; i++) {
        int complement = s - v[i];

        if (complement >= 1 && complement <= 10000 && hashTable[complement] > 0) {
            numberOfPairs++;
        }

        hashTable[v[i]]++;
    }

    return numberOfPairs;
}

int main() {
    int n, s;
    scanf("%d %d", &n, &s);

    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("%d\n", numberOfPairs(n, s, v));
    return 0;
}
