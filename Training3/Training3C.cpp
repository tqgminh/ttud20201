#include <bits/stdc++.h>
using namespace std;
int m; // so giang vien
int n; // so mon hoc
int a; // bien luu cac mon hoc co the day
int ans = 30;
int posteach[50][50]; // pos[i][j] = 1 giang vien i co the day mon j
vector<int> teach[50]; // tong so mon giang vien i day
int course[50][50]; // course[i][j] = 1 mon i va j khong cung 1 giang vien day
int k;
int x, y;

int numberEmpty(int m) {
    int res = 0;
    for(int i = 1; i <= m; ++i)
        if(teach[i].empty()) res++;
    return res;
}

//kiem tra xem giang vien m co day 2 mon khong hop le khong
bool test(int m, int i) {
    for(int u = 0; u < teach[m].size(); ++u)
        if(course[teach[m].at(u)][i] == 1) return false;
    return true;
}
// k la mon hoc thu k dang xet
void Try(int k) {
    if(k == n+1) {
        if(numberEmpty(m) == 0) {
            int res = 0;
            for(int i = 1; i <= m; ++i)
                res = max(int(teach[i].size()), res);
            ans = min(res, ans);
        }
    }
    else {
        for(int i = 1; i <= m; ++i) {
            if(posteach[i][k] == 1 && test(i, k)) {
                teach[i].push_back(k);
                if(teach[i].size() < ans) Try(k+1);
                teach[i].pop_back();
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; ++i) {
        cin >> k;
        for(int j = 0; j < k; ++j) {
            cin >> a;
            posteach[i][a] = 1;
        }
    }
    cin >> k;
    for(int i = 0; i < k; ++i) {
        cin >> x >> y;
        course[x][y] = 1;
        course[y][x] = 1;
    }
    Try(1);
    cout << ans;
    return 0;
}