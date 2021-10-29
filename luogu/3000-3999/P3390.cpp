#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define ll long long
#define ull unsigned ll
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

struct stu {
    ll p[101][101];
    stu() { memset(p, 0, sizeof(p)); }
    void cl() {
        for (int i = 1; i <= n; i++) p[i][i] = 1;
    }
};

stu operator*(const stu& a, const stu& b) {
    stu tem;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k2 = 1; k2 <= n; k2++)
                (tem.p[i][j] += a.p[i][k2] * b.p[k2][j]) %= k;
    return tem;
}

inline void puts(const stu& a) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (j != n)
                cout << a.p[i][j] << ' ';
            else
                cout << a.p[i][j] << endl;
}

inline stu ksm(stu a, ll x) {
    stu bs;
    bs.cl();
    for (; x; x >>= 1, a = a * a)
        if (x % 2) bs = bs * a;
    return bs;
}

int main() {
    cin >> n >> k1;
    stu mem;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> mem.p[i][j];
    mem = ksm(mem, k1);
    puts(mem);
}