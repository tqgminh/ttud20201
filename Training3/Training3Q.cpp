#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull n, m, k, in[10004];
ull a[10004];
vector<ull> show;
ull C(ull k, ull n)
{
    ull res = 1;
    ull m = k < n/2 ? k : n-k;
    for(ull i = 1; i <= m; i++, n--) {
        res = res*n/i;
    }
    return res;
}
void Init() {
    for(ull i = 1; i <= n; ++i)
        in[i] = i;
}
void deleteIndex(int k) {
    for(ull i = k; i < n; ++i)
        in[i-k+1] = in[i+1];
    n = n-k;
}
ull ToHop() {
    a[0] = 0;
    for(ull i = 1; i <= n-m+1; ++i) {
        a[i] = a[i-1]+C(m-1, n-i);
        if(a[i] >= k) return i;
    }
    return 0;
}
int run() {
    while(m > 0) {
        ull x = ToHop();
        if(x == 0 || in[x] == 0) {
            return 0;
        }
        show.push_back(in[x]);
        k = k-a[x-1];
        m--;
        deleteIndex(x);
    }
    return 1;
}
int main()
{
    cin >> n >> m >> k;
    Init();
    if(run())
        for(ull i = 0; i < show.size(); ++i)
        cout << show.at(i) << " ";
    else cout << "-1";
    return 0;
}
