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

int t;
ll k;
ll to[100];
int q[1001], cnt;

int main() {
    to[0] = 2;
    for(int i=1; i<=61; i++) to[i] = ((to[i-1]+2ll)*2)-2ll;
    // for(int i=1; i<=61; i++) cout << to[i] << endl;
    cin >> t;
    while(t--) {
        int ans=0;
        cnt = 0;
        cin >> k;
        if(k&1) {cout << -1 << endl; continue;}
        for(int i=61; i>=0; i--)
            while(k >= to[i]) {
                // cout << k << "---" << to[i] << ' ' << i << endl;
                k -= to[i];
                q[++cnt] = i;
                ans += i+1;
            }
        cout << ans << endl;
        while(cnt) {
            int r = q[cnt--];
            cout << 1 << ' ';
            while(r) {cout << 0 << ' '; --r;}
        }
        cout << endl;
    }
    return 0;
}