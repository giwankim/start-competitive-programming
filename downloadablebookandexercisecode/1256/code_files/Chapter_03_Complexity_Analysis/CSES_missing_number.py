#  https://cses.fi/problemset/task/1083

n = int(input())

in_list = map(int, input().strip().split())

sum_list = sum(in_list)

sum_n = (n + 1) * n / 2

num = sum_n - sum_list

print(f'{int(num)}')
