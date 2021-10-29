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

int sum[2022];
char s[2002000];

int main() {
    cin >> s;
    int l = strlen(s);
    ll ans = 0;
    int pre = 0;
    int pre_ = 1;
    sum[0] = 1;
    for(int i=l-1; i>=0; i--) {
        pre += (s[i] - '0')*pre_;
        pre %= 2019;
        ans += sum[pre];
        ++sum[pre];
        // cout << pre << endl;
        pre_ = (pre_*10) % 2019;
    }
    cout << ans << endl;
    return 0;
}