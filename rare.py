from collections import Counter

f = open("code")
c = Counter(f.read())
print(c.most_common())
