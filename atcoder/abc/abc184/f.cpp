#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
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

int n, t;
int a[100];
set<int, greater<int>> e;

int main() {
    cin >> n >> t;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+1+n);

    int k = lower_bound(a+1, a+1+n, t)-a;
    if(k <= n) {
        if(a[k]==t) {
            cout << t;
            return 0;
        }
        k--;
    }
    e.insert(0);
    for(int i=k; i>=1; i--) {
        for(auto r = e.begin(); r!=e.end();r++) 
            if(int(*r)+a[i]<t){
                e.insert(int(*r)+a[i]);
            } else if(int(*r)+a[i]==t) {
                cout << t << endl;
                return 0;
            }
    }
    auto key = e.lower_bound(t);
    cout << *key;
    return 0;
}