#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, m, start, finish;
vector<pair<int, int> > edge[MAX];
int dist[MAX];
//vector<bool> visited[MAX];

void dijkstra(int start) {
	for(int i = 1; i < MAX; i++)
		dist[i] = INT_MAX;
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
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

int main() {
	cin >> n >> m;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(v, w));
	}
	cin >> start >> finish;
	dijkstra(start);
	cout << dist[finish];
}