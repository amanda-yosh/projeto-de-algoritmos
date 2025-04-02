#include <iostream>

#define SIZE 7

using namespace std;

bool marked[SIZE][SIZE];

char moves[8][2] = {
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2}
};

bool valid(char v) {
    return (v >= 0) && (v < SIZE);
}

void backtracking(char lin, char col, char k) {
    char new_lin, new_col;

    if (k == SIZE * SIZE - 1) {
        cout << "There exists a path!" << endl;
    } else {
        for (int i = 0; i < 8; i++) {
            new_col = col + moves[i][0];
            new_lin = lin + moves[i][1];

            if (valid(new_lin) && valid(new_col) && !marked[new_lin][new_col]) {
                marked[new_lin][new_col] = true;
                backtracking(new_lin, new_col, k+1);
                marked[new_lin][new_col] = false;
            }
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            marked[i][j] = false;
        }
    }

    marked[0][0] = true;
    backtracking(0, 0, 0);

    return 0;
}
