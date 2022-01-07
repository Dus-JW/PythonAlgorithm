import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
ans = sorted(set(arr))
dic = {ans[i] : i for i in range(len(ans))}
for i in arr :
	print(dic[i], end="")
