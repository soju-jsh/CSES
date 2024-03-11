"""
    Author: JN.Wang
    Created: 03/08/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    Round Trip
    https://cses.fi/problemset/task/1669
'''
from collections import deque

def dfs(connections, pos=1):
    vis = [False for _ in range(len(connections) + 1)]
    prev = [None for _ in range(len(connections) + 1)]
    
    vis[pos] = True
    prev[pos] = pos
    stack = deque([pos])
    while stack:
        city = stack.popleft()
        
        for nb in connections[city]:
            if nb == prev[city]:
                continue
            
            if not vis[nb]:
                stack.append(nb)
                prev[nb] = city
                vis[nb] = True
                # print(f"GOING {nb} FROM {city}")
            else:
                # print(f"INTERSECTION AT {nb}, TRIED FROM {city}")
                prev[nb] = [prev[nb], city]
                return [prev, nb]
    
    return [], None
    
def analyze(prev, x):
    # let X be the intersection point
    
    d1, d2 = prev[x]
    
    path1_all = [x, d1]
    path1 = []
    path2 = [d2]
    
    while d1 > 1:
        path1_all.append(prev[d1])
        d1 = prev[d1]
        
    while d2 > 1:
        path2.append(prev[d2])
        d2 = prev[d2]
        if prev[d2] in path1_all:
            break
    
    x2 = path1_all.index(path2[-1])
    for _ in range(x2 + 1):
        path1.append(path1_all[_])
    
    path2.reverse()
    path2.extend(path1)
    
    print(len(path2))
    print(*path2)
     
def main():
    n, m = map(int, input().split())
    connections = {i: [] for i in range(1, n + 1)}
    for _ in range(m):
        a, b = map(int, input().split())
        connections[a].append(b)
        connections[b].append(a)
    
    path, intersecton = dfs(connections=connections)
    if path:
        analyze(prev=path, x=intersecton)
    else:
        print("IMPOSSIBLE")
        
if __name__ == "__main__":
    main()
    