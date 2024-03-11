"""
    Author: JN.Wang
    Created: 03/08/24
"""

from sys import stdin,stdout
input = stdin.readline
# print = stdout.write

'''
    Minimizing Coins
    https://cses.fi/problemset/task/1634
'''

def ks(n, desired, coins):
    table = [[[] for j in range(desired + 1)] for i in range(n + 1)]
    
    for i in range(n + 1):
        for j in range(desired + 1):
            if i == 0 or j == 0:
                continue
            
            c = coins[i - 1]
            
            if c <= j:
                if sum(table[i - 1][j - c] + [c]) == j or sum(table[i][j - c] + [c]) == j:
                    options = [table[i][j - c] + [c]]
                    if table[i - 1][j]:
                        options.append(table[i - 1][j])
                    if table[i - 1][j - c]:
                        options.append(table[i - 1][j - c] + [c])
                        
                    table[i][j] = min(options, key=lambda x : len(x))
                    continue
            
            table[i][j] = table[i - 1][j]
    # Debug
    # [print(_) for _ in table]
    if table[-1][-1]:
        return len(table[-1][-1])
    else:
        return False
        
def main():
    n, desired = map(int, input().split())
    coins = sorted([int(x) for x in input().split()], reverse=True)
    
    hi = coins[0]
    
    if hi == 1:
        print(desired // hi)
        return
    
    if desired == hi:
        print(1)
        return
    
    count = 0
    if desired > hi:
        count = (desired - coins[1]) // hi
        desired %= hi + coins[1]
    
    result = ks(n=n, desired=desired, coins=coins)
    if result:
        print(count + result)
    else:
        print(-1)
        
if __name__ == "__main__":
    main()
    