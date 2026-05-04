// LC: 0000 Tree Matching
// Title: Tree Matching
// Difficulty: Hard
// Date: 04 May 2026

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

int rec(vector<vector<int>>& v, int i, bool takechild, int parent, vector<vector<int>>& dp){

    
    if(dp[i][takechild] != -1){
        return dp[i][takechild];
    }
    int ans = 0;
    int sum = 0;

    for(auto c: v[i]){
        if(c == parent) continue;

        sum += max(rec(v,c,true, i,dp),rec(v,c,false, i,dp));
    }
    ans = sum;


    //take child
    if(takechild){

    for(auto c: v[i]){
        if(c == parent) continue;

        int val = 1 + rec(v,c,false, i,dp);

        
        int mx = max(rec(v,c,true, i,dp),rec(v,c,false, i,dp));


        ans = max(ans, val+sum-mx);
    }
}


    return dp[i][takechild] = ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    vector<vector<int>> dp(n+1, vector<int>(2,-1));
    int a,b;
    for(int i=0; i< n-1;i++){
        cin>>a>>b;
        v[a-1].push_back(b-1);
         v[b-1].push_back(a-1);
    }

    int ans = 0;

    for(int i=0; i < n; i++){
        ans = max(ans, rec(v,i,true, -1,dp));
        ans = max(ans, rec(v,i,false, -1,dp));
    }



    cout<<ans<<endl;

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
