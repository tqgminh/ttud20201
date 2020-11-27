#include <bits/stdc++.h>
using namespace std;
int n, c;
int x[100005];

int check(int m, int n) {
    int count = 1;
    int before = 0;
    int i = 0;
    while(i < n) {
        if(x[i]-x[before] >= m) {
            before = i;
            count++;
        }
        i++;
    }
    return count >= c;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &c);
        for(int i = 0; i < n; ++i)
            scanf("%d", &x[i]);
        sort(x, x+n);
        int l = 0;
        int r = x[n-1];
        int m;
        while(r-l > 1) {
            m = (l+r)/2;
            if(check(m, n))
                l = m;
            else
                r = m;
        }
        printf("%d\n", l);
        //cout << check(3, n);
    }
    return 0;
}
