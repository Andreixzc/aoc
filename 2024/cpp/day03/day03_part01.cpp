#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int getNumber(string str) {
    int result = 0;
    for (char c : str) {
        if (isdigit(c)) {
            result = result * 10 + (c - '0');
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    char c;
    int total = 0;
    while (scanf("%c", &c) != EOF) {
        str += c;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'm' && i + 3 < str.length()) {
            if (str[i + 1] == 'u' && str[i + 2] == 'l' && str[i + 3] == '(') {
                int j = i + 4;
                string xString, yString;
                int x = 0, y = 0;
                bool validExpression = true;
                while (j < str.length() && str[j] != ',' && str[j] != ')') {
                    if (isdigit(str[j])) {
                        xString += str[j];
                        if (xString.length() > 3) {
                            validExpression = false;
                            break;
                        }
                    } else {
                        validExpression = false;
                        break;
                    }
                    j++;
                }

                if (validExpression && j < str.length() && str[j] == ',') {
                    x = getNumber(xString);
                    j++; 
                    while (j < str.length() && str[j] != ')') {
                        if (isdigit(str[j])) {
                            yString += str[j];
                            if (yString.length() > 3) {
                                validExpression = false;
                                break;
                            }
                        } else {
                            validExpression = false;
                            break;
                        }
                        j++;
                    }

                    if (validExpression && j < str.length() && str[j] == ')') {
                        y = getNumber(yString);
                        total += x * y;
                    } else {
                        validExpression = false;
                    }
                } else {
                    validExpression = false;
                }

                if (!validExpression) {
                    i = j;
                }
            }
        }
    }

    cout << total << endl;
    return 0;
}
