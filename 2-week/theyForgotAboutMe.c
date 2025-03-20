#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    int months = 12;
    int growPerMonth[months];
    for (int i = 0; i < months; i++) {
        scanf("%d", &growPerMonth[i]);
    }

    int hashTable[12] = {0};
    for (int j = 0; j < months; j++) {
        hashTable[growPerMonth[j]]++;
    }

    // sort hashTable
    for (int i = 0; i < months - 1; i++) {
        for (int j = i + 1; j < months; j++) {
            if (growPerMonth[i] < growPerMonth[j]) {
                int temp = growPerMonth[i];
                growPerMonth[i] = growPerMonth[j];
                growPerMonth[j] = temp;
            }
        }
    }
    
    int sum = 0, count = 0;
    for (int i = 0; i < months && sum < k; i++) {
        if (growPerMonth[i] > 0) {
            sum += growPerMonth[i];
            count++;
        }
    }

    if (sum >= k) {
        printf("%d\n", count);
    } else {
        printf("%d\n", -1);
    }
    
    return 0;
}
