#include <stdio.h>

int numberOfPairs(int n, int s, int* v) {
    int countNumberOfPairs = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            if (v[i] + v[j] == s) {
                countNumberOfPairs++;
            }
        }
    }

    return countNumberOfPairs;
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
