#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int n;
int tp[22];
int to[200200];
int bk[200200][21];

int main() {
    int t;
    cin >> n;
    tp[0]=1;
    for(int i=1; i<=20; i++) tp[i] = tp[i-1]*2;
    for(int i=1; i<=n; i++) {
        cin >> t;
        for(int j=20; j; j--) {
            if(t >= tp[j]) {
                t -= tp[j];
                bk[i][j] = 1;
            }
            bk[i][j] += bk[i-1][j];
        }
    }
    for(int j=20; j; j--) {
        int loc = 1;
        for(int i=n; i>=1; i--) {
            if(bk[i][j] != bk[loc][j-1]) {
                to[loc] = i;
                loc = i;
            }
        }
    }


    return 0;
}