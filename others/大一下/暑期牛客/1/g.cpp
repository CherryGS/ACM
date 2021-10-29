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

int n, k;
ll ans;
ll a[500500], b[500500];
bool via[500500], vib[500500];
vector<int> q1, e[2];

bool cmp(cint x, cint y) {
    if(x < 0) return y < 0 ? b[-x] < b[-y] : b[-x] < a[y];
    else return y < 0 ? a[x] < b[-y] : a[x] < a[y];
}

void debug() {
    for(int i=1; i<=q1.size(); i++) {
        cout << q1[i-1] << ' ';
    }
    cout << endl;
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++) ans += abs(a[i] - b[i]);
    if(n == 2) {
        if(k & 1) cout << abs(a[1]-b[2])+abs(a[2]-b[1]) << endl;
        else cout << ans << endl;
    } else {
        for(int i=1; i<=n; i++) q1.push_back(i);
        for(int i=1; i<=n; i++) q1.push_back(-i);
        sort(q1.begin(), q1.end(), cmp);
        for(int i=0; i<n; i++) {
            if(q1[i] > 0) via[q1[i]] = 1;
            else vib[-q1[i]] = 1;
        }
        for(int i=1; i<=n; i++) {
            if(via[i] && vib[i]) e[1].push_back(max(a[i], b[i]));
            if(!via[i] && !vib[i]) e[0].push_back(min(a[i], b[i]));
        }
        sort(e[0].begin(), e[0].end());
        sort(e[1].begin(), e[1].end());
        int le = e[0].size();
        for(int i=1; i<=min(k,le); i++) {
            if(e[0][le-i] <= e[1][i-1]) break;
            ans += 2*(e[0][le-i]-e[1][i-1]);
        }
        // debug();
        cout << ans << endl;
    }
    return 0;
}