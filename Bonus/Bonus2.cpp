#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005];
long long mem[100005];
bool comp[100005];
int len = 0;

long long solve(int x) {
    if(x < 0) return 0;
    if(x == 0) {
        mem[0] = a[0];
        return a[0];
    }
    if(comp[x]) {
        return mem[x];
    }
    long long ans = max(solve(x-1), solve(x-2)+a[x]);
    ans = max(ans, a[x]);
    mem[x] = ans;
    comp[x] = true;
    return ans;
}

void trace(int i) {
    if(i < 0) {
        cout << len << "\n";
        return;
    }
    if(i == 0) {
        cout << len+1 << "\n";
        cout << 1 << " ";
        return;
    }

    if(mem[i] == mem[i-1]) {
        trace(i-1);
    }
    else if(mem[i] == mem[i-2]+a[i]) {
        len++;
        trace(i-2);
        cout << i+1 << " ";
    }
    else {
        cout << len+1 << "\n";
        cout << i+1 << " ";
        return;
    }
}

int main()
{
    memset(comp, 0, sizeof(comp));
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(solve(n-1) <= 0) {
        cout << "0\n0\n0";
        return 0;
    }
    cout << solve(n-1) << "\n";
    //cout << len+1 << "\n";
    trace(n-1);
    return 0;
}
