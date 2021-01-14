#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int p[MAX], n, m;
struct edge {
    int u, v;
    int weight;

    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};
vector<edge> adj;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void unite(int x, int y) {
    p[find(x)] = find(y);
}

bool edge_cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

void reset_parent() {
    for(int i = 0; i <= MAX; i++)
        p[i] = i;
}

long long kruskal(vector<edge> edges) {
    reset_parent();
    //vector<edge> mst;
    sort(edges.begin(), edges.end(), edge_cmp);
    long long ans = 0;
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        if(find(u) != find(v)) {
            unite(u, v);
            //mst.push_back(adj[i]);
            ans += (edges[i].weight);
        }
    }
    return ans;
}

int main() {
    reset_parent();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back(edge(u, v, w));
        //p[v] = u;
    }
    cout << kruskal(adj);
}
