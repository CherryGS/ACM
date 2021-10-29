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

int t, n;
int a[100100];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        int ans=0;
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        a[n+1] = 0;
        sort(a+1, a+1+n);
        for(int i=n; i; i--) if(a[i+1] != a[i]){
            if(a[i+1] != a[i]+1) ++a[i];
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
2
7
1 2 3 4 5 5 5
7
1 2 3 4 5 5 5
*/