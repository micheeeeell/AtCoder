n = int(input())
a = list(map(int, input().split()))
# print(a)

ok = False
for i in a:
    if i == 0:
        ok = True
if(ok):
    print(0)
    exit()

ret = 1
for i in a:
    ret *= i
    if(ret > 10 ** 18):
        print(-1)
        exit()

print(ret)