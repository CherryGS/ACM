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

int t, le;
char a[1001];

char div() {
    bool flag=0;
    for(int i=le; i; i--) {
        if(a[i] <= '1') {
            if(!flag) --le, flag=1;
            int tmp = 10 + a[i-1] - '0';
            a[i-1] = '0'+tmp/2;
        } else {
            flag=1;
            a[i] = 
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> a;
        le = strlen(a)-1;
    }
    return 0;
}