# http://www.usaco.org/index.php?page=viewproblem2&cpid=1252

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    gCover = -1
    hCover = -1
    s = input()
    cnt = 0
    out = ['.'] * n

    for idx, ch in enumerate(s):
        if ch == 'G':
            if idx <= gCover:
                continue
            cnt += 1
            if idx + k >= len(patches):
                if patches[idx] != '.':
                    patches[idx - 1] = 'G'
                else:
                    patches[idx] = 'G'
                gCover = n
            else:
                patches[idx + k] = 'G'
                gCover = idx + 2 * k
        if ch == 'H' and hCover < idx:
            if idx + k >= len(patches):
                if patches[idx] != '.':
                    patches[idx - 1] = 'H'
                else:
                    patches[idx] = 'H'
                hCover = idx + k
            else:
                patches[idx + k] = 'H'
                hCover = idx + 2 * k
    print(cnt)
    print("".join(out))


