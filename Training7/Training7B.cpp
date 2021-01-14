#include <bits/stdc++.h>
using namespace std;
int t[100009], n, ans = 0;
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> t[i];
    sort(t, t+n);

    for(int i = n-1; i >= 0; i--)
        if((n-i)+t[i]+1 > ans) ans = (n-i)+t[i]+1;
    cout << ans;
    return 0;
}
