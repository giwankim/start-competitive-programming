# http://usaco.org/index.php?page=viewproblem2&cpid=591

f_in = open('promote.in', 'r')

b0, b1 = map(int, f_in.readline().split())
s0, s1 = map(int, f_in.readline().split())
g0, g1 = map(int, f_in.readline().split())
p0, p1 = map(int, f_in.readline().split())

# promoted

pm = p1 - p0
gm = g1 - g0 + pm
sm = s1 - s0 + gm

f_out = open('promote.out', 'w')
str1 = str(sm) + '\n' + str(gm) + '\n' + str(pm) + '\n'
f_out.write(str1)
