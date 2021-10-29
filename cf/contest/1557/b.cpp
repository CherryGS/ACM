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
int n, k;
struct stu {
    int id, val;
    void init(cint x) {
        id = x;
        cin >> val;
    }
    bool operator < (const stu&a) const {
        return val < a.val;
    }
} a[100100];

bool cmp(const stu&a, const stu&b) {
    return a.id < b.id;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i=1; i<=n; i++) a[i].init(i);
        sort(a+1, a+1+n);
        for(int i=1; i<=n; i++) a[i].val = i;
        sort(a+1, a+1+n, cmp);
        int ans = 0;
        for(int i=1; i<n; i++)
            if(a[i+1].val != a[i].val+1) ++ ans;
        if(ans >= k) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}