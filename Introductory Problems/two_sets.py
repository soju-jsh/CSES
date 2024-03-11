"""
    Author: soju-jsh
    Created: 03/09/24
"""

from sys import stdin, stdout
input = stdin.readline
# print = stdout.write

'''
    https://cses.fi/problemset/task/1092
'''
        
def main():
    n = int(input())
    if n in [1, 2]:
        print("NO")
    else:
        a_sum = lambda x : int((x + 1) / 2 * x)
        if a_sum(x=n) % 2:
            print("NO")
        else:
            print("YES")
            half = a_sum(x=n) // 2
            seq1, seq2 = [], [x for x in range(1, n + 1)]
            while half:
                if half >= seq2[-1]:
                    val = seq2.pop()
                else:
                    val = seq2.pop(seq2.index(half))
                    
                seq1.append(val)
                half -= val
            seq1.reverse()
            
            print(len(seq1))
            print(*seq1)
            print(len(seq2))
            print(*seq2)
        
if __name__ == "__main__":
    main()
    