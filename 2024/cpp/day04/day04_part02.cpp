#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int checkSE(const vector<vector<char>> &matrix, int i, int j) {
    if (i + 3 >= matrix.size() || j + 3 >= matrix[i].size())
        return 0;
    return matrix[i + 1][j + 1] == 'M' && matrix[i + 2][j + 2] == 'A' && matrix[i + 3][j + 3] == 'S';
}

int checkNE(const vector<vector<char>> &matrix, int i, int j) {
    if (i - 3 < 0 || j + 3 >= matrix[i].size())
        return 0;
    return matrix[i - 1][j + 1] == 'M' && matrix[i - 2][j + 2] == 'A' && matrix[i - 3][j + 3] == 'S';
}

int checkNO(const vector<vector<char>> &matrix, int i, int j) {
    if (i - 3 < 0 || j - 3 < 0)
        return 0;
    return matrix[i - 1][j - 1] == 'M' && matrix[i - 2][j - 2] == 'A' && matrix[i - 3][j - 3] == 'S';
}

int checkSO(const vector<vector<char>> &matrix, int i, int j) {
    if (i + 3 >= matrix.size() || j - 3 < 0)
        return 0;
    return matrix[i + 1][j - 1] == 'M' && matrix[i + 2][j - 2] == 'A' && matrix[i + 3][j - 3] == 'S';
}

int checkN(const vector<vector<char>> &matrix, int i, int j) {
    if (i - 3 < 0)
        return 0;
    return matrix[i - 1][j] == 'M' && matrix[i - 2][j] == 'A' && matrix[i - 3][j] == 'S';
}

int checkS(const vector<vector<char>> &matrix, int i, int j) {
    if (i + 3 >= matrix.size())
        return 0;
    return matrix[i + 1][j] == 'M' && matrix[i + 2][j] == 'A' && matrix[i + 3][j] == 'S';
}

int checkO(const vector<vector<char>> &matrix, int i, int j) {
    if (j - 3 < 0)
        return 0;
    return matrix[i][j - 1] == 'M' && matrix[i][j - 2] == 'A' && matrix[i][j - 3] == 'S';
}

int checkL(const vector<vector<char>> &matrix, int i, int j) {
    if (j + 3 >= matrix[i].size())
        return 0;
    return matrix[i][j + 1] == 'M' && matrix[i][j + 2] == 'A' && matrix[i][j + 3] == 'S';
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
            if (matrix[i][j] == 'X') {
                ans += checkSE(matrix, i, j);
                ans += checkNE(matrix, i, j);
                ans += checkNO(matrix, i, j);
                ans += checkSO(matrix, i, j);
                ans += checkN(matrix, i, j);
                ans += checkS(matrix, i, j);
                ans += checkO(matrix, i, j);
                ans += checkL(matrix, i, j);
            }
        }
    }

    cout << ans << endl;
}


