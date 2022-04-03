ok1 = True
ok2 = True
s = input()
p = []

for i in range(len(s)):
    if s[i] == ' ':
        p.append(s[:i])
        p.append(s[i + 1:])
if len(p) < 2:
    print("? + ? = ?")
    exit(0)
a = 0
try:
    a = int(p[0])
    if not(0 < a <= 1000):
        ok1 = False
except:
    ok1 = False
try:
    b = int(p[1])
    if not(0 < b <= 1000):
        ok2 = False
except:
    ok2 = False
if ok1:
    print(a, end = " + ")
else:
    print("?", end = " + ")
if ok2:
    print(b, end = " = ")
else:
    print("?", end = " = ")
if ok1 and ok2:
    print(a + b)
else:
    print("?")
