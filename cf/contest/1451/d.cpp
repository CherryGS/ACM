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

ll t, d, k;

int main() {
    cin >> t;
    while(t--) {
        cin >> d >> k;
        ll a = (ll)(sqrt(((d*d)/(k*k)/2)*1.0));
        while((pow(a+1,2)+pow(a,2))*(k*k) <= d*d) ++a;
        if(2*a*a*k*k > d*d) cout << "Ashish" << endl;
        else cout << "Utkarsh" << endl;
    }
    return 0;
}