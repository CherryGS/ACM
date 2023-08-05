#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
char s[200200];
int sum[200200][3];

int main() {
    cin >> n >> m;
    cin >> s;
    for(int i=0; i<n; i++) {
        sum[i][s[i]-'a']++;
        for(int j=0; j<3; j++) {
            if(i >= 3) sum[i][j] += sum[i-3][j];
        }
    }
    return 0;
}