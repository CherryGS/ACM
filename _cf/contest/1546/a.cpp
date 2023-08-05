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

int t, n;
int a[101], b[101];
queue<int> q1, q2;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) cin >> b[i];
        int sum = 0;
        for(int i=1; i<=n; i++) sum += a[i]-b[i];
        if(sum) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(a[i] < b[i]) for(int j=1; j <= b[i]-a[i]; j++) q1.push(i);
            if(a[i] > b[i]) for(int j=1; j <= a[i]-b[i]; j++) q2.push(i);
            ans += abs(a[i]-b[i]);
        }
        cout << ans/2 << endl;
        while(!q1.empty()) {
            cout << q2.front() << ' ' << q1.front() << endl;
            q1.pop(); q2.pop();
        }
    }
    return 0;
}