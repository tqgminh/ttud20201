#include <bits/stdc++.h>
#define N 1005
using namespace std;

int t;
int main()
{

    cin >> t;
    while(t--) {
        vector<pair<int, int>> a, b;
        int l, c;
        int cnt[2*N][2*N] = {};
    	int u, v;
    	cin >> l >> c;
    	for(int i = 0; i < l; i++)
    		for(int j = 0; j < c; j++) {
    			cin >> u;
    			if(u) a.push_back({i, j});
		}
	for(int i = 0; i < l; i++)
		for(int j = 0; j < c; j++) {
			cin >> u;
			if(u) b.push_back({i, j});
		}
	for(auto &u: a)
		for(auto &v: b) {
			int delta_x = v.first - u.first + N;
			int delta_y = v.second - u.second + N;
			cnt[delta_x][delta_y]++;
		}
	int ans = 0;
	for(int i = 0; i < 2*N; ++i)
		for(int j = 0; j < 2*N; ++j)
			ans = max(ans, cnt[i][j]);
		cout << ans << "\n";
    }
    return 0;
}
