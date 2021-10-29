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

int n, m;
bool mp[13][13][13][13];
bool isok[13][13][13][13];

void NO() {
    cout << 0 << endl;
}

void sol(cint a, cint b, cint c, cint d, bool st) {
    int r[5] = { a, b, c, d };
    sort(r, r+4);
    // if(st)
    // cout << r[0] << ' ' << r[1] << ' ' << r[2] << ' ' << r[3] << endl;
    if(!st)
        mp[r[0]][r[1]][r[2]][r[3]] = 1;
    if(st)
        isok[r[0]][r[1]][r[2]][r[3]] = 1;
}

void check(cint a, cint b, cint c, cint d) {
    if(a*c%d) return;
    int s = a*c/d;
    if(a*b-a*c/d != m) { return; }

    sol(a, b, c, d, 1);
}

int main() {
    cin >> n >> m;
    if(n == 4 && 13*13-1 < m) NO();
    else if(n < 4) NO();
    else {
        for(int a=1; a<=13; a++) {
            for(int b=1; b<=13; b++) {
                for(int c=1; c<=13; c++) {
                    for(int d=1; d<=13; d++) {
                        check(a, b, c, d);
                    }
                }
            }
        }
        for(int a=1; a<=13; a++) {
            for(int b=a; b<=13; b++) {
                for(int c=b; c<=13; c++) {
                    for(int d=c; d<=13; d++) {
                        if(!mp[a][b][c][d] && isok[a][b][c][d]) {
                            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
                        }
                    }
                }
            }
        }
    } 
    return 0;
}