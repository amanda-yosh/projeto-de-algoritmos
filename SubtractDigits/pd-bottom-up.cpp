#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getBiggerDigit(int num) {
    int bigger = 0;

    while (num > 0) {
        int digit = num % 10;
        bigger = max(bigger, digit);
        num /= 10;
    }

    return bigger;
}

int subtractDigitsIterative(int num) {
    vector<int> dp(num + 1, 0); // dp[i] = número mínimo de passos para chegar a 0

    for (int i = 1; i <= num; ++i) {
        int maxDigit = getBiggerDigit(i);
        dp[i] = 1 + dp[i - maxDigit];
    }

    return dp[num];
}

int main() {
    int num;
    cin >> num;

    int result = subtractDigitsIterative(num);
    cout << result << endl;

    return 0;
}

// Divisão em Subproblemas -> calculamos dp[i] com base em dp[i - maxDigit]
// Bottom-up é uma PD Iterativa, não utiliza recursão e usa um vetor dp e vai construindo de 0 até n.
