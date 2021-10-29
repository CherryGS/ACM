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
int a[100100];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int id=0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(a[i] < 100000) id = i;
    }
    cout << "19992147" << endl;
    if(id) cout << id << ' ' << 1 << endl;
    else cout << -1 << endl;
    return 0;
}