/*
    Author: soju-jsh
    Created: 03.29.24
 
    Problem: https://cses.fi/problemset/task/1072
    Result: AC
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Datatype Shortcuts
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vs = vector<string>;
using usll = unordered_set<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using pqii = priority_queue<int>;
using pqll = priority_queue<ll>;

// Chars
#define nl '\n'
#define wp ' '
#define INF INT_MAX
#define MOD (ll)1e9 + 7

// Macros
#define all(x) x.begin(), x.end()
#define REP(i, ii, t) for (ll i = ii; i < t; i++)
#define rREP(i, t) for (ll i = t - 1; i >= 0; i--)
#define array_cin(arr) for (auto &i : arr) cin >> i;
#define test_case() ll tt; cin >> tt; while (tt--)

// Debugging purposes
#define display(arr) {for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << wp; cout << nl;}

// FastIO
#pragma GCC diagnostic ignored "-Wunused-result"
void fast(string file_name = ""){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (file_name.size()){
        freopen((file_name + ".in").c_str(), "r", stdin);
        freopen((file_name + ".out").c_str(), "w", stdout);
    }
}

int main(){
    fast();

    ll N;
    cin >> N;

    cout << 0 << nl;
    REP(i, 2, N + 1)
        cout << (i * i) * (i * i - 1) / 2 - (4 * (i - 2) * (i - 1)) << nl;
}