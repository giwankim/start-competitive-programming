a2z = input()
hummed = input()

index1 = 27  # Just to get us started.
cnt = 0

for c in hummed:
    index2 = a2z.find(c)
    if index2 <= index1:
        cnt += 1
    index1 = index2

print(cnt)

'''
Sample case:
abcdefghijklmnopqrstuvwxyz
mood

answer:
3
'''
