/*
    Author: soju-jsh
    Created: 3.12.24

    Problem: https://cses.fi/problemset/task/1661
    Result: AC
*/

#include <bits/stdc++.h>
using namespace std;

// Datatype Shortcuts
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
 
// Chars
#define nl '\n'
#define wp ' '
 
// Macros
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define REP(i, ii, t) for (ll i = ii; i < t; i++)
#define rREP(i, t) for (ll i = t - 1; i >= 0; i--)
#define vll_cin(arr) for (auto &i : arr) cin >> i;
#define test_case() ll tt; cin >> tt; while (tt--)

// Debugging purposes
#define display(arr) for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << wp; 

void fast(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fast();

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, x; 
    cin >> n >> x;
    vll seq(n); 
    vll_cin(seq);

    ll cnt = 0;
    
    unordered_map<ll, ll> ss;
    ll total = 0;
    REP(i, 0, n){
        total += seq[i];
        if (total == x) cnt++;
        if (ss[total - x]) cnt += ss[total - x];
        ss[total]++;
    }

    cout << cnt;
}