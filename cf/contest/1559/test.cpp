#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll cnt;

int check(int x) {
    if(x == 1) return 1;
    int num = 0;
    int r = sqrt(x);
    for(int i=2; i<=r; i++) {
        ++cnt;
        if(!(x%(i*i))) return 2;
        if(!(x%i)) { 
            ++ num;
            x /= i;
        }
    }
    if(x > 1) ++num;
    return !(num&1);
}

int main() {
    for(int i=1; i<=100000; i++) check(i);
    cout << cnt << endl;
    return 0;
}