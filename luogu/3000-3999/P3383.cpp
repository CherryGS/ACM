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

int n, q;
int pri[50000100], cnt;
bool vis[100000001];

void init() {
    for(int i=2; i<=100000000; i++) {
        if(!vis[i]) {
            pri[++cnt] = i;
        }
        for(int j=1; j<=cnt && i*pri[j] <= 100000000; j++) {
            if(i*pri[j] > 100000000) cout << i*pri[j] << endl;
            vis[i*pri[j]] = 1;
            if(!(i%pri[j])) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    cin >> n >> q;
    int s;
    for(int i=1; i<=q; i++) {
        cin >> s;
        cout << pri[s] << endl;
    }
    return 0;
}