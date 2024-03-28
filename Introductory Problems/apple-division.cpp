/*
    Author: soju-jsh
    Created: 03.28.24
 
    Problem: https://cses.fi/problemset/task/1623
    Result: AC
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Datatype Shortcuts
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using tll = tuple<ll,ll,ll>;

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
#define get_REP(tt) ll tt; cin >> tt; while (tt--)

// Debugging purposes
#define display(arr) for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << wp; cout << nl;
 
void fast(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

ll min_difference(ll max_apples, vll &weights, ll apple = 0, ll basket1 = 0, ll basket2 = 0)
{
    if (apple == max_apples) 
        return abs(basket1 - basket2);

    return min(
        min_difference(max_apples, weights, apple + 1, basket1 + weights[apple], basket2),
        min_difference(max_apples, weights, apple + 1, basket1, basket2 + weights[apple])
    );
}

int main(){
    fast();
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll N; 
    cin >> N; 

    vll weights(N);
    vll_cin(weights);

    cout << min_difference(N, weights) << endl;
}