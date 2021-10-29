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

int n;
int a[200200];
bool mp[1000100];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int ans=0;
    for(int i=1; i<=n; i++) mp[a[i]] = 1;
    for(int i=1; i<=n; i++) {
        int t=a[i];
        for(int j=2; j*t <= a[n]; j++)
            mp[j*t] = 0;
    }
    for(int i=1; i<=n; i++)
        if(a[i-1] != a[i] && a[i+1] != a[i])
            ans += mp[a[i]];
    cout << ans << endl;
    return 0;
}