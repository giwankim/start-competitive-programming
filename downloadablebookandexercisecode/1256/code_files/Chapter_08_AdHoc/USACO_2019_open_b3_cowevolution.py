# http://www.usaco.org/index.php?page=viewproblem2&cpid=941

fin = open('evolution.in', 'r')
N = int(fin.readline())

features = {}  # Empty dictionary
for i in range(N):
    s = fin.readline().split()
    k = int(s[0])
    for ss in s[1:]:
        if ss in features:
            features[ss].append(i)
        else:
            features[ss] = [i]

# print(features)

valid = True

for s1 in features.keys():
    list1 = features[s1]
    for s2 in features.keys():
        if s1 == s2:
            continue
        list2 = features[s2]
        if set(list1) == set(list2):
            continue  # "Both lists are identical."
        elif set(list1).issubset(set(list2)):
            continue  # "List 1 is contained within List 2."
        elif set(list2).issubset(set(list1)):
            continue  # "List 2 is contained within List 1."
        elif len(set(list1).intersection(set(list2))) > 0:
            valid = False  # "Lists have partial overlap."
        else:
            continue  # "Lists are disjoint."

if valid:
    ans = 'yes'
else:
    ans = 'no'

fout = open('evolution.out', 'w')
fout.write(ans)
