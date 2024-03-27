/*
    Author: soju-jsh
    Created: 03.28.24
 
    Problem: https://cses.fi/problemset/task/1070/
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
#define cREP(i, ii, t, increment) for (ll i = ii; i < t; i += increment)
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
    
    ll N; 
    cin >> N;

    if (1 < N and N <= 3) cout << "NO SOLUTION";
    else
    {
        cREP(i, N % 2 ? 1 : 2, N + 1, 2) cout << i << wp;
        cREP(i, N % 2 ? 2 : 1, N    , 2) cout << i << wp;
    }
}