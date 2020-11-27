#include <bits/stdc++.h>

using namespace std;
int a[104], n;
stack<int> positive, negative, zero;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) negative.push(a[i]);
        else if(a[i] > 0) positive.push(a[i]);
        else zero.push(a[i]);
    }
    if(negative.size()%2 == 1) {
        if(positive.empty()) {
            positive.push(negative.top());
            negative.pop();
            positive.push(negative.top());
            negative.pop();
            cout << negative.size() << " ";
            while(!negative.empty()) {
                cout << negative.top() << " ";
                negative.pop();
            }
            cout << "\n";
            cout << positive.size() << " ";
            while(!positive.empty()) {
                cout << positive.top() << " ";
                positive.pop();
            }
            cout << "\n";
            cout << zero.size() << " ";
            while(!zero.empty()) {
                cout << zero.top() << " ";
                zero.pop();
            }
        }
        else {
            cout << negative.size() << " ";
            while(!negative.empty()) {
                cout << negative.top() << " ";
                negative.pop();
            }
            cout << "\n";
            cout << positive.size() << " ";
            while(!positive.empty()) {
                cout << positive.top() << " ";
                positive.pop();
            }
            cout << "\n";
            cout << zero.size() << " ";
            while(!zero.empty()) {
                cout << zero.top() << " ";
                zero.pop();
            }
        }
    }
    else {
        if(positive.empty()) {
            positive.push(negative.top());
            negative.pop();
            positive.push(negative.top());
            negative.pop();
            zero.push(negative.top());
            negative.pop();
            cout << negative.size() << " ";
            while(!negative.empty()) {
                cout << negative.top() << " ";
                negative.pop();
            }
            cout << "\n";
            cout << positive.size() << " ";
            while(!positive.empty()) {
                cout << positive.top() << " ";
                positive.pop();
            }
            cout << "\n";
            cout << zero.size() << " ";
            while(!zero.empty()) {
                cout << zero.top() << " ";
                zero.pop();
            }
        }
        else {
            zero.push(negative.top());
            negative.pop();
            cout << negative.size() << " ";
            while(!negative.empty()) {
                cout << negative.top() << " ";
                negative.pop();
            }
            cout << "\n";
            cout << positive.size() << " ";
            while(!positive.empty()) {
                cout << positive.top() << " ";
                positive.pop();
            }
            cout << "\n";
            cout << zero.size() << " ";
            while(!zero.empty()) {
                cout << zero.top() << " ";
                zero.pop();
            }
        }
    }
    return 0;
}
