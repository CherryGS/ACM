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
int a[505];
int to[505];
int q[505050], cnt;

void debug() {
    cout << endl;
    cout << endl;
    cout << "------" << endl;
    for(int i=1; i<=n; i++) cout << a[i] << ' ';
    cout << endl;
    cout << "------" << endl;
}

void sw(cint x) {
    // debug();
    q[++cnt] = x;
    swap(to[a[x]], to[a[x+1]]);
    swap(a[x], a[x+1]);
}

void sol(int x) {
    while(x >= a[x+1]) {
        sw(x);
        -- x;
    }
}

void change(cint x) {
    sw(x-1);
    sw(x);
    sw(x-1);
    sw(x);
    sw(x-1);
}


int main() {
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            to[a[i]] = i;
        }
        for(int i=1; i<=n; i++) {
            int r = to[i];
            if(r == i) continue;
            if(((cnt+1)&1) ^ ((r-1)&1)) {
                if(r-i >= 2) sw(r-2);
                else change(r-1);
            }
            r = to[i];
            sol(r-1);
        }
        cout << cnt << endl;
        for(int i=1; i<=cnt; i++) cout << q[i] << ' ';
        cout << endl;
    }
    return 0;
}
/*
1
5
2 1 4 3 5
*/