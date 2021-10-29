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



int main() {
    int l = 1, r = 300;
    int xor_ = 25;
    vector<int> e;
    for(int i=l; i<=r; i++) e.push_back(i^xor_);
    sort(e.begin(), e.end());
    for(int x: e) cout << x << ' ';
    cout << endl;
    return 0;
}