# http://www.usaco.org/index.php?page=viewproblem2&cpid=1107

N = int(input())

year = ['Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake', 'Horse', 'Goat', 'Monkey', 'Rooster', 'Dog', 'Pig', 'Rat'];
index = range(12)
year_dic = dict(zip(year, index))
cow_age = {'Bessie':0}
cow_year = {'Bessie':year_dic['Ox']}

for i in range(N):
    line = input()
    [cow_to, _, _, b4next, symbol, _, _, cow_from] = line.split()
    # Mildred born in next Dragon year from Bessie
    # print(f'cow_to={cow_to}, cow_from={cow_from}, b4next={b4next}')
    year_from = cow_year[cow_from]
    year_to = year_dic[symbol]
    if b4next=='previous':
        age = cow_age[cow_from] - (year_from - year_to + 12)%12
        if year_to == year_from:
            age -= 12
    if b4next == 'next':
        age = cow_age[cow_from] + (year_to - year_from + 12)%12
        if year_to == year_from:
            age += 12
    cow_year[cow_to] = year_to
    cow_age[cow_to] = age

print(f'{abs(cow_age["Elsie"])}')