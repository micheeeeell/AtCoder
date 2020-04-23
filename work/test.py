M, K = map(int, input().split()) 

sum = 0
MOD = 10 ** 9 + 7

for j in range(K,M+2):
    temp = j*(M-j+1) + 1
    sum += temp
    sum %= MOD


print(sum)
