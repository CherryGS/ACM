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

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
int arr[1001000];
int nx[1001000];
int tr[1001000];
struct stu {
    int l, r;
    int id, ans;
    void init(cint x) {
        cin >> l >> r;
        id = x;
    }
} a[1001000];

bool cmp1(const stu&a, const stu&b) {
    return a.r < b.r;
}

bool cmp2(const stu&a, const stu&b) {
    return a.id < b.id;
}

int lowbit(cint x) {
    return x&-x;
}

void add(int x, cint co) {
    while(x <= n) {
        tr[x] += co;
        x += lowbit(x);
    }
}

int gets(int x) {
    int ans=0;
    while(x) {
        ans += tr[x];
        x -= lowbit(x);
    }
    return ans;
}

void build(int x, cint y) {
    while(x <= y) {
        if(!nx[arr[x]]) {
            nx[arr[x]] = x;
            add(x, 1);
        } else {
            add(nx[arr[x]], -1);
            add(x, 1);
            nx[arr[x]] = x;
        }
        ++x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    for(int i=1; i<=m; i++) a[i].init(i);
    sort(a+1, a+1+m, cmp1);
    for(int i=1; i<=m; i++) {
        build(a[i-1].r+1, a[i].r);
        a[i].ans = gets(a[i].r) - gets(a[i].l-1);
    }
    sort(a+1, a+1+m, cmp2);
    for(int i=1; i<=m; i++) cout << a[i].ans << endl;
    return 0;
}