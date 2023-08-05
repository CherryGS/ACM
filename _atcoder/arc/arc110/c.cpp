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
int a[2010000];
int to[2000100];
int ans[2000100], cnt;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        to[a[i]] = i;
    }
    int mn = n;
    for(int i=n; i>=1; i--) 
        if(to[i] != i && to[i] < mn) {
            mn = to[i];
            for(int j=to[i]; j<i; j++) {
                ans[++cnt] = j;
                swap(a[j], a[j+1]);
            }
        }
    if(cnt != n-1) {
        cout << -1 << endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
        if(a[i] != i) {
            cout << -1 << endl;
            return 0;
        }
    for(int i=1; i<=cnt; i++) 
        cout << ans[i] << endl;
    return 0;
}