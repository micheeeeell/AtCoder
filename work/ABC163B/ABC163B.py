N = int(input())
M = int(input())

A = 0

for i in range(M):
  A += int(input())

if M < A:
  print(N-A)

else:
  print(-1)