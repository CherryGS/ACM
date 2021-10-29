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
#define lson (loc<<1)
#define rson ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

struct tree {
    int node[200200<<5];
    int lowbit(cint x) { return x&-x; }
    void add(int x, int y, cint lim, cint co) {
        ++y;
        while(x <= lim) {
            node[x] += co;
            x += lowbit(x);
        }
        while(y <= lim) {
            node[y] -= co;
            y += lowbit(y);
        }
    }
    int query(int x) {
        int ans = 0;
        while(x) {
            ans += node[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void clear(cint x) {
        memset(node, 0, sizeof node);
        // for(int i=0; i<=x; i++) {
        //     node[x] = 0;
        // }
    }
}s1, s2;

int t, n;
int b[200200], cnt;
int c[200200];
map<int, int > e;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        cnt = 0;
        e.clear();
        for(int i=1; i<=n; i++) cin >> b[i];
        for(int i=1; i<=n; i++) c[i] = b[i];
        sort(c+1, c+1+n);
        for(int i=1; i<=n; i++)
            if(c[i] != c[i-1] || i == 1) {
                e[c[i]] = ++cnt;
            }
        s1.clear(n);
        s2.clear(n);
        bool flag = 0;
        for(int i=1; i<=n; i++) {
            int n1 = i - s1.query(e[b[i]]);
            int n2 = i - s2.query(e[b[i]]);
            // cout << n1 << "[]" << n2 << endl;
            if(n1 < 0 || n2 < 0) {
                flag = 1;
                // cout << i << ' ' << b[i] << ' ' << n1 << ' ' << n2 << endl;
                break;
            }
            s1.add(e[b[i]]+1, cnt, cnt, n1);
            s2.add(1, e[b[i]], cnt, n2);
        }
        if(!flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*

*/