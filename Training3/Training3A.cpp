#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m; // số thành phố và số chi phí đường đi
int visit[25]; // mảng đánh dấu các đỉnh đã đi
int v[25]; // mảng lưu đường đi
int c, cmin = 10e7, ans = 10e7, sum = 0, x, y;
int a[25][25]; // mảng lưu vị trí chi phí đường đi

// hàm quay lui
void Try(int k) {
    // xét các đỉnh từ 1 đến n
    for(int i = 1; i <= n; ++i) {
        // nếu đỉnh i chưa đc thăm
        if(visit[i] == 0) {
            v[k] = i;
            visit[i] = 1;
            sum = sum+a[v[k-1]][v[k]];
            // kết thúc
            if(k == n)
                ans = min(ans, sum+a[v[n]][v[1]]);
            // nhánh cận
            else
                if(sum+(n-k+1)*cmin < ans) Try(k+1);
            sum = sum-a[v[k-1]][v[k]];
            visit[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < 25; ++i)
        visit[i] = 0;
    for(int i = 1; i < 25; ++i)
        for(int j = 1; j < 25; ++j)
        a[i][j] = 10000000;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y >> c;
        a[x][y] = c;
        cmin = min(cmin, c);
    }
    v[1] = 1;
    visit[v[1]] = 1;
    Try(2);
    cout << ans;
    return 0;
}