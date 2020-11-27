#include <bits/stdc++.h>

using namespace std;
int n, k, m, ans = 0;
int c[40][40], mark[40], visit[40];
void Try(int x) {
    if(x == k+2)
        ans++;
    else {
        for(int i = 1; i <= n; ++i) {
            if(mark[i] == 0 && c[visit[x-1]][i] == 1) {
                mark[i] = 1;
                visit[x] = i;
                Try(x+1);
                mark[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        c[x][y] = 1;
        c[y][x] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        visit[1] = i;
        mark[i] = 1;
        Try(2);
        mark[i] = 0;
    }
    cout << ans/2;
    return 0;
}
