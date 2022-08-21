## fail -- 失配指针

节点的 fail 指针只会指向比自己更浅节点 , 而每个点有且只有一个 fail 指针指出 , 而根节点的 fail 指针可以视为自己 , 所以 fail 指针的关系类似前缀函数中的跳跃关系 , 都形成了一棵树 (实际上就是一棵向下的 trie 树和一棵向上的 fail 树)

```cpp
const int sig = 26;
const int N = 1000000;
struct trie {
    int node[sig][N+100], cnt;
    int val[N+100];
    /* 字符串下标从 0 开始 */
    void insert(char *s, int n) {
        int t = 0, v;
        for(int i=0; i<n; i++) {
            v = s[i] - 'a';
            if(node[v][t] == 0) { node[v][t] = ++cnt; }
            t = node[v][t];
        }
        ++val[t];
    }
};

struct AC {
    trie *p;
    int fail[N+100];
    void init(trie &a) { p = &a; }
    void build() {
        // fail[0] = -1;
        auto tr = p->node;
        queue<int> q;
        for(int i=0; i<sig; i++) { if(tr[i][0]) { q.push(tr[i][0]); } }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0; i<sig; i++) {
                if(tr[i][u]) { fail[tr[i][u]] = tr[i][fail[u]]; q.push(tr[i][u]); }
                else { tr[i][u] = tr[i][fail[u]]; }
            }
        }
    }
    /* 示例 */
    int query(char *s, int n) {
        int ans = 0, t = 0, v;
        auto tr = p->node;
        auto val = p->val;
        for(int i=0; i<n; i++) {
            v = s[i] - 'a';
            t = tr[v][t];
            for(int j=t; j && val[j] != -1; j = fail[j]) {
                ans += val[j];
                val[j] = -1;
            }
        }
        return ans;
    }
};
```

