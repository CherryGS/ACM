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

int n;
int h[200200], nx[400400], to[400400], cnt;
int fib[1000];
bool flag, ed;
bool mp[200200];
int nrt;

void add(cint f, cint t) {
    nx[++cnt] = h[f];
    h[f] = cnt;
    to[cnt] = t;
}

void init() {
    int i=3;
    fib[1] = fib[2] = 1;
    while(fib[i-1]<=2e5) {
        fib[i] = fib[i-1] + fib[i-2];
        ++i;
    }
    // cout << fib[i-1] << endl;
}

int dfs(cint loc, cint fa,int & r) {
    int sum=1;
    for(int i=h[loc]; i; i=nx[i])
        if(to[i] != fa && mp[to[i]] == mp[loc]) {
            sum += dfs(to[i], loc, r);
            if(r <= 4 || flag) return 0;
        }
    if(r <= 4 || flag) return 0;
    mp[loc] ^= 1;
    if(sum > fib[r-1]) {
        if(n==121393) cout << loc << ' ' << sum << ' ' << fa << ' ' << r << endl;
        flag = 1;
        return 0;
    } 
    if(sum == fib[r-1]) {
        int rr = r-1;
        r -= 2;
        dfs(loc, fa, rr);
        return 0;
    }
    if(sum == fib[r-2]) {
        int rr = r-2;
        r -= 1;
        dfs(loc, fa, rr);
        return 0;
    }
    return sum;
}

int main() {
    init();
    cin >> n;
    int u, v;
    for(int i=1; i<n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    int r=1;
    while(fib[r] && fib[r] != n) ++r;
    if(!fib[r]) cout << "No" << endl;
    else if(r <= 4) cout << "Yes" << endl;
    else {
        dfs(1, 1, r);
        if(flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}