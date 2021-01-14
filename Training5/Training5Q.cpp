#include <bits/stdc++.h>

using namespace std;
int n, m;
int x[10005], y[10005];
int lcs[10005][10005];
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < m; i++)
        cin >> y[i];
    for(int i = 0; i < n; i++) {
        if(x[i] == y[0])
            lcs[i][0] = 1;
    }
    for(int j = 0; j < m; j++) {
        if(y[j] == x[0])
            lcs[0][j] = 1;
    }
        lcs[0][0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            if(x[i] == y[j])
                lcs[i][j] = max(lcs[i][j], lcs[i-1][j-1]+1);
        }
    }
    cout << lcs[n-1][m-1];
    return 0;
}
