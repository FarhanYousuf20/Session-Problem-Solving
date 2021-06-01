#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define deb(x)                  cerr << #x << " = " << x << endl
#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define f0(i, a, n)             for(i = a; i < n; i++)
#define f1(i, a, n)             for(i = a; i <= n; i++)
#define ini(x, y)               memset(x, y, sizeof(x))
#define all(x)                  x.begin(), x.end()
#define sz(x)                   x.size()
#define ll                      long long int
#define ull                     unsigned long long int
#define pb                      push_back
#define ppb                     pop_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define M                       1000000007
#define endl                    '\n'
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define vi                      vector<int>
#define pii                     pair<int,int>
#define vpii                    vector<pii>
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define maxHeap                 priority_queue<int>

const int N = 1e5 + 1;
const int MX = 1e9 + 10;
const ll INF = 1e18;

using namespace std;
using namespace __gnu_pbds;

inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
inline ll mod(ll x) {return ( (x % M + M) % M );}

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

ll power(ll a, ll b) {
        ll res = 1;
        while (b) {
                if (b & 1) res = res * a % 1000;
                a = a * a % 1000;
                b >>= 1;
        }
        return res;
}

void solve() {
        ll n, k;
        cin >> n >> k;

        // formula : 
        // n ^ k = x.yz... * 10 ^ p, here p is some integer
        // log10(n ^ k) = log10(x.yz * 10 ^ p)
        // log10(n ^ k) = log10(x.yz) + log10(10 ^ p)
        // log10(n ^ k) = log10(x.yz) + p, here log10(10) = 1;
        // log(x.yz) = log10(n ^ k) - p
        // log(x.yz) = log10(n ^ k) - int value of log10(n ^ k), here p = total_digit - 1 ans total_digit = log(n ^ k) + 1
        // log(x.yz) = tmp, let's assume tmp = log10(n ^ k) - (int)log10(n ^ k)
        // x.yz = 10 ^ tmp
        // ans (int)x.yz * 100 is our desired result
        double log_double = k * (double)log10(n);
        ll log_int = k * log10(n);
        double tmp = log_double - log_int;
        ll first_3_digit = pow(10.00, tmp) * 100;

        // just we take (product % 1000)
        ll last_3_digit = power(n, k);
        string tmp2 = to_string(last_3_digit);
        if(tmp2.size() == 1) tmp2 = "00" + tmp2;
        else if(tmp2.size() == 2) tmp2 = "0" + tmp2;

        cout << first_3_digit << " " << tmp2 << endl;
}

int main () {
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