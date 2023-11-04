"""
6
2 3 2 3 2 4
"""

size = int(input())
nro_str = input().split()

# print(nro_str)
nums = []
for n in nro_str:
    nums.append(int(n))

nums.sort()

c = len(nums) - 1
b = len(nums) - 2
a = len(nums) - 3

perimetro = 0

es_posible = 0
while c >= 2:
    if nums[a] > (nums[c] - nums[b]):  # se puede armar triangulo
        p = nums[c] + nums[b] + nums[a]
        perimetro = p
        es_posible = 1
        break
        # if p > perimetro:
        # 	perimetro = p
    c -= 1
    b -= 1
    a -= 1

if es_posible == 1:
    print(perimetro)
else:
    print("-1")
