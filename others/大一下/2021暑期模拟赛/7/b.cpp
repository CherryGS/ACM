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

int n, m, k;
int b[100100];

vector<int > q;

int main() {
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=2; i<=n; i++) q.push_back(b[i]-b[i-1]);
    sort(q.begin(), q.end());
    ll ans = 0;
    for(int i=0; i<q.size()-k+1; i++) ans += q[i];
    ans += min(n, k);
    cout << ans << endl;
    return 0;
}