#include <bits/stdc++.h>

using namespace std;
int n, L1, L2;
int a[1000005], F[1000005];
int main()
{
    cin >> n >> L1 >> L2;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];

    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        F[i] = a[i];
    }
    for(int i = L1; i < n; i++) {
        int j = i-L1;
        while(!dq.empty()) {
            if(F[dq.back()] <= F[j])
                dq.pop_back();
            else break;
        }
        dq.push_back(j);
        while(!dq.empty()) {
            if(dq.front() < i-L2) {
                dq.pop_front();
            }
            else break;
        }
        if(!dq.empty())
            F[i] = a[i]+F[dq.front()];
        else
            F[i] = a[i];
    }
    for(int i = 0; i < n; i++)
        ans = max(ans, F[i]);
    cout << ans;

    return 0;
}
