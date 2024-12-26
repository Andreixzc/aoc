#include <iostream>
#include <string>
#include <cctype>

using namespace std;

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
    string str = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
    int total = 0;

    cout << "Input string: " << str << endl;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'm') {
            if (i + 3 < str.length() && str[i + 1] == 'u' && str[i + 2] == 'l' && str[i + 3] == '(') {
                int j = i + 4;
                string xString, yString;
                int x = 0, y = 0;
                bool exit = false;

                cout << "Found mul at position " << i << endl;

                while (j < str.length() && str[j] != ')' && !exit) {
                    if (isdigit(str[j])) {
                        xString += str[j];
                        if (xString.length() > 3) {
                            exit = true;
                            cout << "Error: x value too long" << endl;
                            break;
                        }
                    } else if (str[j] == ',') {
                        x = getNumber(xString);
                        cout << "x = " << x << endl;
                        j++;
                        while (j < str.length() && str[j] != ')') {
                            if (isdigit(str[j])) {
                                yString += str[j];
                                if (yString.length() > 3) {
                                    exit = true;
                                    cout << "Error: y value too long" << endl;
                                    break;
                                }
                            } else {
                                break;
                            }
                            j++;
                        }
                        y = getNumber(yString);
                        cout << "y = " << y << endl;
                        if (!exit) {
                            total += x * y;
                            cout << "Multiplication result: " << x * y << endl;
                            cout << "Running total: " << total << endl;
                        }
                        break;
                    }
                    j++;
                }
                if (str[j] != ')') {
                    cout << "Error: Missing closing parenthesis" << endl;
                }
            }
        }
    }

    cout << "Final total: " << total << endl;
    return 0;
}
