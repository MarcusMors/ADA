num = input()
d = len(num)
n = int(num)
ans = {}
if n >= int("1" + "0" * d):
    ans[1] = 1
    ans[0] = max(1, d)
else:
    ans[1] = 1
    ans[0] = max(1, d - 1)
for i in range(1, 10):
    if n >= int(str(i) * d):
        ans[i] = d
    else:
        ans[i] = d - 1
print(sum(ans.values()))
