t = int(input())
k = 1
cnt = 1
while k % t != 0:
    k = k * 10 + 1
    cnt = cnt + 1
print(k // t, cnt)