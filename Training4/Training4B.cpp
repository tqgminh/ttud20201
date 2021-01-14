#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string p;
string fibword[105];
ll fib[105];
ll c[105];
ll mc[2];
int n_prepare;
void preprocessing() {
    int i = 2;
    fibword[0] = "0";
    fib[0] = 1;
    fibword[1] = "1";
    fib[1] = 1;
    n_prepare = 2;
    while(fib[i-1] < 100000) {
        fibword[i] = fibword[i-1]+fibword[i-2];
        fib[i] = fib[i-1]+fib[i-2];
        i++;
        n_prepare++;
    }
}
ll count(string s, string p) {
    int len = p.length();
    ll res = 0;
    for(int i = 0; i < s.length()-len+1; ++i) {
        if(s.substr(i, len) == p)
            res++;
    }
    return res;
}
ll count(int n, string p) {
    if(c[n] < 0) {
        c[n] = count(n-1, p)+count(n-2, p)+mc[n%2];
    }
    return c[n];
}
ll solve(int n, string p) {
    int lp = p.size();
    if(n < n_prepare && fib[n] < lp)
        return 0;
    for(int j = 0; j <= n; ++j)
        c[j] = -1;
    int i = 1;
    while(fib[i-1] < lp)
        i++;
    c[i-1] = count(fibword[i-1], p);
    c[i] = count(fibword[i], p);
    string x = fibword[i].substr(0, lp-1);
    string a = fibword[i-1].substr(fibword[i-1].size()-(lp-1));
    string b = fibword[i].substr(fibword[i].size()-(lp-1));
    mc[i%2] = count(a+x, p);
    mc[(i+1)%2] = count(b+x, p);
    return count(n, p);
}
int main()
{
    int i = 0;
    preprocessing();
    while(cin >> n) {
        i++;
        cin >> p;
        cout << "Case " << i << ": " << solve(n, p) << "\n";
    }
}