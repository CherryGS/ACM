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


int t, n, k, x, y;
int a[100100];

int check(cint key) {
    ll tmp = 0;
    for(int i=1; i<=k; i++)
        if(a[i] < key) tmp += (a[i]-key) * x;
        else tmp += (a[i]-key) * y;
    for(int i=k+1; i<=n; i++) {
        ll o = tmp;
        if(a[i-k] < key) o -= (a[i-k]-key) * x;
        else o -= (a[i-k]-key) * y;
        if(a[i] < key) o += (a[i]-key) * x;
        else o += (a[i]-key) * y;
        if(abs(tmp) > abs(o)) tmp = o;
    }
    return tmp;
}

void sol(cint key) {
    ll tmp = 0;
    for(int i=1; i<=k; i++)
        if(a[i] < key) tmp += abs((a[i]-key) * x);
        else tmp += abs((a[i]-key) * y);
    for(int i=k+1; i<=n; i++) {
        ll o = tmp;
        if(a[i-k] < key) o -= abs((a[i-k]-key) * x);
        else o -= abs((a[i-k]-key) * y);
        if(a[i] < key) o += abs((a[i]-key) * x);
        else o += abs((a[i]-key) * y);
        tmp = min(o, tmp);
    }
    cout << tmp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> k >> x >> y;
        int r=0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            r = max(a[i], r);
        }

        int l=0, mid, tmp;
        while(l <= r) {
            mid = (l+r) >> 1;
            tmp = check(mid);
            if(!tmp) break;
            else if(tmp > 0) l = mid+1;
            else r = mid-1;
        }
        int a=abs(check(mid-1)), b=abs(check(mid)), c=abs(check(mid+1));
        if(a < b) {
            if(a < c) --mid;
            else ++mid;
        } else {
            if(b > c) ++mid;
        }
        sol(mid);
        cout << mid << ' ' << check(mid) << endl;
    }
    return 0;
}