#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n, m;
vector<int> adj[MAXN];
vector<int> low(MAXN), num(MAXN, 0);
vector<bool> connect(MAXN, false);
stack<int> comp;
int cur = 0;
int ans = 0;
void scc(int u) {
    connect[u] = true;
    low[u] = num[u] = ++cur;
    comp.push(u);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(num[v] == 0) {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if(connect[v]) {
            low[u] = min(low[u], num[v]);
        }
    }
    if(num[u] == low[u]) {
        ans++;
        while(true) {
            int curr = comp.top();
            comp.pop();
            connect[curr] = false;
            if(curr == u) break;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    while(m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) {
        if(num[i] == 0)
            scc(i);
    }
    printf("%d", ans);
}
