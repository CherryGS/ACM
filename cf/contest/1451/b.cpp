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

int t, n, q;
string a;

int main() {
    cin >> t;
    int l, r;
    while(t--) {
        cin >> n >> q;
        cin >> a;
        for(int i=1; i<=q; i++) {
            bool flag=0, s1=0, s2=0;
            cin >> l >> r;
            for(int j=r+1; j<=n; j++)
                if(a[j-1] == a[r-1]) flag=1;
            for(int j=l-1; j; j--)
                if(a[j-1] == a[l-1]) flag=1;
            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}