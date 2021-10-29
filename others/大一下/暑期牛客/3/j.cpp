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

namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
      	u = 0;
    }
}
using namespace GenHelper;
bool edge[8005][8005];

ll sol(ll x) {
    return x*(x-1)*(x-2)/6;
}

int main() {
    int n, seed;
    cin >> n >> seed;
    srand(seed);
    for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edge[j][i] = edge[i][j] = read();
    ll ans = 0;
    // for(int i=0; i<n; i++) {
    //     for(int j=i+1; j<n; j++)
    //         cout << edge[i][j] << ' ';
    //         cout << endl;
    // }
    for(int i=0; i<n; i++) {
        int s1 = 0, s2 = 0;
        for(int j=0; j<n; j++) if(i!=j){
            if(edge[i][j]) ++s1;
            else ++s2;
        }
        ans += s1*s2;
    }
    cout << sol(n) - ans/2 << endl;
 	return 0;
}