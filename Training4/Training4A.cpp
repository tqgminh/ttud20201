#include<bits/stdc++.h>
using namespace std;
const double PI = 3.1415926;
int n, f;
double a[10005];

int mid(double m)
{
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum = floor(sum+a[i]/m);
    }
    return sum >= (f+1);
}
int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> f;
        double max_size = -1;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = a[i]*a[i]*PI;
            max_size = max(max_size, a[i]);
        }
        double l = 0, r = max_size;
        while(r-l > 1e-6) {
            double m = (l+r)/2;
            if (mid(m)) l = m;
            else r = m;
        }
        printf("%.6lf\n", l);
    }
    return 0;
}
