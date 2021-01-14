#include <bits/stdc++.h>
#define MAX 25
using namespace std;
int n, m;
int select[MAX];
int adj[MAX][MAX];
int ans = 0;

void Try(int x) {
	if(x == n+1) {
		vector<int> point;
		for(int i = 1; i <= n; i++) {
			if(select[i] == 1)
				point.push_back(i);
		}
		int sum = 0;
		int sum_point = point.size();
		for(int i = 0; i < sum_point; i++) {
			for(int j = i+1; j < sum_point; j++) {
				if(point[i] != point[j] && adj[point[i]][point[j]] == 1)
					sum++;
			}
		}
		if(sum == sum_point*(sum_point-1)/2) ans = max(ans, sum_point);
	}
	else {
		select[x] = 0;
		Try(x+1);

		select[x] = 1;
		Try(x+1);
	}
}

int main() {
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	Try(1);
	cout << ans;
}