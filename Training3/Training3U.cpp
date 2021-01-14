#include <bits/stdc++.h>

using namespace std;
int n, k1, k2;
int ans = 0;
void Try(int x) {
    if(x == k1 || x == k2+1)
        ans = (ans+1)%1000000007;
    else if(x > k1 && x <= k2)
        ans = (ans+2)%1000000007;
    else if(x > k2+1){
        for(int i = k1; i <= k2; ++i) {
            Try(x-1-i);
            //Try(x-i);
        }
    }
}
int main()
{
    cin >> n >> k1 >> k2;
    Try(n);
    Try(n-1);
    cout << ans;
    return 0;
}