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
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, x;
int a[1010], b[1010];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) cin >> b[i];
        sort(a+1, a+1+n);
        sort(b+1, b+1+n);
        bool flag=0;
        for(int i=1; i<=n; i++)
            if(a[i]+b[n-i+1]>x) {flag=1;break;}
        if(flag) cout << "No";
        else cout << "Yes";
        cout << endl;
    }
    return 0;
}