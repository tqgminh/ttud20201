#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[5005], mark[100005];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        mark[a[i]]++;
    }
    sort(a, a+n);
    long long ans = 0;
    for(int i = 0; i < n-2; i++) {
        mark[a[i]]--;
        for(int j = i+1; j < n-1; j++) {
            mark[a[j]]--;
            if(k-a[i]-a[j] > 0)
                ans += mark[k-a[i]-a[j]];
            //mark[a[j]]++;
        }
        for(int j = i+1; j < n-1; j++)
            mark[a[j]]++;
    }

    cout << ans;
    return 0;
}
