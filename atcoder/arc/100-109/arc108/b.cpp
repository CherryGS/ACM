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
char q[200200];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    char a;
    for(int i=1; i<=n; i++) {
        cin >> a;
        if(a == 'x' && cnt >= 2 && q[cnt]=='o' && q[cnt-1] == 'f') cnt -= 2;
        else q[++cnt] = a;
    }
    cout << cnt;
    return 0;
}