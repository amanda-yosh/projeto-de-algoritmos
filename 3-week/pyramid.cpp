#include <iostream>
#include <unordered_set>
using namespace std;

int set_size;
unordered_set<int> uniqueSums;

void backtracking(int v[], int k, int current_sum) {
    if (k == set_size) {
        if (current_sum > 0) {
            uniqueSums.insert(current_sum);
        }
        return;
    }

    // Inclui o elemento atual na soma
    backtracking(v, k + 1, current_sum + v[k]);

    // Exclui o elemento atual da soma
    backtracking(v, k + 1, current_sum);
}

int main() {
    cin >> set_size;

    int set[set_size];
    for (int i = 0; i < set_size; i++) {
        cin >> set[i];
    }

    backtracking(set, 0, 0);

    cout << uniqueSums.size() << endl;
    return 0;
}
