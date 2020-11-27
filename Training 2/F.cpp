#include <bits/stdc++.h>

using namespace std;

long long a[200006];
int b, n;

int maxRight(int i, int j) {
    if(i >= j) return i;
    int ans = i;
    for(int k = i+1; k <= j; k++)
        if(a[k] > a[ans]) ans = k;
    return ans;
}
int maxLeft(int i, int j) {
    if(i >= j) return j;
    int ans = j;
    for(int k = j-1; k >= i; k--)
        if(a[k] > a[ans]) ans = k;
    return ans;
}
int minIndex(int i, int j) {
    int ans = i;
    for(int k = i+1; k <= j; k++)
        if(a[k] < a[ans]) ans = k;
    return ans;
}

long long f(int i, int j) {
    if(i-j >= -1) return -1;
    else {
        //int m = (i+j)/2;
        int m = i+1;
        for(int k = i+1; k < j; k++)
            if(a[k] < a[m]) m = k;
        //int m = minIndex(i, j);
        long long left = f(i, m-1);
        long long right = f(m+1, j);
        long long mid;
        int maxL = maxRight(i, m-1);
        int maxR = maxLeft(m+1, j);
        long long mL = a[maxL];
        long long mR = a[maxR];
        long long mM = a[m];
        if(mL-mM >= b && mR-mM >= b)
            mid = mL-mM+mR-mM;
        else mid = -1;
        return max(max(left, right), mid);
    }
}

int main()
{
    //int n;
    cin >> n >> b;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    cout << f(0, n-1);
    return 0;
}
