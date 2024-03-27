/*
    Author: soju-jsh
    Created: 03.28.24
 
    Problem: https://cses.fi/problemset/task/1083
    Result: AC
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Datatype Shortcuts
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
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
#define get_REP() ll tt; cin >> tt; while (tt--)
 
// Debugging purposes
#define display(arr) for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << wp; cout << nl;
 
void fast(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
 
int main(){
    fast();
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    auto arithmetic_sum = [](ll u_bound) -> ll {
        return (u_bound + 1) * u_bound / 2 ;
    };
 
    ll N; 
    cin >> N;
 
    ll e, expected = arithmetic_sum(N);
    REP(i, 0, N - 1) {
        cin >> e;
        expected -= e;
    }
    
    cout << expected;
}