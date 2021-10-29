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
int h[100100], nx[200200], to[200200], ct;
int siz[100100];
int q[100100], cnt;

void add(cint f, cint t) {
    nx[++ct] = h[f];
    h[f] = ct;
    to[ct] = t;
}

int dfs(cint loc, cint fa) {
    int r= -111;
    int ans = -1, oth = 0;
    vector<int > d;
    for(int i=h[loc]; i; i = nx[i])
        if(to[i] != fa) {
            r = dfs(to[i], loc);
            siz[loc] += siz[to[i]];
            if(!(siz[to[i]] & 1) && r > 0) ans += r;
            else if(!(siz[to[i]] & 1) && r < 0) oth += r;
            else if((siz[to[i]] & 1)) d.push_back(r);
        }
    int nt = d.size();
    for(int i=0; i<nt; i++) q[i+1] = d[i];
    sort(q+1, q+1+nt);
    for(int i=nt; i>=1; i--)
        if(!((nt-i) & 1)) ans += q[i];
        else ans -= q[i];
    if(nt & 1) ans -= oth;
    else ans += oth;
    return ans;
}

int main() {
    cin >> n;
    int r;
    for(int i=2; i<=n; i++) {
        cin >> r;
        add(r, i);
        add(i, r);
        siz[i] = 1;
    }
    cout << (n-dfs(1, 1))/2 << endl;
    return 0;
}
/*
3
1 2
*/