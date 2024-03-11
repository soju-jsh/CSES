#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;

    list<char> container;
    auto cursor = container.begin();

    for (auto c : s){
        if (c == 'L'){
            --cursor;
        } else if (c =='R'){
            ++cursor;
        } else if (c == 'B'){
            cursor--;
            cursor = container.erase(cursor);
        } else {
            container.insert(cursor, c);
        }
    }

    auto c2 = container.begin();
    for (c2; c2 != container.end(); c2++)
        printf("%c", *c2);
    putchar('\n');
}