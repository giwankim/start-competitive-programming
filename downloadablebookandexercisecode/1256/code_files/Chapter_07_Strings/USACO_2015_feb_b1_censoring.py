
f_in = open("censor.in", 'r')
f_out = open("censor.out", 'w')

str = f_in.readline().split()
str = str[0]
T = f_in.readline().split()
T = T[0]
Tlen = len(T)

out = ""

for ch in str:
    out += ch
    if out[-Tlen:] == T:
        out = out[:-Tlen]

f_out.write(out)