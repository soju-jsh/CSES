/*
    Author: JN.Wang
    Created: 03/07/24
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*
    Counting Rooms
    https://cses.fi/problemset/task/1192
*/

vector<pll> neighbors(vector<string> &mapa, pll position, ll rows, ll cols){
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<pll> nbs;

    for (int i = 0; i < 4; i++){
        ll newX = position.first + dx[i];
        ll newY = position.second + dy[i];
        
        if (newX >= 0 && newX < cols && newY >= 0 && newY < rows){
            if (mapa[newY][newX] != '#'){
                nbs.push_back(make_pair(newX, newY));
            }
        }
    }

    return nbs;
}

void dfs(vector<string> &mapa, pll position, vector<vector<int>> &vis, ll rows, ll cols){
    stack<pll> line;
    line.push(position);

    while (!line.empty()) {
        pll pos = line.top();
        line.pop();

        if (!vis[pos.second][pos.first]){
            vis[pos.second][pos.first] = 1;
            for (pll nb : neighbors(mapa, pos, rows, cols)){
                if(!vis[nb.second][nb.first])
                    line.push(nb);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m; cin >> n >> m;
    vector<string> mapa(n);
    for (auto &row : mapa)
        cin >> row;

    vector<vector<int>> vis(n, vector<int>(m));
    ll rooms = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mapa[i][j] != '#' && !vis[i][j]){
                dfs(mapa, make_pair(j, i), vis, n, m);
                ++rooms;
            }
        }
    }
    cout << rooms;
}