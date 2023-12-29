with open('t.txt') as f:
   res = f.readlines()
res = [i[:-2] for i in res]
res = [int(i) for i in res]
cpu = 0
for i in range(int(len(res) )):
   cpu += res[i]
print(cpu/8)
