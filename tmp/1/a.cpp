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

int n, k;
ull s;

int main() {
    cin >> n >> k >> s;
    bool flag = 1;
    for(int i=1; i<=k; i++) {
        int tmp;
        cin >> tmp;
        if((1ull<<(tmp-1)) & s) {
            flag = 0;
            break;
        }
    }
    if(!flag || (s >= (1ull<<(n-1)) && (1ull<<(n-1)) <= s - (1ull<<(n-1)))) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
/*
18446744073709551615
*/