#include <bits/stdc++.h>
using namespace std;
int p1, p2, c, ok[1000][1000], a[100000][2];
long long ans = LLONG_MAX;
void Try(long long x, int h1, int h2)
{
	if(h1 == c || h2 == c) {
        ans = min(ans, x);
        ok[h1][h2] = 0;
        return;
	}
	else {
		if(ok[h1][h2] == 0) {
            ok[h1][h2] = 1;
			Try(x+1, p1, h2);
			ok[h1][h2] = 0;
		}
		if(ok[h1][h2] == 0) {
            ok[h1][h2] = 1;
			Try(x+1, h1, p2);
			ok[h1][h2] = 0;
		}
		if(ok[h1][h2] == 0) {
            ok[h1][h2] = 1;
            if(h1+h2 <= p2) Try(x+1, 0 , h1+h2);
			else Try(x+1, h1+h2-p2, p2);
			ok[h1][h2] = 0;
		}
		if(ok[h1][h2] == 0) {
            ok[h1][h2] = 1;
			if(h1+h2 <= p1) Try(x+1, h1+h2, 0);
			else Try(x+1, p1, h1+h2-p1);
			ok[h1][h2] = 0;
		}
		if(ok[h1][h2] == 0) {
            ok[h1][h2] = 1;
			Try(x+1, 0, h2);
			ok[h1][h2] = 0;
		}
		if(ok[h1][h2] == 0) {
            ok[h1][h2] = 1;
			Try(x+1, h1, 0);
			ok[h1][h2] = 0;
		}
	}
}
int main()
{
	cin >> p1 >> p2;
	cin >> c;
	Try(0, 0, 0);
	if(ans == LLONG_MAX) cout << "-1";
	else cout << ans;
	return 0;
}
