#include <bits/stdc++.h>
#define MAX 25
using namespace std;
int n, m;
int p[MAX];
vector<pair<int, int> > adj;
vector<pair<int, int> > edge;
int ans = 0;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    p[find(x)] = find(y);
}

void reset_parent() {
    for(int i = 0; i < MAX; i++)
        p[i] = i;
}

bool check_kruskal(vector<pair<int, int> > edge) {
    reset_parent();
    for(int i = 0; i < edge.size(); i++) {
        int u = edge[i].first, v = edge[i].second;
        if(find(u) != find(v)) {
            unite(u, v);
        }
        else return false;
    }
    return true;
}

void Try(int x) {
    if(x >= m) {
        if(edge.size() == n-1) {
            if(check_kruskal(edge)) ans++;
        }
    }
    else {
        if(edge.size() < n-1) {
            edge.push_back(adj[x]);
            Try(x+1);
            edge.pop_back();
        }
        Try(x+1);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj.push_back(make_pair(u, v));
    }
    reset_parent();
    Try(0);
    cout << ans;
}