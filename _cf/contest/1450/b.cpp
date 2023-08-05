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

int t, n, k;
int x[101], y[101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool flag=0;
        for(int i=1; i<=n; i++) {
            cin >> x[i] >> y[i]; 
        }
        for(int i=1; i<=n; i++) {
            flag=0;
            for(int j=1; j<=n; j++)
                if(i!=j && abs(x[i]-x[j])+abs(y[i]-y[j])>k) flag=1;
            if(!flag) break;
        }
        if(flag) cout << -1 << endl;
        else cout << 1 << endl;
    }   
    return 0;
}