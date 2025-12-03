#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

vector<pair<int, int>> word_search(vector<vector<char>>& matrix, int m, int n, string word) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    function<vector<pair<int, int>>(int, int, int, vector<pair<int, int>>)> backtrack;
    backtrack = [&](int x, int y, int index, vector<pair<int, int>> path) -> vector<pair<int, int>> {
        if (index == word.length()) {
            return path;
        }

        visited[x][y] = true;
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (is_valid(nx, ny, m, n) && !visited[nx][ny] && matrix[nx][ny] == word[index]) {
                path.push_back({nx, ny});
                auto result = backtrack(nx, ny, index + 1, path);
                if (!result.empty()) {
                    return result;
                }
                path.pop_back();
            }
        }
        visited[x][y] = false;
        return {};
    };

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == word[0]) {
                vector<pair<int, int>> path = {{i, j}};
                auto result = backtrack(i, j, 1, path);
                if (!result.empty()) {
                    return result;
                }
            }
        }
    }

    return {};
}

void print_result(int m, int n, vector<pair<int, int>>& path) {
    if (path.empty()) {
        cout << "Not found" << endl;
    } else {
        vector<vector<int>> result_matrix(m, vector<int>(n, 0));
        for (int i = 0; i < path.size(); ++i) {
            result_matrix[path[i].first][path[i].second] = i + 1;
        }
        for (const auto& row : result_matrix) {
            for (int i = 0; i < row.size(); ++i) {
                cout << row[i] << (i < row.size() - 1 ? " " : "\n");
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    string word;
    cin >> word;

    vector<pair<int, int>> path = word_search(matrix, m, n, word);
    print_result(m, n, path);

    return 0;
}
