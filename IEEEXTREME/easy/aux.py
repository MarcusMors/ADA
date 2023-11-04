n = 1000

output = []

for i in range(1, n):
    raw = input()
    if raw == "-1":
        break

    ins = raw.split(" ")
    params = ins[1].split(",")
    # print(ins)
    # print(params)
    if ins[0] == "add-int":
        output.append(f"{params[0]} = {params[1]} + {params[2]};")
    elif ins[0] == "move":
        output.append(f"{params[0]} = {params[1]};")
    elif ins[0] == "sub-int":
        output.append(f"{params[0]} = {params[1]} - {params[2]};")
    else:
        output.append(raw)

for o in output:
    print(o)
