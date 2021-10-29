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

int n, m;
vector<int> mp[100100];
int sav[101];

void add(cint f, cint t) {
    mp[f].push_back(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int k, r;
    for(int i=1; i<=n; i++) {
        cin >> k;
        for(int j=1; j<=k; j++) {
            cin >> r;
            add(i, r);
        }
    }
    int now = 1;
    for(int i=1; i<=m; i++) {
        cin >> k >> r;
        if(k == 0) {
            now = mp[now][r-1];
        } else if(k == 1) {
            sav[r] = now;
            cout << now << endl;
        } else {
            now = sav[r];
        }
    }
    cout << now << endl;
    return 0;
}