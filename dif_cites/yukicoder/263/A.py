import math
n = int(input())
cnt = 0
if(n == 1 or n == 4):
    print(-1)
    exit()



while(n % 2 == 0):
    cnt += 1
    n //= 2
    # print(n, cnt)
if(cnt == 1):
    print(-1)
else:
    print(1)abc
