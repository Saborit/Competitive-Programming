def div(n):
	ans = 0
	i=1
	while i*i <= n:
		if n%i==0:
			ans += 1
			if i != n/i:
				ans += 1
		i += 1
	return ans

max = 0
num_max  = 0

for i in xrange(2, 1000001):
	d = div(i)
	
	if i%10000 ==0:
		print i, d

	max += d
print str(max) 
