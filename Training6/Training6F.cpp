#include <bits/stdc++.h>
#define MAX 25
using namespace std;
int n, m, k;
vector<pair<int, int> > adj[MAX];

int kmst(int start) {
	vector<bool> inT(n+1, false);
	int res = 0;
	int count = 0;
	vector<int> bestW(n+1, 1e9), bestAdj(n+1, -1);
	bestW[start] = 0;
	while(count < k) {
		int v = -1, w = 1e9;
		for(int x = 1; x <= n; ++x) {
			if(inT[x] == false && bestW[x] < w) {
				//u = bestAdj[x];
				v = x;
				w = bestW[x];
			}
		}
		if(v == -1) return 1e9;
		inT[v] = true;
		for(pair<int, int> e: adj[v]) {
			if(bestW[e.first] > e.second) {
				bestW[e.first] = e.second;
				bestAdj[e.first] = v;
			}
		}
		if(v != start) {
			res += w;
			count++;
		}
	}
	return res;
}

int main() {
	cin >> n >> m >> k;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	int ans = 1e9;
	for(int i = 1; i <= n; i++) {
		ans = min(kmst(i), ans);
	}
	if(ans == 1e9) cout << "-1";
	else cout << ans;
}