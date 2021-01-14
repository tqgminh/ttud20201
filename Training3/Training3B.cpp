#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0, v[1000], m[1000], sum = 0, vol = 0, b;
double maxAVW = 0.0; // lưu trọng lượng trung bình lớn nhất
void Try(int x)
{
	if(x == n) {
        ans = max(sum, ans);
	}
	else {
        Try(x+1);
        if(vol+v[x] <= b) {
            vol = vol+v[x];
            sum = sum+m[x];
            if(sum+maxAVW*(b-vol) >= ans) Try(x+1);
            vol = vol-v[x];
            sum = sum-m[x];
        }
	}
}
int main()
{
	cin >> n >> b;
	for(int i = 0; i < n; i++) {
	    cin >> v[i] >> m[i];
	    maxAVW = max(maxAVW, (double) m[i]/v[i]);
	}
	Try(0);
	cout << ans;
}