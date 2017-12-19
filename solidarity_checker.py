from math import sqrt
from sympy import divisors, factorint

START = 1891500000 
END = START + 500000 # Try this many

def sigma_1(n): # Sum of factors with parity check
        return sum(list(divisors(n, generator=True)))

def abundancy(n):
	return sigma_1(n)/n

def get_friendlies(n, START, END):
	ab_n = abundancy(n) # Cache result
	friendlies = []

	print(ab_n)

	for test in range(START, END):
		if test % 10000 == 0: # Print progress
			print(test/END * 100, "%", sep="")
		if (abundancy(test) == ab_n):
			friendlies.append(test)
			print("Found", test, "...")

	print("Done.")
	if (len(friendlies) > 0):
		print("Numbers friendly with", n, "less than", END, "are:")
		print(friendlies)


if __name__ == '__main__':
	get_friendlies(10, START, END)