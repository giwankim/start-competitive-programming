
N = int(input())
sin = input()

name = 'BESSIE'

pts = 0
for length in range(1, len(name) + 1):
    sub_name = name[0:length]
    pos = sin.find(sub_name)
    while pos != -1:
        pos += length
        pts += length
        if length == 6:
            pts += 4
        pos = sin.find(sub_name, pos)

print(f'{pts}')

'''
Input:
6
BESSIE
Ans:
25

Input:
4
BESS
Ans:
10

Input:
14
BESSIEBEBESSIE
Ans:
53
'''