#include<bits/stdc++.h>
using namespace std;

void elevator(int capacity, vector<int> weight, vector<int> value, int num_people) {
    vector<vector<int>> dp_table(num_people + 1, vector<int>(capacity + 1));

    for (int i = 0; i <= num_people; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp_table[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp_table[i][w] = max(value[i - 1] + dp_table[i - 1][w - weight[i - 1]], dp_table[i - 1][w]);
            else
                dp_table[i][w] = dp_table[i - 1][w];
        }
    }

    int result = dp_table[num_people][capacity];
    vector<int> answer(num_people);

    int w = capacity;
    for (int i = num_people; i > 0 && result > 0; i--) {
        if (result == dp_table[i - 1][w])
            continue;
        else {
            answer[i - 1] = 1;
            result = result - value[i - 1];
            w = w - weight[i - 1];
        }
    }

    for (int i = 0; i < num_people; i++)
        cout << answer[i];
}

int main() {
    int capacity;
    cin >> capacity;
    int num_people;
    cin >> num_people;
    vector<int> weight(num_people), value(num_people);
    for (int i = 0; i < num_people; i++)
        cin >> weight[i] >> value[i];

    elevator(capacity, weight, value, num_people);

    return 0;
}
