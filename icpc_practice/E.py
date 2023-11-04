arr = [0] * 1000
arr_n = [0] * 1000
# for i in range(0, 1000):
#     arr[i] = False
#     arr_n[i] = 0


[s, n] = input().split(" ")

n = int(n)
# print("s:", s)
# print("n:", n)

for i in range(0, len(s)):
    c = s[i]
    if c != "?":
        arr[i] = True


d_aprox = 0
for i in range(0, 1000):
    if arr[i]:
        exp = len(s) - i - 1
        arr_n[i] = ((10 ** (len(s) - i - 1)) + n - 1) // n
        d_aprox += arr_n[i]

print("min_d? :", d_aprox)
print("using_d :", d_aprox * n)
