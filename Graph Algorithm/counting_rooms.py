"""
    Author: JN.Wang
    Created: 03/07/24
"""

from sys import stdin
cin = stdin.readline

'''
    Counting Rooms
    https://cses.fi/problemset/task/1192

    Description:
        >   You are given a map of a building, 
            and your task is to count the number of its rooms. 
            
        >   The size of the map is n x m squares, 
            and each square is either floor or wall. 
            
        >   You can walk left, right, up, and down through the floor squares.

'''

from collections import deque

def neighbor(position, mapa):
    x, y = position
    nbs = []
    
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    
    for _ in range(4):
        new_x = x + dx[_]
        new_y = y + dy[_]
        
        if 0 <= new_x < m and 0 <= new_y < n:
            if mapa[new_y][new_x] != '#':
                nbs.append((new_x, new_y))
        
    return nbs

def dfs(pos, mapa):
    stack = deque()
    stack.append(pos)
    
    while stack:
        x, y = stack.pop()
        if not visited[y][x]:
            visited[y][x] = True
            for xx, yy in neighbor(position=(x, y), mapa=mapa):
                if not visited[yy][xx]:
                    stack.append((xx, yy))

def main():
    global n, m, visited
    n, m = map(int, input().split())
    mapa = [input().strip() for _ in range(n)]
    visited = [[False for j in range(m)] for i in range(n)]
    
    count = 0
    for i in range(n):
        for j in range(m):
            if not visited[i][j] and mapa[i][j] != '#':
                pos = (j, i)
                dfs(pos=pos, mapa=mapa)
                count += 1
    
    print(count)
        
if __name__ == "__main__":
    main()
    