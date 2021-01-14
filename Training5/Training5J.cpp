#include <bits/stdc++.h>

using namespace std;
int n, T, d;
int a[1005], t[1005];
int dp[1005][1005];

int main()
{
    cin >> n >> T >> d;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> t[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int k = t[i]; k <= T; k++) {
            for(int j = i-1; j >= max(0, i-d); j--)
                dp[i][k] = max(dp[i][k], dp[j][k-t[i]]+a[i]);
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
    return 0;
}
