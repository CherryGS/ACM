#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll a, b, c;

ll q[10], cnt;
bool vis[10];
bool flag;

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x%y);
}

void sol() {
    ll s[3];
    for(int i=1; i<=9; i+=3) {
        s[i/3] = 100*q[i]+10*q[i+1]+q[i+2];
    }
    ll r = gcd(a, b), rr = gcd(s[0], s[1]);
    if(a/r != s[0]/rr || b/r != s[1]/rr) return;
    r = gcd(b, c), rr = gcd(s[1], s[2]);
    if(b/r != s[1]/rr || c/r != s[2]/rr) return;
    if(s[0] > s[1] || s[1] > s[2] || s[0] > s[2]) return;
    cout << s[0] << ' ' << s[1] << ' ' << s[2] << endl;
    flag = 1;
}

void dfs(cint step) {
    if(step == 10) {
        sol();
        return;
    }
    for(int i=1; i<=9; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            q[++cnt] = i;
            dfs(step+1);
            --cnt;
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> a >> b >> c;
    dfs(1);
    if(!flag) cout << "No!!!" << endl;
    return 0;
}