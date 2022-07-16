#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n, m, k;

int a[10001];
int st[101], cnt;

string _to_string(int x) {
    string s;
    while(x) {
        s = char(x%10+'0') + s;
        x /= 10;
    }
    return s;
}

int main() {
    freopen("1.in", "r", stdin);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) { cin >> a[i]; }
    vector<string> ans;
    int lst = 0x3f3f3f3f, i = 1, sum = 0;
    string now;
    while(true) {
        if(cnt == 0 && i > n) { break; }
        if(sum == k) {
            ans.push_back(now);
            sum = 0;
            now = "";
            lst = 0x3f3f3f3f;
        }
        if(cnt != 0 && st[cnt] <= lst) {
            // 小盒子最上面的满足条件
            if(now != "") { now += " "; }
            now += _to_string(st[cnt]);
            lst = st[cnt];
            --cnt;
            ++sum;
        }
        else {
            // 小盒子最上面的不满足条件
            if(i <= n && a[i] <= lst) {
                // 推送器上还有且满足条件
                if(now != "") { now += " "; }
                now += _to_string(a[i]);
                lst = a[i];
                i++;
                ++sum;
            }
            else if(i > n) {
                // 推送器上没有
                ans.push_back(now);
                sum = 0;
                now = "";
                lst = 0x3f3f3f3f;
            }
            else if(cnt < m && i <= n){
                // 推送器上还有但不满足条件 , 此时小盒子没满
                st[++cnt] = a[i];
                i++;
            }
            else{
                // 推送器上还有但不满足条件 , 此时小盒子满了
                ans.push_back(now);
                sum = 0;
                now = "";
                lst = 0x3f3f3f3f;
            }
        }
    }
    if(now != "") { ans.push_back(now); }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size() - 1) {
            cout << '\n';
        }
    }
}