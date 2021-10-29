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
int n;

int main() {
    cin >> t;
    while(t--) {
        string a;
        cin >> n >> a;
        int l=0, r=n-1, st=0;
        int t1=0;
        while(l<=r) {
            while(l<=r && ((a[l]-'0')&1)^st!=(l&1)) ++l;
            while(l<=r && ((a[r]-'0')&1)^st!=(r&1)) --r;
            st^=1;
            if(l<=r)++t1;
            ++l, --r;
        }
        l=0, r=n-1, st=0;
        int t2=0;
        while(l<=r) {
            while(l<=r && ((a[l]-'0')&1)^st==(l&1)) ++l;
            while(l<=r && ((a[r]-'0')&1)^st==(r&1)) --r;
            st^=1;
            if(l<=r)++t2;
            ++l, --r;
        }
        cout << min(t1, t2) << endl;
    }
    return 0;
}
/*
1
6
000111
*/