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
char s[1001];
char r[1001];
int le;

bool check(cint le) {
    for(int i=0; i<n-le; i++) {
        if(r[0] == s[i]) {
            for(int j=0; j<=le; j++) {
                if(r[j] != s[i+j]) {
                    break;
                }
                if(j == le) return 0;
            }
        }
    }
    return 1;
}

int main() {
    cin >> t;
    int la;
    while(t--) {
        cin >> n;
        cin >> s;
        le = 0;
        r[0] = 'a';
        while(!check(le)) {
            if(r[le] == 'z') {
                r[le] = 'a';
                la = le-1;
                while(la >= 0) {
                    if(r[la] == 'z') {
                        r[la] = 'a';
                        --la;
                    }
                    else {
                        r[la] = r[la] + 1;
                        break;
                    }
                }
                if(la < 0) r[++le] = 'a';
            } else {
                r[le] = r[le]+1;
            }
        }
        for(int i=0; i<=le; i++) cout << r[i];
        cout << endl;
    }
    return 0;
}