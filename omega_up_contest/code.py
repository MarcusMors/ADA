import sys


def main():
    arr = [0] * 10000
    arr[0] = 0
    arr[1] = 1
    arr[2] = 1
    arr[3] = 2
    arr[4] = 4
    for i in range(5, 10000):
        arr[i] = 0
    n = int(sys.stdin.readline())
    while n != 0:
        if arr[n] != 0:
            print(arr[n])
            n = int(sys.stdin.readline())
            continue
        a = 1
        b = 1
        c = 2
        j = 2
        while j < n + 1:
            if arr[j] == 0:
                a = arr[j - 3]
                b = arr[j - 2]
                c = arr[j - 1]
                j -= 1
                break
            j += 1
        for i in range(j, n):
            tmp = a + b + c
            a = b
            b = c
            c = tmp
            arr[i + 1] = c
        print(c)
        n = int(sys.stdin.readline())


if __name__ == "__main__":
    main()
