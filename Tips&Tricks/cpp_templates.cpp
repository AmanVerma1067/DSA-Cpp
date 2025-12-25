// cpp_templates.cpp
// Collection of reusable C++ templates for contests
// Includes: fast I/O, DSU, Fenwick (BIT), Segment Tree (point update + range sum), lazy Segment Tree (range add + range sum)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ---------- Fast I/O ----------
struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

// ---------- DSU (Union-Find) ----------
struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n=0) { init(n); }
    void init(int _n) {
        n = _n;
        p.resize(n+1); r.assign(n+1,0);
        for (int i=1;i<=n;i++) p[i]=i;
    }
    int find(int x) {
        if (p[x]==x) return x;
        return p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a==b) return false;
        if (r[a] < r[b]) swap(a,b);
        p[b] = a;
        if (r[a]==r[b]) r[a]++;
        return true;
    }
};

// ---------- Fenwick Tree (1-based) ----------
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int _n=0){init(_n);} 
    void init(int _n){ n=_n; bit.assign(n+1,0); }
    void add(int idx, ll val){ for(; idx<=n; idx+=idx&-idx) bit[idx]+=val; }
    ll pref(int idx){ ll s=0; for(; idx>0; idx-=idx&-idx) s+=bit[idx]; return s; }
    ll range(int l,int r){ if(r<l) return 0; return pref(r)-pref(l-1); }
};

// ---------- Segment Tree (point update, range sum) ----------
struct SegTree {
    int n;
    vector<ll> st;
    SegTree(int _n=0){init(_n);} 
    void init(int _n){ n=1; while(n<_n) n<<=1; st.assign(2*n,0); }
    void build(const vector<ll>& a){
        int m = a.size(); init(m);
        for(int i=0;i<m;i++) st[n+i]=a[i];
        for(int i=n-1;i>0;i--) st[i]=st[i<<1]+st[i<<1|1];
    }
    void point_update(int pos, ll val){ // set a[pos]=val (0-based pos)
        pos += n; st[pos] = val;
        for(pos>>=1; pos; pos>>=1) st[pos] = st[pos<<1] + st[pos<<1|1];
    }
    ll range_sum(int l, int r){ // 0-based inclusive
        ll res=0;
        l += n; r += n;
        while(l<=r){
            if (l&1) res += st[l++];
            if (!(r&1)) res += st[r--];
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

// ---------- Lazy Segment Tree (range add, range sum) ----------
struct LazySeg {
    int n;
    vector<ll> st, lz;
    LazySeg(int _n=0){init(_n);} 
    void init(int _n){ n=1; while(n<_n) n<<=1; st.assign(2*n,0); lz.assign(2*n,0); }
    void push(int p, int len){
        if (lz[p]==0) return;
        st[p] += lz[p]*len;
        if (p < n) { // not leaf
            lz[p<<1] += lz[p];
            lz[p<<1|1] += lz[p];
        }
        lz[p]=0;
    }
    void range_add(int p, int l, int r, int ql, int qr, ll val){
        push(p, r-l+1);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr){
            lz[p] += val; push(p, r-l+1); return;
        }
        int mid = (l+r)>>1;
        range_add(p<<1, l, mid, ql, qr, val);
        range_add(p<<1|1, mid+1, r, ql, qr, val);
        st[p] = st[p<<1] + st[p<<1|1];
    }
    ll range_sum(int p, int l, int r, int ql, int qr){
        if (qr < l || r < ql) return 0;
        push(p, r-l+1);
        if (ql <= l && r <= qr) return st[p];
        int mid = (l+r)>>1;
        return range_sum(p<<1, l, mid, ql, qr) + range_sum(p<<1|1, mid+1, r, ql, qr);
    }
    // wrappers (0-based external)
    void add(int l, int r, ll val){ range_add(1, 0, n-1, l, r, val); }
    ll sum(int l, int r){ return range_sum(1, 0, n-1, l, r); }
};

// ---------- Useful map snippets ----------
// unordered_map<int,int> freq;
// freq.reserve(1024);
// freq.max_load_factor(0.7);

// ---------- Example main (template) ----------
int main(){
    // Example usage area; replace with contest I/O
    // fastio already initialized
    return 0;
}
