#include <bits/stdc++.h>
using namespace std;
int t, n, money, ans = 0;
int main()
{
    //cin >> t;
    //while(t--) {
        cin >> n;
        ans = 0;
        money = 1000-n;
        while(money > 0) {
            if(money >= 500) {
                ans += money/500;
                money = money%500;
            }
            else if(money >= 100) {
                ans += money/100;
                money = money%100;
            }
            else if(money >= 50) {
                ans += money/50;
                money = money%50;
            }
            else if(money >= 10) {
                ans += money/10;
                money = money%10;
            }
            else if(money >= 5) {
                ans += money/5;
                money = money%5;
            }
            else {
                ans += money;
                money = 0;
            }
        }
        cout << ans;
    //}
    return 0;
}
