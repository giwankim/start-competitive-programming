# https://cses.fi/problemset/task/1068
'''
n
If n is even --> divide by 2
if n is odd  --> Multiply by 3 and add 1
Stop when n==1
'''

n = int(input())
while n != 1:
    print(n, end=' ')
    if n % 2 == 0 :
        n = n // 2
    else:
        n = 3 * n + 1
        
print(n)
