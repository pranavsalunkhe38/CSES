// LC: 0000 Book Shop
// Title: Book Shop
// Difficulty: Medium
// Date: 16 July 2026

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

// ---------- constants ----------
const ll INFLL = (ll)4e18;
const int INF = (int)2e9;

// ---------- IO helpers ----------
template <typename T>
void read_vec(vector<T> &v)
{
    for (auto &x : v)
        cin >> x;
}

// ---------- solve ----------
void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);

    read_vec(prices);
    read_vec(pages);

    // dp[money] = maximum pages obtainable with budget 'money'
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // Traverse backwards to ensure each book is used at most once
        for (int money = x; money >= prices[i]; money--)
        {
            dp[money] = max(dp[money],
                            dp[money - prices[i]] + pages[i]);
        }
    }

    cout << dp[x] << '\n';
}

// ---------- main ----------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}