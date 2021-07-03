#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define deb(x)                  cerr << #x << " = " << x << endl
#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define ll                      long long int
#define ull                     unsigned long long int
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define ini(x, y)               memset(x, y, sizeof(x))
#define all(x)                  x.begin(), x.end()
#define all2(x)                 x.rbegin(), x.rend()
#define sz(x)                   x.size()
#define pb                      push_back
#define ppb                     pop_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define M                       1000000007
#define endl                    '\n'
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define vl                      vector<ll>
#define pll                     pair<ll,ll>
#define vpll                    vector<pll>
#define uni(x)                  x.erase(unique(all(x)), x.end())
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>

const int N = 2e5 + 5;
const int L = 20;
const int MX = 1e9 + 10;
const ll INF = 1e18;

const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

using namespace std;
using namespace __gnu_pbds;

inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
inline ll mod(ll x) {return ( (x % M + M) % M );}
ll power(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
ll modpow(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}

#ifndef ONLINE_JUDGE
#define done cerr << "Line " << __LINE__ << " is done" << endl;
#else
#define done
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for(auto& x : v) os << x << " "; return os << '\n';}
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {for(auto& x : v) os << x << " "; return os << '\n';}
template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& p) {os << p.first << ' ' << p.second << '\n'; return os;}
template<typename... T> void in(T&... args) {((cin >> args), ...);}
template<typename... T> void out(T&&... args) {((cout << args << endl), ...);}
template<typename... T> void out2(T&&... args) {((cout << args << " "), ...);}
template<typename... T> void out3(T&&... args) {((cout << args << " "), ...); cout << endl;}

vector<vector<ll>> a;
vector<ll> dp;
ll n;

ll cost(ll subcost) {
        if(subcost == (1 << n) - 1) return 0;
        if(dp[subcost] != -1) return dp[subcost];

        ll mn = MX;
        for(ll i = 0; i < n; i++) {
                if((subcost & (1 << i)) == 0) {
                        ll tot = a[i][i];
                        for(ll j = 0; j < n; j++) {
                                if(i == j) continue;
                                if(subcost & (1 << j)) tot += a[i][j];
                        }
                        mn = min(mn, tot + cost(subcost | (1 << i)));
                        // deb(tot);
                }
        }
        return dp[subcost] = mn;
}

void solve() {
        cin >> n;
        a = vector<vector<ll>>(n, vector<ll>(n));
        for(ll i = 0; i < n; i++) {
                for(ll j = 0; j < n; j++) {
                        cin >> a[i][j];
                }
        }

        dp = vector<ll>((1 << 15), -1);
        cout << cost(0) << endl;
}

signed main () {
        #ifndef ONLINE_JUDGE
                // freopen("input.txt", "r", stdin);
                // freopen("output.txt", "w", stdout);
        #endif
        FIO; //don't use when getting input from file
        TC(t) {
                cout << "Case " << i << ": ";
                solve();
        }
        return 0;
}