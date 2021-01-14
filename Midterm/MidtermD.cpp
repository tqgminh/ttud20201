#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[100005];
double sumk[100005];
int numele[100005];
int main()
{
    double seqmx = -1e5;
    double sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i) {
        if(i < k-1) {
            sum += a[i];
            sumk[i] = 0;
        }
        else if(i == k-1) {
            sumk[i] = sum;
            numele[i] = k;
        }
        else {
            sum = sum-a[i-k]+a[i];
            sumk[i] = sum;
            numele[i] = k;
        }
    }
    for(int i = k; i < n; ++i) {
        if((sumk[i-1]+a[i])/(numele[i-1]+1) >= sumk[i]/numele[i]) {
            sumk[i] = sumk[i-1]+a[i];
            numele[i] = numele[i-1]+1;
        }
    }
    for(int i = k-1; i < n; ++i)
        seqmx = max(sumk[i]/numele[i], seqmx);
    cout << seqmx;
    return 0;
}
