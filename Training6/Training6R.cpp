#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;

int f, s, g, u, d;
int dist[MAX];
void bfs(int start) {
	for(int i = 1; i <= f; i++)
		dist[i] = -1;
	dist[start] = 0;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()) {
		int temp = Q.front();
		Q.pop();
		if(temp-d > 0) {
			int v = temp-d;
			if(dist[v] == -1) {
				Q.push(v);
				dist[v] = 1+dist[temp];
			}
		}
		if(temp+u <= f) {
			int v = temp+u;
			if(dist[v] == -1) {
				Q.push(v);
				dist[v] = 1+dist[temp];
			}
		}
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;
	bfs(s);
	if(dist[g] == -1)
		cout << "use the stairs";
	else
		cout << dist[g];
}