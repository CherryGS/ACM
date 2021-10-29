#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t, n;
ll sum[200200];
ll tmp[200200];

struct stu {
    ll a, b;
    bool operator < (const stu&ab) const {
        return a < ab.a;
    }
    void init() {
        cin >> a >> b;
    }
}f[200200];

ll cacu() {
    int key = lower_bound(tmp+1, tmp+1+n, 0) - tmp;
    // cout << endl;
    // for(int i=1; i<=n; i++) cout << tmp[i] << ' ';
    // cout << endl;
    // cout << key << "---" << tmp[key-1] << endl;
    return min(f[key].a, sum[n]-sum[key-1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> f[i].a;
        for(int i=1; i<=n; i++) cin >> f[i].b;
        sort(f+1, f+1+n);
        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + f[i].b;
        for(int i=1; i<=n; i++) tmp[i] = f[i].a-sum[n]+sum[i];
        cout << cacu() << endl;
    }
    return 0;
}