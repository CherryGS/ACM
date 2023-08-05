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

int t, n, x;
int a[505], b[505];

bool check(int i) {
    for(; i<=n; i++)
        if(a[i] < a[i-1]) return 0;
    return 1;
}

int main() {
    cin >> t;
    while(t--) {
        bool flag=0;
        a[0] = -1;
        cin >> n >> x;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            if(a[i] < a[i-1]) flag=1;
        }
        if(!flag) {cout << 0 << endl; continue;}

        int ans=0;
        for(int i=1; i<=n && !check(i); i++) {
            if(a[i] > x) swap(a[i], x), ++ans;
            if(a[i] < a[i-1]) flag=0;
        }
        if(!flag) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
/*
1
6 1
0 2 1 3 4 5
*/