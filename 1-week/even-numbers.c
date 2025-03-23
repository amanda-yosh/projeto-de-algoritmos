#include <stdio.h>

int main() {
    int n, s;
    int currentElement = 0;
    int countNumberOfPairs = 0;
    int hashTable[32001] = {0};

    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++) {
        scanf("%d", &currentElement);
        int complement = s - currentElement;

        countNumberOfPairs += (complement >= 1 && complement <= 32001) ? hashTable[complement] : 0;
        hashTable[currentElement]++;
    }

    printf("%d\n", countNumberOfPairs);
    return 0;
}
