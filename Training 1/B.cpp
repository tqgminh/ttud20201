#include <iostream>
#include <float.h>
using namespace std;

long long a[1000009];
int maxLeft(long long a[], int i, int j) {
    long long maxSum = LLONG_MIN, sum = 0;
    for(int k = j; k >= i; k--) {
        sum = sum+a[k];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int maxRight(long long a[], int i, int j) {
    long long maxSum = LLONG_MIN, sum = 0;
    for(int k = i; k <= j; k++) {
        sum = sum+a[k];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int maxSub(long long a[], int i, int j) {
    if(i == j) return a[i];
    else {
        int m = (i+j)/2;
        long long wL = maxSub(a, i, m);
        long long wR = maxSub(a, m+1, j);
        long long wM = maxLeft(a, i, m)+maxRight(a, m+1, j);
        return max(wL, max(wR, wM));
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxSub(a, 0, n-1);
    return 0;
}
