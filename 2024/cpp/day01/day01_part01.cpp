#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream myFile("input.txt");
    ofstream outputFile("output.txt");

    vector<int> list1;
    vector<int> list2;
    string line;
    int total = 0;

    while (getline(myFile, line)) {
        stringstream ss(line);
        int num1, num2;
        ss >> num1 >> num2;
        list1.push_back(num1);
        list2.push_back(num2);
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());


    for (size_t i = 0; i <= list1.size(); i++) {
        total += abs(list1[i] - list2[i]);
    }

    outputFile << total << endl;

    return 0;
}
