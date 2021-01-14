#include <bits/stdc++.h>

using namespace std;
int a[10005], n;
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int k = n-1;
    while(k > 0) {
        if(a[k] < a[k-1]) k--;
        else break;
    }
    if(k == 0) cout << "-1";
    else {
        int m = n-1;
        while(a[m] < a[k-1]) m--;
        swap(a[m], a[k-1]);
        for(int i = 0; i <= k-1; ++i)
            cout << a[i] << " ";
        for(int i = n-1; i >= k; i--)
            cout << a[i] << " ";
    }
    return 0;
}