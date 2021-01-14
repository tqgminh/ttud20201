#include <bits/stdc++.h>

using namespace std;

typedef struct pass {
    long long x, m;
} Pass;

Pass p[10050];
int main()
{
    int n;
    long long k;
    long long ans = 0;
    //long long go;
    vector<Pass> positive, negative;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].m;
    for(int i = n-1; i >= 0; i--)
        for(int j = 1; j <= i; j++)
        if(p[j-1].x > p[j].x) swap(p[j-1], p[j]);
    for(int i = 0; i < n; ++i)
        if(p[i].x >= 0) {
            if(!positive.empty()) {
                if(p[i].x == positive.back().x) positive.back().m += p[i].m;
                else positive.push_back(p[i]);
            }
            else positive.push_back(p[i]);
        }
    for(int i = n-1; i >= 0; i--)
        if(p[i].x < 0) {
            p[i].x = -p[i].x;
            if(!negative.empty()) {
                if(p[i].x == negative.back().x) negative.back().m += p[i].m;
                else negative.push_back(p[i]);
            }
            else negative.push_back(p[i]);
        }

    while(!positive.empty()) {
        int l = positive.size();
        if(l == 1) {
            if(positive.back().m%k == 0) ans = ans+2*(positive.back().m/k)*positive.back().x;
            else ans = ans+2*(positive.back().m/k+1)*positive.back().x;
            positive.pop_back();
        }
        else {
            if(positive.back().m%k == 0) {
                ans = ans+2*(positive.back().m/k)*positive.back().x;
                positive.pop_back();
                continue;
            }
            else {
                ans = ans+2*(positive.back().m/k+1)*positive.back().x;
                if(positive.at(l-2).m > k-positive.back().m%k) {
                    positive.at(l-2).m -= k-positive.back().m%k;
                    positive.pop_back();
                }
                else {
                    long long go = k-positive.back().m%k;
                    positive.pop_back();
                    while(!positive.empty()) {
                        if(go > positive.back().m) {
                            go = go - positive.back().m;
                            positive.pop_back();
                        }
                        else if(go == positive.back().m) {
                            positive.pop_back();
                            break;
                        }
                        else {
                            positive.back().m = positive.back().m-go;
                            break;
                        }
                    }
                }
            }
        }
    }
    while(!negative.empty()) {
        int l = negative.size();
        if(l == 1) {
            if(negative.back().m%k == 0) ans = ans+2*(negative.back().m/k)*negative.back().x;
            else ans = ans+2*(negative.back().m/k+1)*negative.back().x;
            negative.pop_back();
        }
        else {
            if(negative.back().m%k == 0) {
                ans = ans+2*(negative.back().m/k)*negative.back().x;
                negative.pop_back();
                continue;
            }
            else {
                ans = ans+2*(negative.back().m/k+1)*negative.back().x;
                if(negative.at(l-2).m > k-negative.back().m%k) {
                    negative.at(l-2).m -= k-negative.back().m%k;
                    negative.pop_back();
                }
                else {
                    long long go = k-negative.back().m%k;
                    negative.pop_back();
                    while(!negative.empty()) {
                        if(go > negative.back().m) {
                            go = go - negative.back().m;
                            negative.pop_back();
                        }
                        else if(go == negative.back().m) {
                            negative.pop_back();
                            break;
                        }
                        else {
                            negative.back().m = negative.back().m-go;
                            break;
                        }
                    }
                }
            }
        }
    }
    /*for(int i = 0; i < positive.size(); i++)
        cout << positive.at(i).x << " " << positive.at(i).m << "\n";*/
    cout << ans;
    return 0;
}