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
void printGraph() {
    for (const auto& pair : adj) {
        cout << "Vértice " << pair.first << " : ";
        for (int v : pair.second) {
            cout << v << " ";
        }
        cout << endl;
    }
}
int main() {
    ifstream file("graph.txt");  // Supondo que o arquivo se chame "graph.txt"
    string line;
    
    // Lê o arquivo linha por linha
    while (getline(file, line)) {
        stringstream ss(line);
        int u, v;
        
        // Lê os dois números separados por "|"
        char delimiter;
        ss >> u >> delimiter >> v;
        
        // Adiciona a aresta direcionada de u para v
        addEdge(u, v);
    }

    // Imprime o grafo
    printGraph();
    
    return 0;
}

