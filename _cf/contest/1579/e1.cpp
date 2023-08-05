#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n;
int a[200200];
deque<int> q;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        q.push_back(a[1]);
        for(int i=2; i<=n; i++) {
            if(a[i] < q.front()) q.push_front(a[i]);
            else q.push_back(a[i]);
        }
        while(!q.empty()) {
            cout << q.front() << ' ';
            q.pop_front();
        }
        cout << endl;
    }
    return 0;
}