/*
    Author: soju-jsh
    Created: 03.28.24
 
    Problem: https://cses.fi/problemset/task/1624
    Result: AC
*/
 
#include <bits/stdc++.h>
using namespace std;
 
// Datatype Shortcuts
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using usll = unordered_set<ll>;
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
#define array_cin(arr) for (auto &i : arr) cin >> i;
#define get_REP(tt) ll tt; cin >> tt; while (tt--)

// Debugging purposes
#define display(arr) for (auto i = arr.begin(); i != arr.end(); i++) cout << *i << wp; cout << nl;

// FastIO
void fast(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
}

vs board(8);

void backtrack(ll &ways, ll start, ll row = 0, vb col_taken = vb(8, false), usll diag1 = {}, usll diag2 = {}){
    if (row == 7 and ways++)
        return;

    col_taken[start] = true;
    usll new_d1, new_d2;

    for (auto c : diag1) if (c + 1  < 8) new_d1.insert(c + 1);
    for (auto c : diag2) if (c - 1 >= 0) new_d2.insert(c - 1);

    if (start + 1 < 8) new_d1.insert(start + 1);
    if (start - 1 >= 0) new_d2.insert(start - 1);
    
    REP(i, 0, 8)
        if (!new_d1.count(i) and !new_d2.count(i) and !col_taken[i])
            if (board[row + 1][i] == '.')
                backtrack(ways, i, row + 1, col_taken, new_d1, new_d2);
}

int main(){
    fast();

    array_cin(board);

    ll ways = 0;
    REP(i, 0, 8)
        if (board.front()[i] == '.')
            backtrack(ways, i);

    cout << ways << endl;
}