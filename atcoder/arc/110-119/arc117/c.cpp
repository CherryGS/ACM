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

const int mod = 3;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll a[400400];
ll jie[400400];
int st = 1;

void init() {
    jie[0] = 1;
    for(int i=1; i<=400000; i++)
        jie[i] = (jie[i-1]*i) % mod;
}

ll C(cint x, cint y) {
    if(x == 0) return 1;
    return (jie[y]*(jie[x]*jie[y-x])) % mod;
}

int main() {
    init();
    cin >> n;
    char s;
    if(!(n&1)) st = -1;
    for(int i=1; i<=n; i++) {
        cin >> s;
        if(s == 'B') a[i] = 0;
        else if(s == 'W') a[i] = 1;
        else a[i] = 2;
    }
    ll pre = 0;
    for(int i=1; i<=n; i++) {
        pre = (pre + C(i-1, n-1) * a[i] * st);
    }
    pre = (pre+n*mod) % mod;
    if(pre == 0) cout << "B" << endl;
    else if(pre == 1) cout << "W" << endl;
    else if(pre == 2) cout << "R" << endl;
    return 0;
}