#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isSafeSequence(const vector<int> &array, int index)
{

    bool inc = false;
    bool dec = false;
    vector<int> numbers;
    for (int i = 0; i < array.size(); i++)
    {
        if (i != index)
        {
            numbers.push_back(array[i]);
        }
    }

    for (int i = 1; i < numbers.size(); i++)
    {
        int prev = numbers[i - 1];
        int current = numbers[i];

        if (prev > current)
        {
            dec = true;
        }
        else if (prev < current)
        {
            inc = true;
        }

        if ((inc && dec) ||abs(prev - current) < 1 ||abs(prev - current) > 3)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream inFile("input.txt");
    string line;
    int ans = 0;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        int num;
        vector<int> array;
        while (ss >> num)
        {
            array.push_back(num);
        }
        bool isSafe = false;
        bool inc = false;
        bool dec = false;

        if (!isSafeSequence(array, -1) && !isSafeSequence(array,0))
        {
            for (int i = 1; i < array.size(); i++)
            {
                if (array[i - 1] > array[i])
                {
                    inc = true;
                }
                else if (array[i - 1] < array[i])
                {
                    dec = true;
                }
                int dif = abs(array[i - 1] - array[i]);
                if (inc && dec || dif < 1 || dif > 3)
                {
                    isSafe = isSafeSequence(array, i) || isSafeSequence(array, i - 1);
                    break;
                }
            }

            if (isSafe)
                ans++;
        } else {
            ans++;
        }
    }
    cout << ans << endl;
}
