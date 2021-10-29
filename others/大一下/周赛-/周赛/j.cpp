#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <bitset>
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

int n;
int a[100100];
bitset<100000> l, r;

int main() {
    ios::sync_with_stdio(false);
    ll ans=0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        r[n-a[i]]=1;
    }
    r[n-a[1]]=0;
    l[a[1]-1]=1;
    for(int i=2; i<n; i++) {
        r[n-a[i]]=0;
        if(n+1<2*a[i]) ans += ((l>>(-n+2*a[i]-1)) & r).count();
        else ans += ((l<<(n-2*a[i]+1)) & r).count();
        l[a[i]-1]=1;
    }
    cout << ans << endl;
    return 0;
}