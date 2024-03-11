"""
    Author: JN.Wang
    Created: 03/10/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    https://cses.fi/problemset/task/1091
'''

from bisect import bisect_right

def main():
    n, m = map(int, input().split())
    
    ticket_prices = sorted([int(x) for x in input().split()])
    max_prices = [int(x) for x in input().split()]
    
    used = [False for _ in range(m + 2)]
    for _ in range(m):
        ticket = bisect_right(ticket_prices, max_prices[_]) - 1
        
        while ticket > 0 and used[ticket] is True:
            ticket -= 1
        
        if ticket <= -1:
            print(ticket)
        elif ticket_prices[ticket] <= max_prices[_] and used[ticket] is False:
            print(ticket_prices[ticket])
            used[ticket] = True
        else:
            print(-1)
        
if __name__ == "__main__":
    main()
    