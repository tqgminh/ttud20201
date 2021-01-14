#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n;
vector<pair<int, int> > adj[MAX];
int dist[MAX];
//vector<bool> visited[MAX];
/* 
void dijkstra(int start) {
	for(int i = 1; i <= n; i++)
		dist[i] = INT_MAX;
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
	pq.push(make_pair(dist[start], start));
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop(); 
		for(int i = 0; i < edge[u].size(); i++) {
			int v = edge[u][i].first;
			int w = edge[u][i].second;
			if(w+dist[u] < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}
*/
void dfs(int start) {
    stack<int> S;
    for(int i = 1; i <= n; i++)
        dist[i] = -1;
    S.push(start);
    dist[start] = 0;
    while(!S.empty()) {
        int u = S.top();
        S.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[v] == -1) {
                S.push(v);
                dist[v] = w+dist[u];
            }
        }
    }
}

int main() {
	cin >> n;
	int m = n-1;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	int ans = 0, re = 1;
	dfs(1);
	for(int i = 1; i <= n; i++) {
		if(dist[re] < dist[i])
			re = i;
	}
	dfs(re);
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dist[i]);
	}
	cout << ans;
}