#include <bits/stdc++.h>
using namespace std;
#define MAX 2005
int t, x, y;
int n, k, stop;
vector<int> adj[MAX];
int color[MAX];

void dfs(int start) {
    stack<int> S;
    S.push(start);
    color[start] = 0;
    while(!S.empty()) {
        int u = S.top();
        S.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(color[v] == color[u]) {
                printf("Suspicious bugs found!\n");
                stop = 1;
                return;
            }
            if(color[v] == -1) {
                S.push(v);
                color[v] = 1-color[u];
            }
        }
    }
}



int main() {
    scanf("%d", &t);
    int index = 1;
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        while(k--) {
            scanf("%d%d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i = 1; i <= n; i++)
            color[i] = -1;
        int i = 1;
        stop = 0;
        printf("Scenario #%d:\n", index);
        while(i <= n && stop == 0) {
            if(color[i] == -1)
                dfs(i);
            i++;
        }
        if(stop == 0)
            printf("No suspicious bugs found!\n");
        index++;
    }
}
