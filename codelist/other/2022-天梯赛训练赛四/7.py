Case = int(input())
for i in range(Case):
l = input().split()
l[1] = int(l[1])
l[2] = int(l[2])
if not (15 <= l[1] <= 20) or not (50 <= l[2] <= 70):
print(l[0])