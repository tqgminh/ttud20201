#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, x, y;
vector<int> adj[MAX];
vector<bool> visited(MAX, false);
int parent[MAX];
void bfs(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    parent[start] = 1;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!visited[v]) {
                Q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
}
int main() {
    cin >> n;
    int k = n-1;
    while(k--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    for(int i = 2; i <= n; i++)
        cout << parent[i] << " ";
}
