#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

unordered_map<int, vector<int>> adj;
void addEdge(int u, int v) {
    adj[u].push_back(v);
}
bool dfs(int origin, int destination, unordered_map<int, vector<int>> &graph)
{
    stack<int> s;
    unordered_set<int> visited;
    s.push(origin);
    visited.insert(origin);
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        if (u == destination)
        {
            return true;
        }
        for (int v : graph[u])
        {
            if (visited.find(v) == visited.end())
            {
                s.push(v);
                visited.insert(v);
            }
        }
    }
    return false;
}

int main()
{
    ifstream file("input.txt");
    string line;
    int ans = 0;
    while (getline(file, line))
    {
        if (line.find('|') == string::npos)
        {
            break;
        }
        stringstream ss(line);
        int u, v;
        char delimiter;
        ss >> u >> delimiter >> v;
        addEdge(u, v);
    }
    while (getline(file, line))
    {
        vector<int> numbers;
        stringstream ss(line);
        string number;
        while (getline(ss, number, ','))numbers.push_back(stoi(number));

        unordered_map<int, vector<int>> subgraph;
        unordered_set<int> sequenceSet(numbers.begin(), numbers.end());
        for (int node : numbers)
        {
            for (int neighbor : adj[node])
            {
                if (sequenceSet.find(neighbor) != sequenceSet.end()) subgraph[node].push_back(neighbor);
            }
        }
        bool valid = true;
        for (int i = 0; i < numbers.size(); i++)
        {
            for (int j = i + 1; j < numbers.size(); j++)
            {
                if (!dfs(numbers[i], numbers[j], subgraph))
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }
        if (valid) ans += numbers[numbers.size() / 2];
    }

    cout <<  ans << endl;

    return 0;
}


