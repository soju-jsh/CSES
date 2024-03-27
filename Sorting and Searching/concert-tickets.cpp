/*
    Author: soju-jsh
    Created: 03.28.24

    Problem: https://cses.fi/problemset/task/1091

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
#define test_case() ll tt; cin >> tt; while (tt--)

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
    
    ll n, m; 
    cin >> n >> m;

    multiset<ll> tickets;
    REP(i, 0, n) {
        ll price; cin >> price;
        tickets.emplace(price);
    }

    REP(i, 0, m) {
        ll willing_price; cin >> willing_price;

        auto match = tickets.lower_bound(willing_price);
        if (tickets.empty() or (*match > willing_price and match == tickets.begin())) cout << -1 << nl;
        else
        {
            if (*match != willing_price) match--;
            cout << *match << nl;
            tickets.erase(match);
        }
    }
}