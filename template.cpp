/*
    Author: soju-jsh
    Created: 03.29.24
 
    Problem: https://cses.fi/problemset/task/1072
    Result: AC
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// // Datatype Shortcuts
using ll = long long;
using sll = set<ll>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vs = vector<string>;
using usll = unordered_set<ll>;
using usll = unordered_set<ll>;
using pqll = priority_queue<ll>;

template<typename T1, typename T2>
using um = unordered_map<T1, T2>;

// Chars
#define nl '\n'
#define wp ' '
#define INF INT_MAX
#define MOD 1'000'000'007

// Macros
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define REP(i, ii, t) for (ll i = ii; i < t; i++)
#define rREP(i, t) for (ll i = t; i >= 0; i--)
#define array_cin(arr) for (auto &i : arr) cin >> i;
#define test_case() ll tt; cin >> tt; while (tt--)

// Debugging purposes (if iterable)
#define h_display(arr) {for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << wp; cout << nl;}
#define v_display(arr) {for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << nl;}

// FastIO
void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

const string file_name = "io";

int main(){

    // freopen((file_name + ".in").c_str(), "r", stdin);
    // freopen((file_name + ".out").c_str(), "w", stdout);

    fastIO();
}