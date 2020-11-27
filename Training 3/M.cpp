#include <iostream>

using namespace std;
int n, q = 0, a[10], ok[10];
void Try(int k) {
    if(k == 7) {
        int m = a[0]*100+a[1]*10+a[2]-a[3]*100+a[4]*1000+a[5]*100+a[6]*10+a[2];
        if(m == n+62) q++;
    }
    else {
        for(int i = 1; i <= 9; ++i) {
            if(ok[i] == 0) {
                ok[i] = 1;
                a[k] = i;
                Try(k+1);
                ok[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    Try(0);
    cout << q;
    return 0;
}
