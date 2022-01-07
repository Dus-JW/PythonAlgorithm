n = int(input())
arr = list(map(int, input().split()))
ans = sorted(set(arr))

for i in range(len(arr)) :
	for j in range(len(ans)) :
		if (arr[i] == ans[j]) :
			print("%d "%j, end="")