/*
    Author: JN.Wang
    Created: 03/07/24
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;

/*
    Building Roads
    https://cses.fi/problemset/task/1666
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m; cin >> n >> m;
    vector<vll> nbs(n + 1);
    
    for (int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        nbs[a].push_back(b);
        nbs[b].push_back(a);
    }

    vll vis(n + 1);
    vector<vll> components;
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;

        deque<ll> line;
        line.push_back(i);
        vll nodes;
        while (!line.empty()){
            ll city = line.back();
            line.pop_back();
            if(!vis[city]){
                vis[city] = true;
                nodes.push_back(city);

                for (auto nb : nbs[city]){
                    if(!vis[nb]){
                        line.push_back(nb);
                    }
                }
            }
        } components.push_back(nodes);
    }

    cout << components.size() - 1 << '\n';
    for (int i = 1; i < components.size(); i++){
        cout << components[i - 1].back() << ' ' << components[i].front() << '\n';
    }
}