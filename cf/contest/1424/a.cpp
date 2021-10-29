#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

priority_queue<int, vector<int>, greater<int>> s, d;

int main() {
    int n, b, de;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> b >> de;
        s.push(b);
        d.push(de);
    }
    int ans = 0, key;
    int now = 0;
    while(!s.empty()) {
        int a1 = s.top();
        int a2 = d.top();
        if(a1 < a2) {
            now++;
            s.pop();
        }
        else if(a1 == a2) {
            s.pop();
            d.pop();
        }
        else {
            now--;
            d.pop();
        }
        if(ans < now) {
            ans = now;
            key = a1;
        }
    }

    cout << key << ' ' << ans;
    return 0;
}