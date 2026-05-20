// LC: Traffic Lights
// Title: Lights
// Difficulty:
// Date: 20 May 2026

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
void solve()
{
    int x,n;
    cin>>x>>n;
    set<int> lights;
multiset<int> gaps;
    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);
    int temp;
    for(int i=0; i < n;i++){


        cin>>temp;
        auto it1 = lights.upper_bound(temp);
        auto it2 = it1;
        it2--;
        // cout<<gaps.find(*it1 - *it2) - gaps.begin()<<endl;
        gaps.erase(gaps.find(*it1 - *it2));
        gaps.insert(*it1 - temp);
        gaps.insert(temp - *it2);
        lights.insert(temp);
        auto ans = gaps.end();
        ans--;

        //         for(auto it: gaps){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        cout<<*ans<<endl;
    }

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