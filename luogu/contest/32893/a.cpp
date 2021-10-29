#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

int n, loc, d;

int main() {
    ios::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> d;
        if(d == 1 && !loc) {
            loc = i;
        }
    }
    int l, r;
    while(q--) {
        cin >> l >> r;
        if(l <= loc && r >= loc) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}