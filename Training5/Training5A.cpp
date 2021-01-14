#include <bits/stdc++.h>
using namespace std;
int n, L1, L2;
int a[100005];
int mem[100005];

void init() {
    memset(mem, -1, sizeof(mem));
}
int Try(int x) {
    if(x < 0)
        return 0;
    if(mem[x] < 0) {
        int tmp = 0;
        for(int i = x-L2; i <= x-L1; ++i)
            tmp = max(tmp, Try(i));
        mem[x] = tmp+a[x];
    }
    return mem[x];
}
int main()
{
    init();
    cin >> n >> L1 >> L2;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0;
    for(int i = n-L1; i < n; ++i)
        res = max(res, Try(i));
    cout << res;
   return 0;
}
