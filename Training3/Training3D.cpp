#include <bits/stdc++.h>
using namespace std;
int n, k; // số địa điểm và số người tối đa
int carry; // biến lưu số người đang được chở
int visit[25]; // mảng đánh dấu các điểm đã ghé thăm
int go[25]; // mảng lưu các vị trí đã đi qua
int cmin = 10000000, ans = 10000000, sum = 0;
int a[25][25]; // mảng lưu chi phí
void Try(int x) {
    if(x == 2*n+1) {
        ans = min(ans, sum+a[go[x-1]][0]);
    }
    else {
        // nếu có hành khách trên xe
        if(carry > 0) {
            // đưa 1 hành khách sang vị trí i+k
            for(int i = n+1; i <= 2*n; ++i) {
                if(visit[i-n] == 1 && visit[i] == 0) {
                    visit[i] = 1;
                    go[x] = i;
                    sum = sum+a[go[x-1]][go[x]];
                    int t = carry;
                    carry--;
                    if(sum+(2*n-x+1)*cmin < ans) Try(x+1);
                    visit[i] = 0;
                    sum = sum-a[go[x-1]][go[x]];
                    carry = t;
                }
            }
            // nếu số hành khách chưa vượt quá k thì chọn 1 địa điểm trong n điểm đầu tiên
            if(carry < k) {
                for(int i = 1; i <= n; ++i) {
                    if(visit[i] == 0) {
                        visit[i] = 1;
                        go[x] = i;
                        sum = sum+a[go[x-1]][go[x]];
                        int t = carry;
                        carry++;
                        if(sum+(2*n-x+1)*cmin < ans) Try(x+1);
                        visit[i] = 0;
                        sum = sum-a[go[x-1]][go[x]];
                        carry = t;
                    }
                }
            }
        }
        // nếu không có hành khách nào thì phải chở người trong n điểm đầu tiên
        else {
            for(int i = 1; i <= n; ++i) {
                if(visit[i] == 0) {
                    visit[i] = 1;
                    go[x] = i;
                    sum = sum+a[go[x-1]][go[x]];
                    int t = carry;
                    carry++;
                    if(sum+(2*n-x+1)*cmin < ans) Try(x+1);
                    visit[i] = 0;
                    sum = sum-a[go[x-1]][go[x]];
                    carry = t;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < 25; ++i)
        visit[i] = 0;
    for(int i = 0; i < 2*n+1; ++i)
        for(int j = 0; j < 2*n+1; ++j) {
            cin >> a[i][j];
            if(i != j) cmin = min(cmin, a[i][j]);
        }
    // lần lượt cho xe xuất phát từ 1 trong n điểm đầu tiên
    for(int i = 1; i <= n; ++i) {
        go[1] = i;
        visit[i] = 1;
        carry = 1;
        sum = a[0][i];
        Try(2);
        visit[i] = 0;
        carry = 0;
    }
    cout << ans;
    return 0;
}