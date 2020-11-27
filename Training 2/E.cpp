#include <iostream>

using namespace std;
int t[100005];
int main()
{
    int n, q, p, c, ans = 1;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> t[i];
        if(i > 0) if(t[i] != t[i-1]) ans++;
    }
    cin >> q;
    while(q--) {
        cin >> p >> c;
        if(n == 1) cout << "1\n";
        else {
            int old = t[p-1];
            t[p-1] = c;
            if(old == c) {
                cout << ans << "\n";
                continue;
            }
            if(p == 1) {
                if(old != t[p] && c == t[p]) ans--;
                else if(old == t[p] && c != t[p]) ans++;
            }
            else if(p == n) {
                if(old != t[p-2] && c == t[p-2]) ans--;
                else if(old == t[p-2] && c != t[p-2]) ans++;
            }
            else {
                if(t[p-2] == t[p]) {
                    if(old == t[p] && c != t[p]) ans = ans+2;
                    else if(old != t[p] && c == t[p]) ans = ans-2;
                }
                else {
                    if(old == t[p-2]) {
                        if(c != t[p]) ans++;
                    }
                    else if(old == t[p]) {
                        if(c != t[p-2]) ans++;
                    }
                    else {
                        if(c == t[p-2] || c == t[p]) ans--;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
