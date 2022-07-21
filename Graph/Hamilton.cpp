#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 5;

int nodes, edges, n = 1;

vector<int> hPath, adj[MAX_N];
bool visited[MAX_N];

void printPath();
void dfs(int);
void Hamilton();

int main()  {
    freopen("in.txt", "r", stdin);
    cin >> nodes >> edges;

    for(int i = 0, a, b; i < edges; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
        
    cout << "Hamilton Paths:\n\n";
    Hamilton();

    return 0;
}

void printPath()    {
    cout << "Path No. " << n++ << ":\t";
    for (int i = 0; i < hPath.size(); i++)
        cout << hPath[i] << "-\n"[i == hPath.size()-1];
}

void dfs(int source)    {
    visited[source] = true;

    if(hPath.size() == nodes)    {
        visited[source] = 0;
        printPath();

        return;
    }

    for(int v : adj[source])
        if(visited[v] == false) {
            hPath.push_back(v);
            dfs(v);
            hPath.pop_back();
        }

    visited[source] = 0;
}

void Hamilton() {
    for(int i = 1; i <= nodes; i++){
        hPath.push_back(i);
        dfs(i);
        hPath.pop_back();
    }
}