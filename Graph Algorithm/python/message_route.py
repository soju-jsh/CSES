"""
    Author: soju-jsh
    Created: 03/08/24
"""

from sys import stdin,stdout
input = stdin.readline
# print = stdout.write

'''
    Message Route
    https://cses.fi/problemset/task/1667
'''

from collections import deque

def track_connection(tracks, n):
    path = []
    cursor = n
    while not cursor == 1:
        path.append(cursor)
        cursor = tracks[cursor]
    
    path.append(1)
    path.reverse()
    
    print(len(path))
    print(*path)
        
def main():
    n, m = map(int, input().split())
    
    connections = {i: [] for i in range(1, n + 1)}
    for _ in range(m):
        a, b = map(int, input().split())
        connections[a].append(b)
        connections[b].append(a)
        
    checked = [False for _ in range(n + 1)]
    track = [None for _ in range(n + 1)]
    
    checklist = deque()
    checklist.append(1)
    checked[1] = True
    
    while checklist:
        pc = checklist.popleft()
        for nb in connections[pc]:
            if not checked[nb]:
                checklist.append(nb)
                checked[nb] = True
                
                track[nb] = pc
                if nb == n:
                    track_connection(tracks=track, n=n)
                    return
    
    print("IMPOSSIBLE")
        
if __name__ == "__main__":
    main()
    