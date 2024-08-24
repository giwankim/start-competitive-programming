# Ferris Wheel 2
(n, x) = list(map(int, input().split()))
ws = list(map(int, input().split()))

# n - number of kids
# x - maximum allowed weight
# ws - weights
ws.sort()

cnt = 0
i1 = 0
i2 = n - 1

while i1 <= i2:
    # if a smaller kid fits in, we'll put him in as well!
    if ws[i1] + ws[i2] <= x:
        i1 += 1

    # in any case, we are going to sit theheavy kid in a Gondola
    i2 -= 1
    cnt += 1

print(str(cnt))
# Input:
# 4 10
# 7 2 3 9
# Output:
# 3
