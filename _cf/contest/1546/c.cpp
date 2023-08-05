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
int n;
bool vis[100100];
int to[100100];

struct stu {
    int loc, val;
    bool operator < (const stu&a) const {
        return a.val == val ? loc < a.loc : val < a.val;
    }
    void init(cint x) {
        loc = x;
        cin >> val;
    }
} a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++) a[i].init(i);
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++) to[a[i].loc] = i;
        for(int i=1; i<=n; i++) {
            if()
        }
    }
    return 0;
}