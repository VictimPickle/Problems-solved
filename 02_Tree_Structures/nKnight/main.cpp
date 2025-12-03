#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> board;

bool is_valid_knight(int x, int y) {
    static int knight_moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (auto move : knight_moves) {
        int nx = x + move[0], ny = y + move[1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 1) {
            return false;
        }
    }
    return true;
}

bool is_valid_bishop(int x, int y) {
    static int bishop_moves[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (auto move : bishop_moves) {
        int nx = x, ny = y;
        while (true) {
            nx += move[0];
            ny += move[1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
            if (board[nx][ny] == 2) return false;
        }
    }
    return true;
}

int count_arrangements(int idx) {
    if (idx == n * n) {
        return 1;
    }

    int x = idx / n, y = idx % n;
    int total = 0;

    if (board[x][y] == 0) {
        if (is_valid_knight(x, y)) {
            board[x][y] = 1;
            total += count_arrangements(idx + 1);
            board[x][y] = 0;
        }

        if (is_valid_bishop(x, y)) {
            board[x][y] = 2;
            total += count_arrangements(idx + 1);
            board[x][y] = 0;
        }
    }

    total += count_arrangements(idx + 1);
    return total;
}

int main() {
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n, 0));

    int result = count_arrangements(0);
    cout << result << endl;

    return 0;
}
