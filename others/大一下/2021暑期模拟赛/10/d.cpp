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

int t, n, k;
int a[200100];
int pri[10000100];
map<int, int> e;
set<int> s;

bool update(int x) {
    ll pre = 1;
    while(x > 1 && pri[x]) {
        e[pri[x]]++;
        if(e[pri[x]]&1) { pre *= pri[x]; }
        else if(!(e[pri[x]]&1)) { pre /= pri[x]; }
        x /= pri[x];
    }
    e.clear();
    if(s.find(pre) != s.end()) {
        s.clear();
        s.insert(pre);
        return 1;
    }
    s.insert(pre);
    return 0;
}

void init() {
    for(int i=2; i<=10000000; i++) {
        if(!pri[i]) 
            for(int j=1; i*j<=10000000; j++)
                pri[i*j] = i;
    }
}

int main() {
    init();
    cin >> t;
    while(t--) {
        s.clear();
        e.clear();
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> a[i];
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(update(a[i])) {
                // cout << i << "---" << endl;
                ++ans;
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}