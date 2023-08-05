#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

int n;

int nx[300100];
int to[300100];
int he[300100];
ll w[300100];
int cnt = 0;

inline void add(cint f, cint t, cint co) {
    nx[++cnt] = he[f];
    he[f] = cnt;
    to[cnt] = t;
    w[cnt] = co;
}

void dfs(cint nod, cint fa, ll&ans, const ll& co) {
    ll mn = 0x7fffffffffffffff;
    ll sum = 0, num = 0;
    for(int i = he[nod]; i; i = nx[i]) if(to[i] != fa) {
        num++;
        mn = min(w[i], mn);
        sum += w[i];
    }
    if(!num) return;
    for(int i = he[nod]; i; i = nx[i]) 
        if(to[i] != fa) dfs(to[i], nod, ans, w[i]);
    if(!co) {
        ans += mn*(num-2) + sum;
    } else if(co <= mn) {
        ans += sum + co*num;
    } else {
        ans += co + mn;
        ans += sum + mn*(num-2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        cnt = 0;
        memset(he, 0, sizeof he);
        cin >> n;
        int a, b, c;
        for(int i = 1; i < n; i++) {
            cin >> a >> b >> c;
            add(a, b, c);
            add(b, a, c);
        }
        ll ans = 0;
        dfs(a, a, ans, 0);
        cout << ans << endl;
    }
    return 0;
}