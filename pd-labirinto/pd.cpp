#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

const int MOD = 1e9 + 7;

int N;
vs grid;
vvi MEMO;

// int solveREC(int i, int j) {
//     if (i < 0 || j < 0) return 0;
//     if (grid[i][j] == '*') return 0;
//     if (i == 0 && j == 0) return 1;

//     return (solveREC(i-1, j) + solveREC(i, j-1)) % MOD;
// }

int solveRECPD(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == '*') return 0;
    if (i == 0 && j == 0) return 1;
    if (MEMO[i][j] != -1) return MEMO[i][j];

    MEMO[i][j] = (solveRECPD(i-1, j) + solveRECPD(i, j-1)) % MOD;
    return MEMO[i][j];
}

int main(int argc, char const *argv[]) {
    cin >> N;
    grid.assign(N, "");

    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    // cout << solveREC(N-1, N-1) << endl;
	MEMO.assign(N, vi(N, -1));
    cout << solveRECPD(N-1, N-1) << endl;

    return 0;
}
