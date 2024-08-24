# https://cses.fi/problemset/task/1640
import copy

n, x = map(int, input().strip().split())
a = list(map(int, input().strip().split()))

# we can use python methods to get the index as well,
# but i will do it very simply here.
# among the other options:
# using numpy argsort
# zip with index
# sorted

a_orig = copy.deepcopy(a)

a.sort()

i0 = 0
i1 = n-1
found = False

while i0 < i1:
    if a[i0] + a[i1] > x:
        i1 -= 1
        continue
    if a[i0] + a[i1] == x:
        found = True
        break
    if a[i0] + a[i1] < x:
        i0 += 1
        continue

if not found:
    print("IMPOSSIBLE")
else:
    id1 = a_orig.index(a[i0])
    id2 = a_orig.index(a[i1])
    if id2 == id1:
        id2 = a_orig.index(a[i1], id1 + 1)
    print(f'{id1+1} {id2+1}')


