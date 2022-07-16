#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
char s[100100];
char t[100100];
bool vis[3600*24+2000];

// 13:00:00 - 18:00:00
int cacu(char s[]) {
    // cout << s[0] << " --- " << endl; 
    int sum = 0;
    sum += (s[6] - '0') * 10 + s[7] - '0';
    sum += 60*((s[3] - '0')*10 + s[4] - '0');
    sum += 3600*( (s[0] - '0')*10 + s[1]-'0' );
    return sum;
}

void sol(char s[], char t[]) {
    int st = cacu(s);
    int ed = cacu(t);
    // cout << st << ' ' << ed << endl;
    for(int i=st; i<ed; i++) { vis[i] = 1; }
}

string _to_string(int x) {
    int c = 2;
    string s;
    while(x) {
        -- c;
        s = char(x%10+'0') + s;
        x /= 10;
    }
    while(c) { s = "0" + s; --c; }
    return s;
}

string format(int x) {
    int a[3];
    a[0] = x % 60;
    x /= 60;
    a[1] = x % 60;
    x /= 60;
    a[2] = x % 60;
    x /= 60;
    string s;
    s += _to_string(a[2]) + ":" + _to_string(a[1]) + ":" + _to_string(a[0]);
    return s;
}

void print(int x, int y) {
    cout << format(x) << " - " << format(y) << endl;
}

int main() {
    freopen("1.in", "r", stdin);
    cin >> n;
    char tmp;
    for(int i=1; i<=n; i++) {
        cin >> s >> tmp >> t;
        sol(s, t);
    }
    vis[3600*24-1] = 1;
    int st = -1;
    for(int i=0; i<3600*24; i++) {
        if(!vis[i] && st == -1) {
            st = i;
        }
        if(!vis[i] && vis[i+1] == 1) {
            print(st, i+1);
            st = -1;
        }
    }
    // for(int i=0; i<3600*24; i++) {
    //     cout << vis[i];
    //     if(i % 600 == 0) { cout << endl; }
    // }
}