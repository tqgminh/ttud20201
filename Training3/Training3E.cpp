#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[20]; // lưu số tín của môn học
int load[20]; // số tín của kì
int t[20]; // lưu kì học của môn
int a[20][20]; // lưu điều kiện tiên quyết
int ans = 10000000;

// tính số tín tối đa của các kì
int value(int load[]) {
    int res = 0;
    for(int i = 1; i <= m; i++)
        res = max(res, load[i]);
    return res;
}

// kiếm tra đến kì k đã thỏa mãn điều kiện tiên quyết chưa
bool check(int t[], int k) {
    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= k && j != i; ++j) {
            if(a[i][j] == 1 && t[j] <= t[i]) return false;
        }
    }
    return true;
}

//
void Try(int k) {
    if(k == n+1) {
        if(check(t, n))
            ans = min(ans, value(load));
    }
    else {
        for(int i = 1; i <= m; i++) {
            load[i] += c[k];
            t[k] = i;
            if(value(load) < ans && check(t, k)) Try(k+1);
            load[i] -= c[k];
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    Try(1);
    cout << ans;
    return 0;
}
