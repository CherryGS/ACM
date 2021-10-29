#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll n, a, b;

int main() {
    cin >> t;
    while(t--) {
        bool flag = 0;
        cin >> n >> a >> b;
        if(a == 1) {
            if((n-1)%b) flag = 0;
            else flag = 1;
        }
        else {
            for(ll i=1; i<=n && !flag; i*=a) {
                if(!((n-i)%b)) flag = 1;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}