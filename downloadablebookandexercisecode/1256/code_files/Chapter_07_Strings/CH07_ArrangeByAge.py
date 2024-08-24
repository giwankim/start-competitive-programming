'''

Example 1:
4
Rosie was born in April after Bessie
Daisy was born in April before Rosie
Elsie was born in March before Daisy
Betty was born in August after Rosie

Answer: No

Example 2:
4
Rosie was born in April before Bessie
Daisy was born in April before Rosie
Elsie was born in April before Daisy
Betty was born in August after Rosie

Answer: Yes
'''

N = int(input())

month = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November',
         'December']
index = range(12)
month_dic = dict(zip(month, index))
cow_age = {'Bessie': 0}
cow_month = {'Bessie': month_dic['January']}

for i in range(N):
    line = input()
    [cow_to, _, _, _, mon, b4next, cow_from] = line.split()
    # Rosie was born in April after Bessie
    month_from = cow_month[cow_from]
    month_to = month_dic[mon]
    if b4next == 'before':
        age = cow_age[cow_from] - (month_from - month_to + 12) % 12
        if month_to == month_from:
            age -= 12
    if b4next == 'after':
        age = cow_age[cow_from] + (month_to - month_from + 12) % 12
        if month_to == month_from:
            age += 12
    cow_month[cow_to] = month_to
    cow_age[cow_to] = age

ans = 'No'
for cow in cow_age:
    if cow_age[cow] < -24:
        ans = 'Yes'
print(f'{ans}')
