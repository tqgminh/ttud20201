#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m, k;
ll p[505], b[505], valid_b[505];
bool check(ll mid) {
   for(int i = 0; i < k; i++)
        b[i] = i;
   b[k] = m;
   for(int i = k-1; i >= 0; i--) {
       ll sum = 0, t = b[i];
       for(ll j = b[i+1]-1; j >= t; j--) {
            sum += p[j];
            if(sum == mid) {
                b[i] = j;
                break;
            }
            else if(sum > mid) {
                b[i] = j+1;
                break;
            }
       }
   }
   if(b[0] > 0)
        return false;
   return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        ll high = 0, low = 0;
        cin >> m >> k;
        for(int i = 0; i < m; i++) {
            cin >> p[i];
            high += p[i];
            low = max(low, p[i]);
        }
        while(low < high) {
            ll mid = (low+high)/2;
            if(check(mid)) {
                high = mid;
                for(int i = 0; i < k; ++i)
                    valid_b[i] = b[i];
            }
            else
                low = mid+1;
        }
        for(int i = 0; i < k-1; i++) {
            for(int j = valid_b[i]; j < valid_b[i+1]; j++)
                cout << p[j] << " ";
            cout << "/ ";
        }
        for(int i = valid_b[k-1]; i < m; i++) {
            cout << p[i];
            if(i == m-1)
                break;
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}