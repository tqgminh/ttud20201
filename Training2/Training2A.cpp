#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;
long long a[MAX], p[MAX], q[MAX];
int main()
{
    int n;
    while(1) {
        cin >> n;
        if(n == 0) return 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        p[MAX] = {0}, q[MAX] = {0};
        p[0] = 0;
        q[n-1] = n+1;
        stack<int> st1, st2;
        long long ans = 0;
        st1.push(0);
        st2.push(n-1);
        int i = 1, j = n-2;
        while(i < n) {
            if(st1.empty()) {
                p[i] = 0;
                st1.push(i);
                i++;
                continue;
            }
            else if(a[st1.top()] >= a[i]){
                st1.pop();
            }
            else {
                p[i] = st1.top()+1;
                st1.push(i);
                i++;
            }
        }
        while(j >= 0) {
            if(st2.empty()) {
                q[j] = n+1;
                st2.push(j);
                j--;
                continue;
            }
            else if(a[st2.top()] >= a[j]) {
                st2.pop();
            }
            else {
                q[j] = st2.top()+1;
                st2.push(j);
                j--;
            }
        }
        for(int i = 0; i < n; ++i)
            ans = max(ans, (q[i]-p[i]-1)*a[i]);
        cout << ans << "\n";
    }
    return 0;
}