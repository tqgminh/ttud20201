#include <bits/stdc++.h>
#define MAX 5005
using namespace std;
int n, k, x, y;
int C[MAX], D[MAX];
vector<int> adj[MAX];
int dist[MAX];

vector<pair<int, int> > new_adj[MAX];

void BFS(int start) {
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        dist[i] = -1;
    Q.push(start);
    dist[start] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(dist[v] == -1) {
                Q.push(v);
                dist[v] = 1+dist[u];
            }
        }
    }
}

void dijkstra(int start) {
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(dist[start], start));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < new_adj[u].size(); i++) {
            int v = new_adj[u][i].first;
            int w = new_adj[u][i].second;

            if(w+dist[u] < dist[v]) {
                dist[v] = w+dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> C[i] >> D[i];
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        memset(dist, 0, sizeof(dist));
        BFS(i);
        for(int j = 1; j <= n; j++) {
            if(dist[j] <= D[i] && i != j) {
                new_adj[i].push_back(make_pair(j, C[i]));
            }
        }
    }
    dijkstra(1);
    cout << dist[n];
}
