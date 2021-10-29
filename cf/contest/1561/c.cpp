#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
vector<int> q[100100];
int d[100100];

bool cmp(cint x, cint y) {
    return d[x] < d[y];
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int tmp, tmp1;
        for(int i=1; i<=n; i++) {
            q[i].clear();
            d[i] = 0;
            cin >> tmp;
            for(int j=1; j<=tmp; j++) {
                cin >> tmp1;
                q[i].push_back(tmp1);
                d[i] = max(d[i], tmp1-j+2);
            }
        }
        vector<int> id;
        for(int i=1; i<=n; i++) id.push_back(i);
        sort(id.begin(), id.end(), cmp);
        ll ans = 0, sum = 0;
        for(int x: id) {
            if(sum+ans <= d[x]) ans += d[x]-sum-ans;
            // cout << x << '+' << d[x] << ' ' << ans << ' ' << sum << endl;
            sum += q[x].size();
        }
        cout << ans << endl;
    }
    return 0;
}