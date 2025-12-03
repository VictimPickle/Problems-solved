#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rectangle {
    int x, y, a, b;
};

int main() {
    int n;
    cin >> n;
    
    vector<Rectangle> rects(n);
    vector<int> x_coords, y_coords;

    for (int i = 0; i < n; ++i) {
        cin >> rects[i].x >> rects[i].y >> rects[i].a >> rects[i].b;
        x_coords.push_back(rects[i].x);
        x_coords.push_back(rects[i].x + rects[i].a);
        y_coords.push_back(rects[i].y);
        y_coords.push_back(rects[i].y + rects[i].b);
    }

    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());
    x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

    auto getX = [&](int x) {
        return lower_bound(x_coords.begin(), x_coords.end(), x) - x_coords.begin();
    };
    
    auto getY = [&](int y) {
        return lower_bound(y_coords.begin(), y_coords.end(), y) - y_coords.begin();
    };

    int X_SIZE = x_coords.size();
    int Y_SIZE = y_coords.size();
    vector<vector<bool>> grid(X_SIZE, vector<bool>(Y_SIZE, false));

    for (int i = 0; i < n; ++i) {
        int x1 = getX(rects[i].x);
        int y1 = getY(rects[i].y);
        int x2 = getX(rects[i].x + rects[i].a);
        int y2 = getY(rects[i].y + rects[i].b);

        for (int x = x1; x < x2; ++x) {
            for (int y = y1; y < y2; ++y) {
                grid[x][y] = true;
            }
        }
    }

    int covered_area = 0;
    for (int i = 0; i < X_SIZE - 1; ++i) {
        for (int j = 0; j < Y_SIZE - 1; ++j) {
            if (grid[i][j]) {
                int width = x_coords[i + 1] - x_coords[i];
                int height = y_coords[j + 1] - y_coords[j];
                covered_area += width * height;
            }
        }
    }

    cout << covered_area << endl;
    return 0;
}
