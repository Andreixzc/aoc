#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool inc = false;
    bool dec = false;
    int safeLines = 0;

    ifstream myFile("input.txt");
    string line;

    while (getline(myFile, line)) {
        istringstream iss(line);
        int prev, current;
        bool isSafe = true;

        if (!(iss >> prev)) continue;

        
        while (iss >> current) {
            cout << prev << " com " << current << endl;
            if (prev > current){
                dec = true;
            } else if (prev < current) {
                inc = true;
            
            }
            if ((inc && dec) || abs (prev - current) < 1 || abs (prev - current) >3){
                isSafe = false;
                break;
            }
            prev = current;
        }

        if (isSafe) safeLines++;
        inc = false;
        dec = false;
       // cout << "changed line " << endl;
        
    }
    cout << safeLines << endl;

    return 0;
}

