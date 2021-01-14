#include <iostream>

using namespace std;

int a[1000008];
int main()
{
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum = (sum+a[i])%1000000007;
    }
    cout << sum;
    return 0;
}