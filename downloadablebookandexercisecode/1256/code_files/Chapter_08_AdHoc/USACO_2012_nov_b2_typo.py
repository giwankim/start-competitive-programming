
# http://www.usaco.org/index.php?page=viewproblem2&cpid=188

fin = open('typo.in', 'r')
sin = fin.read().strip()
fin.close()

cnt1 = 0  # counts in one direction
cnt2 = 0  # counts in opposite direction
ans = 0

for c in sin:
    if c == '(':
        cnt1 += 1
    else:
        cnt1 -= 1
        cnt2 += 1
    if cnt1 < 0:
        ans = cnt2
        break

cnt1 = 0
cnt2 = 0
sin = ''.join(reversed(sin))
if ans == 0:
    for c in sin:
        if c == ')':
            cnt1 += 1
        else:
            cnt1 -= 1
            cnt2 += 1
        if cnt1 < 0:
            ans = cnt2
            break

fout = open('typo.out','w')
fout.write(f'{ans}')
fout.close()