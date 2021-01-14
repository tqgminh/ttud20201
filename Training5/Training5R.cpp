#include <bits/stdc++.h>
 
using namespace std;
int n;
int a[1000006], maxsub[1000006];
int main()
{
    int ans = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    maxsub[0] = a[0];
    for(int i = 1; i < n; i++) {
        maxsub[i] = max(a[i], maxsub[i-1]+a[i]);
    }
    for(int i = 0; i < n; i++)
        ans = max(ans, maxsub[i]);
    cout << ans;
    return 0;
}