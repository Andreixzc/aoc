#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void solve() {
    // Your code here
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream myFile("input.txt");
    string line;
    vector<int> list1;
    map<int, int> freqMap;
    while (getline(myFile, line)) {
        stringstream ss(line);
        int num1 = 0;
        int num2 = 0;
        ss >> num1 >> num2;

        list1.push_back(num1);
        freqMap[num2]++;

    }
    int ans = 0;
    for (int i = 0; i <= list1.size(); i++) {

        ans += list1[i] * freqMap[list1[i]];

    }

    cout << ans << endl;

    return 0;
}

