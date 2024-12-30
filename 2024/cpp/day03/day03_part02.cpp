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
    bool dont = false;

    while (scanf("%c", &c) != EOF) {
        str += c;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'd' && i + 2 < str.length()) {
            if (str[i + 1] == 'o' && str[i + 2] == '(') {
                if (i + 3 < str.length() && str[i + 3] == ')') {
                    dont = false;
                    i += 3;
                    continue;
                }
            }
            else if (str[i + 1] == 'o' && str[i + 2] == 'n' && i + 6 < str.length()) {
                if (str[i + 3] == '\'' && str[i + 4] == 't' && str[i + 5] == '(' && str[i + 6] == ')') {
                    dont = true;
                    i += 6;
                    continue;
                }
            }
        }

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
                    }
                    else {
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
                        }
                        else {
                            validExpression = false;
                            break;
                        }
                        j++;
                    }

                    if (validExpression && j < str.length() && str[j] == ')') {
                        y = getNumber(yString);
                        if (!dont) {
                            total += x * y;
                        }
                    }
                    else {
                        validExpression = false;
                    }
                }
                else {
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