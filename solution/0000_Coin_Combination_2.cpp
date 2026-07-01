// LC: 0000 Coin Combination 2
// Title: Coin Combination 2
// Difficulty: medium
// Date: 01 July 2026

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
const int mod = 1000000007;

int rec(vector<int>& v, vector<vector<int>>& dp, int i, int x){
    if(x == 0){
        return 1;
    }
    if(i == v.size()) return 0;

    if(dp[i][x] != -1){
        return dp[i][x];
    }

    int ans = rec(v,dp,i+1,x); // not take
    if(x >= v[i])
        ans = (ans + rec(v,dp, i, x - v[i])) % mod;
    

    return dp[i][x] = ans;
}
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    read_vec(v);
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i = 0; i <= n; i++){
        dp[i][0]= 1;
    }

    for(int i=n-1; i >= 0;i--){
        for(int j = 1; j <= x; j++){

            int ans = dp[i+1][j];

            if(v[i] <= j){
                ans = (ans +  dp[i][j - v[i]]) % mod;
            }

            dp[i][j] = ans;

        }
    }
    cout<<dp[0][x];

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

/*
    FILE* in = freopen("../test_input-2.txt", "r", stdin);

    if (!in) {
        cerr << "Could not open test_input-2.txt\n";
        return 1;
    }

    FILE* out = freopen("../output.txt", "w", stdout);

    if (!out) {
        cerr << "Could not open output.txt\n";
        return 1;
    }

    */