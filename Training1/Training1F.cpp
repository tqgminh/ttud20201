#include <iostream>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    while(n--) {
        cin >> str;
        int len = str.length();
        if(len <= 10)
            cout << str << "\n";
        else {
            cout << str[0] << len-2 << str[len-1] << "\n";
        }
    }
    return 0;
}