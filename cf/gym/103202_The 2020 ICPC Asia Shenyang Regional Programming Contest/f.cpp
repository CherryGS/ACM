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
    int id, val;
    bool operator < (const stu&a) const {
        return val == a.val ? id < a.id : val < a.val;
    }
    void init(cint x) {
        id = x;
        scanf("%d", &val);
    }
}a[1001000];

bool cmp(const stu&a, const stu&b) {
    return a.id < b.id;
}

int main() {
    scanf("%d", &n);
    int mx = 0;
    for(int i=1; i<=n; i++) a[i].init(i);
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++) a[i].val = i;
    sort(a+1, a+1+n, cmp);
    int ans = 0;
    int st = 0;
    for(int i=1; i<=n; i++) {
        st = max(st, a[i].val);
        if(st == i) ++ans;
    }
    cout << ans << endl;
    return 0;
}