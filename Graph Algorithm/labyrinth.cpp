 /*
    Author: soju-jsh
    Created: 03/07/24
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*
    Labyrinth
    https://cses.fi/problemset/task/1193
    
    Result: AC
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

void trace_path(pll from, pll to, vector<vector<pll>> &trace){
    map<int, map<int, char>> movement = {
        { 0, {{1, 'R'}, {-1, 'L'}}},
        { 1, {{0, 'D'}}},
        {-1, {{0, 'U'}}}
    };

    ll cx = to.first;
    ll cy = to.second;

    string path = "";
    ll degree = 0;

    while (true)
    {
        path += movement[cy - trace[cy][cx].second][cx - trace[cy][cx].first];
        ll ccx = cx;
        cx = trace[cy][cx].first;
        cy = trace[cy][ccx].second;
        ++degree;

        if(cx == from.first && cy == from.second)
            break;
    }

    cout << degree << '\n';
    reverse(path.begin(), path.end());
    cout << path;

    return;
}

void dfs(vector<string> &mapa, pll position, pll target, ll rows, ll cols){
    vector<vector<int>> vis(rows, vector<int>(cols));
    vector<vector<pll>> trace(rows, vector<pll>(cols));

    deque<pll> line;
    line.push_back(position);

    bool rchble = false;
    while (!line.empty()) {
        pll pos = line.front();
        line.pop_front();

        if (!vis[pos.second][pos.first]){
            vis[pos.second][pos.first] = 1;
            
            for (pll nb : neighbors(mapa, pos, rows, cols)){
                if(!vis[nb.second][nb.first]){
                    line.push_back(nb);
                    trace[nb.second][nb.first] = pos;

                    if (nb.first == target.first and nb.second == target.second){
                        rchble = true;
                        line.clear();
                        break;
                    }
                }
            }
        }
    }

    if (!rchble){
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES\n";
        trace_path(position, target, trace);
        return ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m; cin >> n >> m;
    vector<string> mapa(n);

    pll start, end;
    for (ll i = 0; i < n; i++){
        cin >> mapa[i];
        for (ll j = 0; j < m; j++){
            if(mapa[i][j] == 'A')
                start = make_pair(j, i);
            if(mapa[i][j] == 'B')
                end = make_pair(j, i);
        }
    }

    dfs(mapa, start, end, n, m);
}