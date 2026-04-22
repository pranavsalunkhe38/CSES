// LC: 0000 Static Range Minimum Queries
// Title: Static Range Minimum Queries
// Difficulty: Medium
// Date: 22 April 2026

#include <bits/stdc++.h>
using namespace std;

// ---------- types ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// ---------- macros ----------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)

// ---------- debug (compile with -DLOCAL) ----------
#ifdef LOCAL
template <typename T>
void _print(const T &x) { cerr << x; }
template <typename A, typename B>
void _print(const pair<A, B> &p)
{
    cerr << "(";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << ")";
}
template <typename T>
void _print(const vector<T> &v)
{
    cerr << "[";
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            cerr << ", ";
        _print(v[i]);
    }
    cerr << "]";
}
template <typename T>
void _print(const set<T> &s)
{
    cerr << "{";
    bool f = 0;
    for (auto &x : s)
    {
        if (f)
            cerr << ", ";
        f = 1;
        _print(x);
    }
    cerr << "}";
}
template <typename K, typename V>
void _print(const map<K, V> &m)
{
    cerr << "{";
    bool f = 0;
    for (auto &kv : m)
    {
        if (f)
            cerr << ", ";
        f = 1;
        _print(kv);
    }
    cerr << "}";
}

#define dbg(x) cerr << #x << " = ", _print(x), cerr << "\n"
#else
#define dbg(x) ((void)0)
#endif

// ---------- constants ----------
const ll INFLL = (ll)4e18;
const int INF = (int)2e9;

// ---------- math helpers ----------
ll gcdll(ll a, ll b) { return std::gcd(a, b); }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

ll modpow(ll a, ll e, ll mod)
{
    ll r = 1 % mod;
    a %= mod;
    while (e > 0)
    {
        if (e & 1)
            r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

// ---------- IO helpers ----------
template <typename T>
void read_vec(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}

template <typename T>
void print_vec(const vector<T> &v, char sep = ' ')
{
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (i)
            cout << sep;
        cout << v[i];
    }
    cout << "\n";
}

// ---------- solve ----------
void build(vector<int>& v, vector<int>& tree, int l, int r, int node){
    if(l == r){
        tree[node] = v[l];
        return;
    }

    int mid = l + (r - l) / 2;

    build(v,tree, l,mid,2*node+1);
    build(v, tree,mid+1,r,2*node+2);

    tree[node] = min(tree[2*node+1], tree[2*node+2]);
    
}

int find(vector<int>& tree, int i, int j, int l, int r,int node){

    if(j < l || r < i){
        return INT_MAX;
    }

    if(i<= l && r <= j){
        return tree[node];
    }

     int mid = l + (r - l) / 2;

    return min(
        find(tree, i, j, l, mid, 2*node+1),
        find(tree, i, j, mid+1, r, 2*node+2)
    ); 
}

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    read_vec(v);
    vector<int> tree(4*n);
   build(v,tree,0,n-1, 0);


    int l,r;
    vector<int> res;
    for(int i=0; i < q; i++){
        cin>>l>>r;
        l--;
        r--;

        int ans = find(tree, l, r, 0,n-1,0);
    
        res.push_back(ans);
    }

    print_vec(res,'\n');
}

// ---------- main ----------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    while (T--)
        solve();

    return 0;
}
