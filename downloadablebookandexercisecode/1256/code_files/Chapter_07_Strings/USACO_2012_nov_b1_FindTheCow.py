total = 0
l_legs = 0
prev_c = ' '
c = ''
f = open('cowfind.in', 'r')
while True:
    c = f.read(1)
    if not c:
        break
    if c == '(' and prev_c == '(':
        l_legs += 1
    if c == ')' and prev_c == ')':
        total += l_legs
    prev_c = c

f_out = open('cowfind.out', 'w')
f_out.write(repr(total))
