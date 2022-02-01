import re

p = input()
t = input()


r = re.match(p, t)
if not r:
    print("No")
elif r.group() == t:
    print("Yes")
else:
    print("No")
