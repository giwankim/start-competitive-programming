
fin = open("whereami.in")
fout = open("whereami.out","w")

N = int(fin.readline())
s = fin.readline()

for l in range(1, len(s)):
    no_duplicate = True
    for i in range(N-l+1):
        s1 = s[i:(i+l)]
        for j in range(i):
            if s1 == s[j:(j+l)]:
                no_duplicate = False
                break
        if not no_duplicate:
            break
    if no_duplicate:
        break

fout.write(repr(l))