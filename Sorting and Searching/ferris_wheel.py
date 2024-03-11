"""
    Author: soju-jsh
    Created: 03/09/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    https://cses.fi/problemset/task/1090
'''

def main():
    n, x = map(int, input().split())
    weights = sorted([int(x) for x in input().split()])
    
    gondolas, l, r = 0, 0, n - 1
    while l <= r:
        l += 1 if weights[l] + weights[r] <= x else 0
        r -= 1
        gondolas += 1
        
    print(gondolas)
        
if __name__ == "__main__":
    main()
    