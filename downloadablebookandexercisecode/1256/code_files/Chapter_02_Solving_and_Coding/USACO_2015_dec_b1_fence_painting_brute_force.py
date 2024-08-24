# http://usaco.org/index.php?page=viewproblem2&cpid=567

fin = open('paint.in', 'r')
fout = open('paint.out', 'w')

a, b = map(int, fin.readline().strip().split())
c, d = map(int, fin.readline().strip().split())

ans = 0

# just check every unit of the fence

for i in range(100):
    p = i + 0.5
    if (a < p < b) or (c < p < d):
        ans = ans + 1

fout.write(f'{ans}')
