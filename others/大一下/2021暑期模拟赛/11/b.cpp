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
int query(cint l, cint r) {
    if(l == r) return l;
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int tmp;
    cin >> tmp;
    return tmp; 
}

void dfs(cint l, cint r, cint id) {
    if(l == r) {
        cout << "! " << l << endl;
        return ;
    }
    if(l + 1 == r) {
        cout << "! " << (id == l ? r : l) << endl;
        return;
    }
    int mid = (l+r) >> 1;
    if(id <= mid) {
        if(l == mid) dfs(mid+1, r, query(mid+1, r));
        else {
            int rd = query(l, mid);
            if(rd == id) dfs(l, mid, id);
            else dfs(mid+1, r, query(mid+1, r));
        }
    } else {
        if(mid+1 == r) dfs(l, mid, query(l, mid));
        else {
            int rd = query(mid+1, r);
            if(rd == id && mid+1!=r) dfs(mid+1, r, id);
            else dfs(l, mid, query(l, mid));
        }
    }
}

int main() {
    cin >> n;
    dfs(1, n, query(1, n));
    return 0;
}