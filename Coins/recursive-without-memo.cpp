#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int MOD = 1e9 + 7;

int arrSize, total;
vi moedas;

int countOfCombinations(int remainingTotal) {
    if (remainingTotal == 0) return 1;
    if (remainingTotal < 0) return 0;

    int totalWays = 0;
    for (int i = 0; i < moedas.size(); ++i) {
        totalWays = (totalWays + countOfCombinations(remainingTotal - moedas[i])) % MOD;
    }

    return totalWays;
}

int main() {
    cin >> arrSize >> total;
    moedas.assign(arrSize, 0);

    for (int i = 0; i < arrSize; ++i) {
        cin >> moedas[i];
    }

    int resultado = countOfCombinations(total);

    cout << resultado << endl;

    return 0;
}
