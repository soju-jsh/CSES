"""
    Author: soju-jsh
    Created: 03/09/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    https://cses.fi/problemset/task/1084
'''
        
def main():
    n, m, k = map(int, input().split())
    people = sorted([int(x) for x in input().split()])
    apartments = sorted([int(x) for x in input().split()])
    
    accepted, cursor = 0, 0
    for desired in people:
        while cursor < m - 1 and apartments[cursor] < desired and abs(desired - apartments[cursor]) > k:
            cursor += 1
            
        if abs(desired - apartments[cursor]) <= k:
            accepted += 1
            cursor += 1
            
        if cursor == m:
            break
        
    print(accepted)
        
if __name__ == "__main__":
    main()
    