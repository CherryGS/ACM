#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int q;

bool check(int f, int t) {
    if(f > t) return 0;
    if(f == t) return 1;

    int r = 0, s = 0;
    while(t) {
        if(f) {
            if(!(f&1)) -- r;
            else -- s;
            f >>= 1;
        }
        if(!(t&1)) ++ r;
        else ++ s;
        t >>= 1;
        if(r < 0) return 0;
    }
    if(s > 0) return 0;
    return 1;
}

int main() {
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        if(check(u, v)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}