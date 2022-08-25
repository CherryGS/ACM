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

ll n;
int ans[100100];
int cnt;

int main() {
    bool flag = 0;
    cin >> n;
    for(ll i = (1<<63); i; i >>= 1) {
        if(n&i) {
            flag = 1;
            ans[++cnt] = 
        }
    }
    return 0;
}