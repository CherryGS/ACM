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

int n, qq;
int a[100100];
int mp[100100];
int to[20][100100];
int val[100100];
int pre[21];

map<int, int> e;

int gcd(cint x, cint y) {
    return y == 0 ? x : gcd(y, x%y);
}

void init() {
    for(int i=2; i<=100000; i++) {
        if(!mp[i]) {
            e[i] = 0;
            for(int j=2; i*j <= 100000; j++)
                mp[i*j] = i;
            mp[i] = i;
        }
    }
    pre[0] = 1;
    for(int i=1; i<=19; i++) pre[i] = pre[i-1] * 2;
}

int q[10010], cnt;

bool sol(int x) {
    if(x == 1) return 1;
    cnt = 0;
    bool flag = 1;
    while(x != 1) {
        int r = mp[x];
        // cout << x << "---" << r << endl;
        x /= r;
        if(e[r] >= 1) return 0;
        q[++cnt] = r;
    }
    while(cnt) { ++e[q[cnt--]]; }
    return 1;
}

void del(int x) {
    while(x != 1) {
        int r = mp[x];
        x /= r;
        --e[r];
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    cin >> n >> qq;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        if(!sol(a[i])) {
            to[0][1] = i-1;
            break;
        } else if(i == n) to[0][1] = n;
    }
    for(int i=2; i<=n; i++) {
        int s = to[0][i-1];
        del(a[i-1]);
        while(s < n && sol(a[s+1])) { ++s; }
        to[0][i] = s;
    }
    // for(int i=1; i<=n; i++) cout << to[0][i] << ' ';
    // cout << endl;

    for(int j=1; j<=19; j++) {
        for(int i=1; i<=n; i++) {
            if(to[j-1][i] == n) to[j][i] = n;
            else to[j][i] = to[j-1][to[j-1][i]+1];
        }
    }

    int l, r;
    for(int i=1; i<=qq; i++) {
        cin >> l >> r;
        int s = 19, num = 0;
        for(s; s>=0; s--) {
            // cout << l << ' ' << r << ' ' << s << ' ' << to[s][l] << endl;
            if(to[s][l] < r && to[s][l]) {
                l = to[s][l]+1;
                num += pre[s];
            }
        }
        cout << num+1 << endl;
    }
    return 0;
}
/*
5 1
1 5 5 3 1 
2 3
*/