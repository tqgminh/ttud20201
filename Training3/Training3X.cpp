#include <iostream>

using namespace std;
int n, k;
long long d[1004][1004];
long long C(int k, int n) {
    if(d[n][k] > 0) return d[n][k]%(1000000000+7);
    else {
        long long a = C(k-1, n-1)%(1000000000+7);
        long long b = C(k, n-1)%(1000000000+7);
        d[n][k] = (a+b)%(1000000000+7);
        return d[n][k];
    }
}
int main()
{
    cin >> k >> n;
    for(int i = 0; i < 1004; ++i) {
        d[i][0] = 1;
        d[i][i] = 1;
    }
    cout << C(k, n);
    return 0;
}