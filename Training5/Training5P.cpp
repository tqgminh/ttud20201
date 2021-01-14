#include <bits/stdc++.h>
 
using namespace std;
int n, a[10005];
int mem[10005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        mem[i] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                mem[i] = max(mem[i], mem[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, mem[i]);
    cout << ans;
    return 0;
}