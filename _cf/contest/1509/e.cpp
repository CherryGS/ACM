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

int t;
ull n, k;
int q[100100], cnt;
int sta[100100], ct;

void sol(int l, ull x) {
    cnt = ct = 0;
    while(x) {
        if(x >= (1ull<<l)) {
            x -= (1ull<<l);
            q[++cnt] = n-l-1;
        }
        --l;
    }
    int s = 1;
    for(int i=1; i<=n; i++) {
        if(s <= cnt && q[s] == i) {
            sta[++ct] = i;
            ++s;
        } else {
            cout << i << ' ';
            while(ct) { cout << sta[ct--] << ' '; }
        }
    }
    cout << endl;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int l = 0;
        while((1ull<<l) <= k) { ++l; }
        --l; --k;
        // cout << n << ' ' << k << ' ' << l << ' ' << endl;
        if(n<=64 && k+1 > (1ull<<(n-1))) cout << -1 << endl;
        else sol(l, k);
    }
    return 0;
}
/*
1
3 4
*/