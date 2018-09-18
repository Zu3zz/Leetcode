str = input().split()
number = int(str[0])
length = int(str[1])
time = int(str[2])
pos_1 = []
pos_sorted = []
index = []
pos = []
position = input().split('\n')[0]
for i in position.split():
    pos.append(int(i))
    pos_1.append(int(i))
if (number == len(pos)):
    for i in range(len(pos)):
        total_length = pos[i] + time
        round = int(total_length / length)
        if (round % 2 == 0):
            pos[i] = total_length - round * length
        else:
            pos[i] = (round + 1) * length - total_length
pos_sorted = sorted(pos_1)
for i in pos_1:
    for j in range(len(pos_sorted)):
        if (i == pos_sorted[j]):
            index.append(j)
pos_final = []
for i in range(number):
    pos_final.append(1)
pos_2 = sorted(pos)
for i in range(number):
    index_i = index[i]
    pos_final[i] = pos_2[index_i]
for i in pos_final:
    print(i,end=' ')
