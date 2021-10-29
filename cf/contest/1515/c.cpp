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
#define pii pair<int, int>

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;


int t;
int n, m, x;
priority_queue<pii >e;
int ans[100100];

int main() {
    cin >> t;
    while(t--) {
        while(!e.empty()) e.pop();
        cin >> n >> m >> x;
        for(int i=1; i<=m; i++)
            e.push(make_pair(0, i));
        int a;
        for(int i=1; i<=n; i++) {
            cin >> a;
            int l = e.top().first;
            int r = e.top().second;
            e.pop();
            ans[i] = r;
            e.push(make_pair(l-a, r));
        }
        cout << "YES" << endl;
        for(int i=1; i<=n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}