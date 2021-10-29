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

string str[8] = {
    "Right",
    "Left",
    "Up",
    "Down",
    "Down-Right",
    "Down-Left",
    "Up-Left",
    "Up-Right",
};
string win = "Done";

int locate(cint x, cint y) {
    cout << x << ' ' << y << endl;
    cout.flush();
    string tmp;
    cin >> tmp;
    if(tmp == win) return -1;
    for(int i=0; i<8; i++)
        if(tmp == str[i]) return i;
}

int main() {
    cin >> t;
    while(t--) {
        int x = 8, y = 8;
        while(1) {
            int r = locate
        }
    }
    return 0;
}