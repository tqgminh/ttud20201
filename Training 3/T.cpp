#include <bits/stdc++.h>
#define N 15
using namespace std;
int n, m, ans, a[N*2], b[N*2], c[N*2], x, y, ok[N][N];
void Try(int k) {
    if(k == n) ans++;
    else {
        for(int i = 0; i < n; i++) {
            if(a[i] == 0 && b[k+i] == 0 && c[k-i+N] == 0 && ok[k][i] == 0) {
                a[i] = 1;
                b[k+i] = 1;
                c[k-i+N] = 1;
                ok[k][i] = 1;
                Try(k+1);
                a[i] = 0;
                b[k+i] = 0;
                c[k-i+N] = 0;
                ok[k][i] = 0;
            }
        }
    }
}
int main()
{
    while(1) {
        cin >> n >> m;
        if(m == 0 && n == 0) return 0;
        for(int i = 0; i < N*2; ++i) {
            a[i] = 0;
            b[i] = 0;
            c[i] = 0;
        }
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                ok[i][j] = 0;
        ans = 0;
        for(int i = 0 ; i < m; ++i) {
            cin >> x >> y;
            ok[x-1][y-1] = 1;
        }
        Try(0);
        cout << ans << "\n";
    }
    return 0;
}
