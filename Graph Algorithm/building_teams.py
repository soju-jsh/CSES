"""
    Author: JN.Wang
    Created: 03/07/24
"""

from sys import stdin,stdout
input = stdin.readline
# print = stdout.write

'''
    Building Teams
    https://cses.fi/problemset/task/1668
'''

from collections import deque

def bfs(connections, groups, parent, vis):
    stack = deque([parent])
    prev = [None for _ in range(len(connections) + 1)]
    prev[parent] = parent
    
    while stack:
        person = stack.pop()
        
        for friend in connections[person]:
            if friend == prev[friend]:
                continue
            
            if groups[friend] == groups[person]:
                return []

            if not groups[friend]:
                groups[friend] = groups[person] ^ 3
                prev[friend] = person
                stack.append(friend)
                
    return vis

def main():
    n, m = map(int, input().split())
    
    connections = {i: [] for i in range(1, n + 1)}
    for _ in range(m):
        a, b = map(int, input().split())
        connections[a].append(b)
        connections[b].append(a)
        
    groups = [0] * (n + 1)
    groups[1] = 1
    
    vis = [False for _ in range(n + 1)]
    for i in range(1, n + 1):
        if not vis[i]:
            result = bfs(connections=connections, groups=groups, parent=i, vis=vis)
            if not result:
                print("IMPOSSIBLE")
                return
            else:
                vis[i] = result
        
    groups.pop(0)
    [print(group, end=' ') for group in groups]
        
if __name__ == "__main__":
    main()
    