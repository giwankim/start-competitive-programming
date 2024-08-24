f = open("cownomics.in", "r")

N, M = map(int, f.readline().strip().split())


spotty = []
for i in range(N):
    spotty.append(f.readline().strip())

plain = []
for i in range(N):
    plain.append(f.readline().strip())

letter = ['A', 'G', 'C', 'T']
locs = []

for i in range(M):
    s1 = [x[i] for x in spotty]
    s2 = [x[i] for x in plain]

    good_loc = True
    for l in letter:
        if s1.count(l) > 0 and s2.count(l) > 0:
            good_loc = False
    if good_loc:
        locs.append(i)

f2 = open("cownomics.out","w")
f2.write(str(len(locs)))
f2.close()