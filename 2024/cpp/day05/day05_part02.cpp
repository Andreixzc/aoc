#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool isValidSequence(const vector<int>& numbers, unordered_map<int, vector<int>>& adj) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        int current = numbers[i];
        int next = numbers[i + 1];
        auto it = adj.find(current);
        if (it == adj.end()) continue;
        
        bool found = false;
        for (int neighbor : it->second) {
            if (neighbor == next) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}
vector<int> getCorrectOrder(vector<int>& numbers, unordered_map<int, vector<int>>& adj) {
    unordered_map<int, vector<int>> subgraph;
    unordered_map<int, int> inDegree;

    for (int num : numbers) inDegree[num] = 0;
    for (int num : numbers) {
        if (adj.find(num) != adj.end()) {
            for (int next : adj[num]) {
                if (find(numbers.begin(), numbers.end(), next) != numbers.end()) {
                    subgraph[num].pb(next);
                    inDegree[next]++;
                }
            }
        }
    }
    queue<int> q;
    for (auto& pair : inDegree) {
        if (pair.second == 0) {
            q.push(pair.first);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.pb(current);
        
        if (subgraph.find(current) != subgraph.end()) {
            for (int next : subgraph[current]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
    
    return result;
}

int main() {
    ifstream file("input.txt");
    string line;
    unordered_map<int, vector<int>> adj;
    int ans = 0;
    while (getline(file, line)) {
        if (line.find('|') == string::npos) break;
        stringstream ss(line);
        int u, v;
        char delimiter;
        ss >> u >> delimiter >> v;
        adj[u].pb(v);
    }
    while (getline(file, line)) {
        vector<int> numbers;
        stringstream ss(line);
        string number;
        while (getline(ss, number, ',')) {
            numbers.pb(stoi(number));
        }
        if (isValidSequence(numbers, adj)) {
            continue;
        }
        vector<int> correctOrder = getCorrectOrder(numbers, adj);
        ans += correctOrder[correctOrder.size() / 2];
    }

    cout << ans << endl;
    return 0;
}