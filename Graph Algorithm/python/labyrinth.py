"""
    Author: soju-jsh
    Created: 03/07/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    Labyrinth
    https://cses.fi/problemset/task/1193
    
    Description:
        >   You are given a map of a labyrinth, 
            and your task is to find a path from start to end.
            
        >   You can walk left, right, up and down.
'''

from collections import deque

def neighbor(pos, mapa, n, m):
    x, y = pos
    
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    
    nbs = []
    for _ in range(4):
        new_x = x + dx[_]
        new_y = y + dy[_]
        
        if 0 <= new_x < m and 0 <= new_y < n:
            if mapa[new_y][new_x] != '#':
                nbs.append((new_x, new_y))
                
    return nbs

def trace_path(path_to, traces):
    path = []
    x, y = path_to
    cnt = 0
    while traces[y][x] is not None:
        (x, y), _ = traces[y][x]
        path.insert(0, _)
        cnt += 1
    
    print("YES")
    print(cnt)
    print(*path, sep='')

def ulod(pos, mapa, n, m):
    stack = deque()
    stack.append(pos)
    
    vis = [[False for j in range(m)] for i in range(n)]
    prev = [[None for j in range(m)] for i in range(n)]
    movement = {
         0 : { 1 : 'R', -1 : 'L' }, 
         1 : { 0: 'D' }, 
        -1 : { 0: 'U' }
    }
    
    x, y = pos
    vis[y][x] = True
    while stack:
        x, y = stack.popleft()
        for xx, yy in neighbor(pos=(x, y), mapa=mapa, n=n, m=m):
            if not vis[yy][xx]:
                vis[yy][xx] = True
                stack.append((xx, yy))
                prev[yy][xx] = (x, y), movement[yy - y][xx - x]
                
                if mapa[yy][xx] == 'B': 
                    trace_path(path_to=(xx, yy), traces=prev)
                    return
    
    print("NO")
    
        
def main():
    n, m = map(int, input().split())
    mapa = []
    
    # Find Start
    start = 0, 0
    found_start = False
    for i in range(n):
        mapa.append(input().strip())
        if not found_start and 'A' in mapa[i]:
            start = mapa[i].index('A'), i
            
    ulod(pos=start, mapa=mapa, n=n, m=m)

if __name__ == "__main__":
    main()