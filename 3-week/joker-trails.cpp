#include <iostream>
#include <string>

#define SIZE 7

using namespace std;

bool marked[SIZE][SIZE];
string path;
int solution_count = 0;

int moves[4][2] = {
    {-1, 0}, // U - cima
    {1, 0},  // D - baixo
    {0, -1}, // L - esquerda
    {0, 1}   // R - direita
};

bool valid(int y, int x) {
    return y >= 0 && y < SIZE && x >= 0 && x < SIZE;
}

void backtracking(int y, int x, int k) {
    if (y == SIZE - 1 && x == 0) { // condicao de parada
        if (k == SIZE * SIZE - 1) {
            solution_count++;
        }
        return;
    }
    
    // Poda do topo e das laterais
    if ((y == 0 || y == SIZE - 1) && x > 0 && x < SIZE - 1 && !marked[y][x - 1] && !marked[y][x + 1]) return;
    if ((x == 0 || x == SIZE - 1) && y > 0 && y < SIZE - 1 && !marked[y - 1][x] && !marked[y + 1][x]) return;
    
    char move = path[k];
    
    for (int i = 0; i < 4; i++) {
        if (move != '?' && move != "UDLR"[i]) continue; // move inesperado
        
        int new_y = y + moves[i][0];
        int new_x = x + moves[i][1];
        
        if (valid(new_y, new_x) && !marked[new_y][new_x]) {
            marked[new_y][new_x] = true;
            backtracking(new_y, new_x, k + 1);
            marked[new_y][new_x] = false;
        }
    }
}

int main() {
    cin >> path;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            marked[i][j] = false;
        }
    }
    
    marked[0][0] = true;
    backtracking(0, 0, 0);
    
    cout << solution_count << endl;
    return 0;
}
