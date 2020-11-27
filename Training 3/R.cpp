#include <bits/stdc++.h>

using namespace std;
int n, a[10005];
string s;
int main()
{
    cin >> n;
    cin >> s;
    int k = n-1;
    while(k >= 0) {
        if(s[k] == '0') {
            s[k] = '1';
            break;
        }
        else {
            s[k] = '0';
            k--;
        }
    }
    if(k < 0) cout << "-1";
    else cout << s;
    return 0;
}
