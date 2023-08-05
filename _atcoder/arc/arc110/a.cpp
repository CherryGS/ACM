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

ull ans=1;
ull n;

int main() {
    cin >> n;
    for(int i=2; i<=n; i++) 
        if(ans % i){
            ull t = i;
            while(t*i<=n) t*=i;
            // cout << i << ' ' << t << endl;
            ans *= t;
        }
    cout << ans+1;
    return 0;
}