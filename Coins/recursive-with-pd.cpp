#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 1000005
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int arrSize, total;
int MEMO[MAX];
vi moedas;

int countOfCombinations(int remainingTotal) {
    if (remainingTotal == 0) return 1;
    if (remainingTotal < 0) return 0;
    if (MEMO[remainingTotal] != -1) return MEMO[remainingTotal];

    int totalWays = 0;
    for (int i = 0; i < moedas.size(); ++i) {
        totalWays = (totalWays + countOfCombinations(remainingTotal - moedas[i])) % MOD;
    }

    return MEMO[remainingTotal] = totalWays;
}

int main() {
    cin >> arrSize >> total;
    moedas.assign(arrSize, 0);

    for (int i = 0; i < arrSize; ++i) {
        cin >> moedas[i];
    }

    memset(MEMO, -1, sizeof(MEMO));
    cout << countOfCombinations(total) << endl;

    return 0;
}
