// LC: 0000 Building Roads
// Title: Building Roads
// Difficulty: Easy
// Date: 29 April 2026

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


void rec(vector<vector<int>>& v, vector<bool>& vis, int i){
    vis[i] = true;

    for(auto x: v[i]){
        if(vis[x] == false)
            rec(v,vis, x);
    }

}
// ---------- solve ----------
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> v(n);
    vector<bool> vis(n,false);

    int a, b;
    for(int i=0; i < m ; i++){
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> ans;

    for(int i=0; i < n; i++){
        if(vis[i] != true){
            ans.push_back(i+1);
            rec(v,vis,i);
        }
    }

    cout<<ans.size()-1<<endl;
    for(int i=1; i < ans.size(); i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }

    
}

// ---------- main ----------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--)
        solve();

    return 0;
}
