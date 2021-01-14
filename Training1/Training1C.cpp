#include <iostream>

using namespace std;

int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    a = a%1000000007;
    b = b%1000000007;
    long long ans = (a+b)%1000000007;
    cout << ans;
    return 0;
}