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

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll ans, pre;
string a;

ll ksm(ll bs, int x) {
    ll ans=1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    } 
    return ans;
}

int main() {
    cin >> n >> a;
    for(int i=0; i<n; i++)
        if(a[i] == '?') ++pre;
    for(int i=0; i<n-2; i++) {
        if(a[i] == 'a' || a[i] == '?')
            if(a[i+1] == 'b' || a[i+1] == '?')
                if(a[i+2] == 'c' || a[i+2] == '?') {
                    ll tmp = (a[i]=='?') + (a[i+1]=='?') + (a[i+2]=='?');
                    ans = (ans+ksm(3, pre-tmp)) % mod;
                }
    }
    cout << ans << endl;
    return 0;
}