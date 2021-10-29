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

const int mat_size = 101;
struct matrix {
    ll bs[mat_size][mat_size];
    void input(cint x) {
        for(int i=1; i<=x; i++)
            for(int j=1; j<=x; j++) cin >> bs[i][j];
    }
    void init(cint x) {
        for(int i=1; i<=x; i++) bs[i][i] = 1;
    }
    void print(cint x) {
        for(int i=1; i<=x; i++) {
            for(int j=1; j<=x; j++)
                cout << bs[i][j] << ' ';
            cout << endl;
        }
    }
};

int n;
ll k;

matrix product (const matrix&a, const matrix&b) {
    matrix tmp;
    memset(tmp.bs, 0, sizeof tmp.bs);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                (tmp.bs[i][j] += a.bs[i][k] * b.bs[k][j]) %= mod;
    return tmp;
}

matrix ksm(matrix bs, ll x) {
    matrix ans;
    ans.init(n);
    while(x) {
        if(x&1) ans = product(ans, bs);
        bs = product(bs, bs);
        x >>= 1;
    }
    return ans;
}

int main() {
    cin >> n >> k;
    matrix a;
    a.input(n);
    matrix ans;
    ans = ksm(a, k);
    ans.print(n);
    return 0;
}