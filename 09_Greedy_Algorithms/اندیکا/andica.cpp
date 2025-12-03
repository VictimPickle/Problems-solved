#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string votes;
    cin >> votes;

    vector<vector<bool>> vote_dependence(n + 1, vector<bool>(n + 1, false));
    vector<int> degree_count(n + 1, 0);
    vector<int> votes_for(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        degree_count[i] = i;
        if (votes[i - 1] == 'K') {
            votes_for[i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        vote_dependence[i][i] = true;
        if (i < n) {
            vote_dependence[i][i + 1] = true;
        }
    }

    vector<int> result_votes = votes_for;

    for (int i = n; i >= 1; --i) {
        if (votes_for[i] == 0) {
            result_votes[i] = 1;
        }
    }

    int total_votes = 0;
    for (int i = 1; i <= n; ++i) {
        total_votes += result_votes[i];
    }

    cout << total_votes << endl;
    return 0;
}
