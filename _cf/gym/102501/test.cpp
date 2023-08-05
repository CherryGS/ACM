#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
ll m = 1ll << 40;
ll s = 0x600DCAFE;

int main() {
    ll r = 0;
    ll rk = 0;
    ll pre = 0;
    for(int i=1; i<=10000000; i++) {
        ll k = (s%10 - r + 10) % 10;
        if(k != rk) { cout << i-pre << endl; pre = i;}
        r = s%10;
        rk = k;
        s = (s + (s>>20) + 12345) % m;
    }
    return 0;
}