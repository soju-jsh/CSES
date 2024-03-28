/*
    Author: soju-jsh
    Created: 03.28.24
 
    Problem: https://cses.fi/problemset/task/1092/
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
    
    // Arithmetic Sum
    auto a_sum = [](ll uBound) -> ll {
        return (uBound * uBound + uBound) / 2;
    };

    ll N, sum, half_sum; 
    cin >> N;
    
    sum = a_sum(N);
    half_sum = sum / 2;

    if (sum % 2) cout << "NO";
    else
    {
        ll size_second = 0, pointer = N;
        vll first_set(N + 1);

        while (half_sum){
            size_second++;
            if (pointer <= half_sum){
                half_sum -= pointer;
                first_set[pointer--] = true;
            } else {
                first_set[half_sum] = true;
                break;
            }
        }

        // OUTPUT
        cout << "YES" << nl;

        cout << N - size_second << nl;
        REP(i, 1, (ll)first_set.size()) if (!first_set[i]) cout << i << wp; cout << nl; 

        cout << size_second << nl;
        REP(i, 1, (ll)first_set.size()) if (first_set[i]) cout << i << wp;
    }
}