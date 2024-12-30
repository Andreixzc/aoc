#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int check(const vector<vector<char>>& matrix, int i, int j) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    if (i - 1 < 0 || i + 1 >= rows || j - 1 < 0 || j + 1 >= cols) return 0;
    if (matrix[i][j] == 'A') {
        bool diag1_mas = (matrix[i - 1][j - 1] == 'M' && matrix[i + 1][j + 1] == 'S');
        bool diag1_sam = (matrix[i - 1][j - 1] == 'S' && matrix[i + 1][j + 1] == 'M');
        bool diag2_mas = (matrix[i - 1][j + 1] == 'M' && matrix[i + 1][j - 1] == 'S');
        bool diag2_sam = (matrix[i - 1][j + 1] == 'S' && matrix[i + 1][j - 1] == 'M');
        if ((diag1_mas || diag1_sam) && (diag2_mas || diag2_sam))
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> matrix;
    ifstream file("input.txt");
    string line;
    int ans = 0;

    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        matrix.pb(row);
    }
    file.close();

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 'A')
                ans += check(matrix, i, j);
        }
    }

    cout << ans << endl;
}