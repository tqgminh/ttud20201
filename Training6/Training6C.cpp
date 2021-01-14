#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m, x, y;
vector<int> adj[MAX];
vector<int> low(MAX), num(MAX, -1);
int bridges = 0, arti_points = 0;
int is_arti_points[MAX];
int curnum = 0;
void find_bridges_arti_points(int u, int p) {
    int children = 0;
    low[u] = num[u] = curnum++;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        if(num[v] == -1) {
            children++;
            find_bridges_arti_points(v, u);
            if(low[v] >= num[u]) {
                is_arti_points[u] = (u == p) ? (children > 1) : 1;
            }
            if(low[v] > num[u]) {
                bridges++;
            }
            low[u] = min(low[u], low[v]);

        }
        else {
            low[u] = min(low[u], num[v]);
        }

    }

}

int main() {
    cin >> n >> m;
    while(m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        if(num[i] == -1) {
            find_bridges_arti_points(i, i);
        }
    }
    for(int i = 1; i <= n; i++) {
        arti_points += is_arti_points[i];
    }
    cout << arti_points << " " << bridges;
}
