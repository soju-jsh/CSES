"""
    Author: soju-jsh
    Created: 03/07/24
"""

from sys import stdin
cin = stdin.readline

'''
    Building Roads
    https://cses.fi/problemset/task/1666
'''
        
def main():
    n, m = map(int, cin().split())
    
    neighbors = {i : [] for i in range(1, n + 1)}
    for road in range(1, m + 1):
        city_a, city_b = map(int, cin().split())
        neighbors[city_a].append(city_b)
        neighbors[city_b].append(city_a)
            
    visited = [False] * (n + 1)
    components = []
    for _ in range(1, n + 1):
        if visited[_]:
            continue
        
        stack = [_]
        node = []
        while stack:
            city = stack.pop()
            if not visited[city]:
                visited[city] = True
                node.append(city)
                
                for w in neighbors[city]:
                    if not visited[w]:
                        stack.append(w)
        
        components.append(node)

    print(len(components) - 1)
    for road in range(1, len(components)):
        print(components[road - 1][-1], components[road][0])
        
if __name__ == "__main__":
    main()
    