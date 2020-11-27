#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long h[n], s[n];
    long long max = 0, ans = 0;
    long long begin, end, mid;
    long long cutted;
    for (long long i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > max) {
            max = h[i];
        }
    }
    begin = 0;
    end = max;
    sort(h, h+n);
    for(int i = n-1; i >= 0; --i)
        s[i] = s[i+1]+h[i];
    while (begin <= end) {
        mid = (begin+end)/2;
        cutted = 0;
        for (long long i = 0; i < n; ++i) {
            if (h[i]-mid > 0) {
                cutted += h[i]-mid;
            }
        }
        if (cutted > m) {
            begin = mid+1;

        }
        else if(cutted < m) {
            end = mid-1;
        }
        else {
            ans = mid;
            break;
        }
    }
    cout << ans;
    return 0;
}
