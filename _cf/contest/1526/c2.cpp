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

int n;
int a[200200];
int nx[200200][2];
int to[200200];
typedef pair<int,int> pii;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ans = 0, pre = 0;
    int st = 0;
    ll tmp = 0;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        if(a[i] < 0) {
            tmp += a[i];
            q.push(a[i]);
            while(tmp < 0) {
                tmp -= q.top();
                q.pop();
            }
        } else {
            ++pre;
            tmp += a[i];
        }
        ans = max(ans, pre+int(q.size()));
    }
    cout << ans << endl;
    return 0;
}