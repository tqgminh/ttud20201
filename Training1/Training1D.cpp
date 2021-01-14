#include <iostream>

using namespace std;

unsigned long long mod(unsigned long long a, unsigned long long b) {
    if(b == 0)
        return 1;
    else if(b == 1)
        return a%1000000007;
    else {
        if(b%2 == 0) {
            unsigned long long x = mod(a, b/2)%1000000007;
            return (x*x)%1000000007;
        }
        else {
            unsigned long long x = mod(a, b/2)%1000000007;
            return (((x*x)%1000000007)*a)%1000000007;
        }
    }
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    a = a%1000000007;
    cout << mod(a, b);
    return 0;
}