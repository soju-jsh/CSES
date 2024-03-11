"""
    Author: JN.Wang
    Created: 03/09/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    https://cses.fi/problemset/task/1621
'''
        
def main():
    n = int(input())
    print(len({x for x in input().split()}))
        
if __name__ == "__main__":
    main()
    