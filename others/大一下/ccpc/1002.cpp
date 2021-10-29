#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
char s[200][20];
int le[200];
int num[26];
bool vis[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        memset(num, 0, sizeof num);
        memset(vis, 0, sizeof vis);
        cin >> n;
        for(int i=0; i<n; i++) cin >> s[i];
        for(int i=0; i<n; i++) le[i] = strlen(s[i]);
        // for(int i=1; i<=n; i++)
        //     cout << le[i] << ' ';
        //     cout << endl;
        vector<char > q;
        for(int l=0; l<60000; l++)
            for(int k=0; k<n; k++) {
                q.push_back(s[k][l%le[k]]);
            }
        deque<int> e;
        int s_le = q.size();
        int num_1 = 0;
        for(int i=0; i<s_le; i++) {
            if(!vis[q[i]-'a']) {
                vis[q[i]-'a'] = 1;
                ++num_1;
            }
        }
        int ed;
        int ans = inf_int;
        int pre = 0;
        // cout << s_le << "---" << endl;
        for(int i=0; i<s_le; i++) {
            if(!num[q[i]-'a']) ++ pre;
            num[q[i]-'a']++;
            e.push_back(i);
            ed = i;
            while(!e.empty() && num[q[e.front()]-'a'] > 1) {
                num[q[e.front()]-'a']--;
                e.pop_front();
            }
            // cout << ed << "---" << e.front() << endl;
            if(pre == num_1) ans = min(ans, ed - e.front()+1);
        }
        cout << ans << endl;
    }    
    return 0;
}