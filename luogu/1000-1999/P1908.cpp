#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long
#define ull unsigned long long
#define cint const int&

using namespace std;

#define ls lson[cnt]
#define rs rson[cnt]
int lson[8002000], rson[8002000];
int sum[8002000];

int n;
int sonN = 1;
int root = 1;
int num;
int mx;
int l, r;

void add(int& cnt, cint le, cint ri) {
    if(!cnt) cnt = ++sonN;
    if(le == ri && le == num) {++sum[cnt]; return;}
    int mid = (le+ri) >> 1;
    if(num <= mid) add(ls, le, mid);
    if(num >= mid+1) add(rs, mid+1, ri);
    sum[cnt] = sum[ls] + sum[rs];
}

ll query(cint cnt, cint le, cint ri) {
    if(!cnt) return 0;
    if(le >= l && ri <= r) return sum[cnt];
    int mid = (le+ri) >> 1;
    ll m = 0;
    if(l <= mid) m += query(ls, le, mid);
    if(r >= mid + 1) m += query(rs, mid+1, ri);
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    ll ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num;
        mx = max(mx, num);
        l = num + 1;r = mx;
        ans += query(root, 0, 1e9+1);
        add(root, 0, 1e9+1);
    }
    cout << ans;
    return 0;
}