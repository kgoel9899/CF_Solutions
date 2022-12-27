for tc in range(int(input())):
  n = int(input())
  p = list(map(int, input().split()))
  a, b, c = 0, 0, 0
  for i in range(n):
    if p[i] != i + 1 and p[i] != n - i:
      c += 1
    elif p[i] != i + 1:
      a += 1
    elif p[i] != n - i:
      b += 1
  if a + c <= b:
    print("First")
  elif b + c < a:
    print("Second")
  else:
    print("Tie")