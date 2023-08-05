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
char x;
int ans;

int main() {
    cin >> n >> ans;
    for(int i=1; i<=n; i++) {
        cin >> x;
        if(x=='o') ++ans;
        else --ans;
        if(ans<0) ans=0;
    }
    cout << ans;
    return 0;
}