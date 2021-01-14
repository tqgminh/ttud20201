#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e17;
unsigned long long a, b;
int main()
{
    cin >> a >> b;
    int a1 = a/MAX, b1 = b/MAX;
    unsigned long long a2 = a%MAX, b2 = b%MAX;
    int f = a1+b1+(a2+b2)/MAX;
    unsigned long long s = (a2+b2)%MAX;
    if(f > 0) {
        cout << f;
        if(s == 0) {
            cout << "00000000000000000";
            return 0;
        }
        int no = int(log10(s))+1;
        for(int i = 1; i <= 17-no; i++)
            cout << "0";
        cout << s;
    }
    else {
        cout << s;
    }
    return 0;
}

