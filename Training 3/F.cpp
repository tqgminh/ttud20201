#include <bits/stdc++.h>
using namespace std;
int n;
int visit[25]; // mảng đánh dấu các vị trí đã thăm
int go[25]; // lưu vị trí đã đi
int cmin = 10000000, ans = 10000000, sum = 0;
int a[25][25]; // lưu chi phí đi
void Try(int k) {
    for(int i = 1; i <= n; ++i) {
        if(visit[i] == 0) {
            go[k] = i;
            visit[i] = 1;
            sum = sum+a[go[k-1]+n][go[k]]+a[go[k]][go[k]+n];
            if(k == n) ans = min(ans, sum+a[go[k]+n][0]);
            else
                if(sum+(2*(n-k)+1)*cmin < ans) Try(k+1);
            sum = sum-(a[go[k-1]+n][go[k]]+a[go[k]][go[k]+n]);
            visit[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < 25; ++i)
        visit[i] = 0;
    for(int i = 0; i < 2*n+1; ++i)
        for(int j = 0; j < 2*n+1; ++j) {
            cin >> a[i][j];
            if(i != j) cmin = min(cmin, a[i][j]);
        }
    for(int i = 1; i <= n; ++i) {
        go[1] = i;
        visit[i] = 1;
        sum = a[0][i]+a[i][i+n];
        Try(2);
        visit[i] = 0;
    }
    cout << ans;
    return 0;
}
