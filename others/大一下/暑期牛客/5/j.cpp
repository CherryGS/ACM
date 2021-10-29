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

struct stu {
    int x, y, z, v;
    bool operator < (const stu&a) const {
        return v == a.v ? z > a.z : v > a.v;
    }
    void init() {
        cin >> x >> y >> z >> v;
    }
} s[303];

ll cacu(ll v, ll t, ll z) {
    return 2*t*v*z + t*t*v*v;
}

ll cacu1(cint x) {
    return pow(s[x].x, 2) + pow(s[x].y, 2) + pow(s[x].z, 2);
}

bool check(cint x, cint y, cint i) {
    return cacu(s[x].v, i, s[x].z)+cacu(s[y].v, i-1, s[y].z) >= cacu(s[x].v, i-1, s[x].z)+cacu(s[y].v, i, s[y].z);
}

void debug() {
    for(int i=1; i<=n; i++)
        cout << s[i].v << ' ' << s[i].z << endl;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) s[i].init();
    sort(s+1, s+1+n);
    for(int i=2; i<=n; i++) {
        for(int j=i-1; j; j--) {
            if(check(j+1, j, i-1)) {
                swap(s[j+1], s[j]);
            } else { break; }
        }
    }
    // debug();
    ll ans = 0;
    for(int i=1; i<=n; i++)
        ans += cacu(s[i].v, i-1, s[i].z) + cacu1(i);
    cout << ans << endl;
    return 0;
}