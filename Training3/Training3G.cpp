#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n, k, q;
ull ans = 0;
int d[20]; // số gói điểm i yêu cầu
int m[20]; // khối lượng xe i đã load
int load[20]; // số địa điểm mà xe i đã load
ull fact(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return n*fact(n-1);
}
void Try(int x) {
    if(x == n) {
        ull res = 1;
        for(int i = 1; i <= k; ++i)
            res = res*fact(load[i]);
        ans = ans+res;
    }
    else {
        for(int i = 1; i <= k; ++i) {
            int t = m[i];
            int p = load[i];
            load[i]++;
            m[i] = m[i]+d[x];
            if(m[i] <= q) Try(x+1);
            load[i] = p;
            m[i] = t;
        }
    }
}
int main()
{
    cin >> n >> k >> q;
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    Try(0);
    cout << (ans/fact(k))%1000000009;
    return 0;
}