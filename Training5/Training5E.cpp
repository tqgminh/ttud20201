#include <bits/stdc++.h>
#define MAX 2000006
using namespace std;
int n, mem[MAX];
pair<int, int> st[MAX];
int F[MAX];
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second < b.second)
        return true;
    else if(a.second == b.second) {
        if(a.first < b.first)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d",&st[i].first, &st[i].second);
    sort(st, st+n, compare);
    int j = 0;
    for(int i = 1; i <= st[n-1].second; i++) {
        F[i] = F[i-1];
        while(st[j].second <= i) {
            F[i] = max(F[i], st[j].second-st[j].first);
            j++;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, st[i].second-st[i].first+F[st[i].first-1]);
    }
    printf("%d", ans);
    return 0;
}
