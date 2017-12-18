END = 10000 # Try this many

def sigma_1(n): # Note that this DOESNT work for 1. Performance improvement.
	# Make an accumulative sum of divisors of n.
	result = 1 # Start at 1, because 1 divides every natural number
	for k in range(2, n): # Doesn't include n itself!
		if n % k == 0: # If k divides n, it's a divisor
			result += k # So add to the sum
	return result + n # Remembering that n is the largest divisor of n.

def abundancy(n):
	return sigma_1(n)/n

def get_friendlies(n, END):
	ab_n = abundancy(n) # Cache result
	friendlies = []

	print(ab_n)

	for test in range(2, END):
		if test % 100000 == 0: # Print progress
			print(test/END * 100, "%", sep="")
		if (abundancy(test) == ab_n):
			friendlies.append(test)
			print("Found", test, "...")

	print("Done.")
	if (len(friendlies) > 0):
		print("Numbers friendly with", n, "less than", END, "are:")
		print(friendlies)


if __name__ == '__main__':
	get_friendlies(10, END)