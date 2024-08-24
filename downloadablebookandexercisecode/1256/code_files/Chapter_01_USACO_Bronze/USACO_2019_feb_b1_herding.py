# http://usaco.org/index.php?page=viewproblem2&cpid=915

f_in = open('herding.in', 'r')

a, b, c = map(int, f_in.readline().split())

# sort the 3 cows
# there are many more concise ways to do it in python.
# we'll just use the most verbose one.
if c < b:
    # b, c = c, b  # swap the two values
    tmp = b
    b = c
    c = tmp
if b < a:
    a, b = b, a

ans_min = 2
if c - a == 2:
    ans_min = 0
else:
    if c - b == 2 or b - a == 2:
        ans_min = 1
    else:
        ans_min = 2

ans_max = max(c - b - 1, b - a - 1)

f_out = open('herding.out', 'w')
f_out.write(f'{ans_min}\n{ans_max}\n')
f_out.close()
