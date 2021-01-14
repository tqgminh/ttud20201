#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, len;
    string str;
    cin >> t;
    while(t--) {
        stack<char> st;
        cin >> str;
        len = str.length();
        for(int i = 0; i < len; ++i) {
            if(str[i] == '(' || str[i] ==  '[' || str[i] == '{') st.push(str[i]);
            else {
                if(str[i]-st.top() != 1 && str[i]-st.top() != 2) st.push(str[i]);
                else st.pop();
            }
        }
        if(st.empty()) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}