# Check if a Number is Solitary

> Find if 10 has a friend

These programs use brute-force factorization to run through billions of
possible friends for a pre-programmed number.

The software is very simple right now, and not very effective. In future, it
may run faster - depends on when I get a decent machine that can actually
compile advanced factorization code.


## Usage

Highly recommend using the C++ version - it's performance optimized. The
python script is just a quick proof of concept and is at least 6 times slower.

In the software, you must edit where to start looking for friends, where to
stop, and which number we're looking at friends for.

Of course, this would be much faster if it was possible to simply determine if
a number is friendly or not with a constant-time operation.


## Why

I was bored one afternoon. I saw on Wikipedia that the solitary-10 problem was
unsolved, and that the quoted number of 100,000,000 was quite low. So, I made
a program to - at the very least - improve the publicly quoted number (even
though it's likely that someone somewhere has already checked this up to a
20-digit number.)

So far, I've used this program to check up for friends up to to 2,000,000,000.


