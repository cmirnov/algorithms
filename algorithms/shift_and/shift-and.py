def shift_and (t, p):

	len_alf = 26

	v = [0] * len_alf 
	for i in range(len(p)):
		if ('a' <= p[i] <= 'z'):
			v[ord(p[i]) - ord('a')] += 1 << i

	ans = [0] * len(t)

	ans[0] = 1 & (v[ord(t[0]) - ord('a')])

	for i in range(1, len(t)):
		ans[i] = ((ans[i - 1] << 1) + 1) & (v[ord(t[i]) - ord('a')])
	return ans


t = input()
p = input()

a = shift_and(t, p)

for i in range(len(a)):
	print (a[i])
