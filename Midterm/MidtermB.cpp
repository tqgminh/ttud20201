#include <bits/stdc++.h>
using namespace std;
int n, i, temp;
vector<int> p;
char s;
stack<int> C;
queue<int> H;
int main()
{
    cin >> n;
    for(i = 0; i < n; ++i) {
        cin >> temp;
        p.push_back(temp);
    }
    while(!p.empty()) {
        C.push(p.back());
        p.pop_back();
    }
    while(cin >> s) {
        if(s == 'C') {
            H.push(C.top());
            C.pop();
        }
        else {
            C.push(H.front());
            H.pop();
        }
        i++;
    }
    while(!C.empty()) {
        cout << C.top() << " ";
        C.pop();
    }
    return 0;
}
