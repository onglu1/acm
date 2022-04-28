n, m = map(int, input().split())
a = []
for i in range(n):
    a.append(min(list(map(int, input().split()))))
print(max(a))