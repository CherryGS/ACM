#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
vector<int> q;

bool check(int x) {
    if(!(x%3)) return 1;
    if((x%10)==3) return 1;
    return 0;
}

void init() {
    for(int i=1; i<=1000000; i++) {
        if(!check(i)) q.push_back(i);
    }
}

int main() {
    init();
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        cout << q[k-1] << endl;
    }
    return 0;
}