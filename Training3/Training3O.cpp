#include <bits/stdC++.h>

using namespace std;
typedef unsigned long long ull;
int n;
ull k;
ull gt[10004];
int index[10004];
vector<int> show;

// gán thứ tự cho số i
void Init() {
    for(int i = 1; i <= n; ++i)
        index[i] = i;
}

// xóa số k khỏi tập hợp các số
void deleteIndex(int k) {
    for(int i = k; i < n; ++i)
        index[i] = index[i+1];
    n--;
}

// tính giai thừa
void fact() {
    gt[0] = 1;
    for(int i = 1; i <= 20; ++i)
        gt[i] = i*gt[i-1];
}

void run() {
    int x = 1;
    // trường hợp n lớn thì chữ số đầu mặc định là 1 do k < n!
    while (n > 13) {
        show.push_back(index[x]);
        deleteIndex(x);
    }
    while(n > 0) {
        x = k/gt[n-1];
        if(k%gt[n-1] != 0) x++;
        if(index[x] == 0) {
            cout << "-1";
            return;
        }
        show.push_back(index[x]);
        k = k-(x-1)*gt[n-1];
        deleteIndex(x);
    }
}

int main()
{
    cin >> n >> k;
    Init();
    fact();
    run();
    for(int i = 0; i < show.size(); i++)
        cout << show.at(i) << " ";
    return 0;
}
