#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;

// Adds commas into a string buffer (based on a number) and prints it
void tocout(long long a)
{
    long long c = 1;

    if(a<0) {a*=-1;cout<<"-";}
    while((c*=1000)<a);
    while(c>1)
    {
       int t = (a%c)/(c/1000);
       cout << (((c>a)||(t>99))?"":((t>9)?"0":"00")) << t;
       cout << (((c/=1000)==1)?"":",");
    }
}

// Need arbitrarily large
// Need optimized factoring library


long long sigma_1(long long x) {
    // We will store sum of factors in `result`
    long long result = 0;
    long long flr_sqrt_x = sqrt(x); // Floor of sqrt of x
    long long i = 1;

    while(i <= flr_sqrt_x) {
        // Check if i divides x without leaving a remainder
        if(x % i == 0) {
            // Add to result
            result += i; 
            // Check if sqrt is actually a factor
            if (x/i != i) {
                result += x/i;
            }
        }
        ++i;
    }

    // Return the sum of the factors of x
    return result;
}

double abundancy(int n) {
    return (double)sigma_1(n) / n;
}

// Crappy implementation of an integer checker
bool is_integer(double n) {
    return n == (int)n;
}

// Returns the first friendly for n (bounded by "to")
long long is_friendly_to(int n, long long from, long long to) {
    double abd_n = abundancy(n);

    // Find the minimum numerator/denominator 
    // increment for the next fraction
    int denominator = 1;
    while (!is_integer(abd_n * denominator)) {
        ++denominator;
    }
    int numerator = abd_n * denominator;

    long long i = 0; // Index tracker

    // Fraction to test
    long long frac_num = numerator;
    long long frac_den = denominator;

    // If we're starting somewhere, get our initial fraction there
    while (frac_den < from) {
        frac_num += numerator;
        frac_den += denominator;
    }

    cout << "Abundancy in most simplified form: " << 
             numerator << "/" << denominator << '\n';

    cout << "Starting at: " << frac_den << '\n';

    // Check all the numbers bounded by "to"
    while (frac_den <= to) {
        // Check if the numerator is the factor sum of the denominator
        if (frac_num == sigma_1(frac_den) && frac_den != n) {
            cout << "Smallest friendly for " << n << " is " << frac_den << '\n';
            return frac_den;
        } else if (i % 100000 == 0) {
            cout << setw(8) << setprecision(3) << (float)frac_den/to * 100 << "% : ";
            tocout(frac_den);
            cout << '\n';
        }

        // Find the next integer ratio
        frac_num += numerator;
        frac_den += denominator;
        ++i;
    }

    cout << "No smallest friendly found for " << n << " below " << to << '\n';
    return false;
}

int main() {
    // Timer begin
    clock_t begin = clock();

    /*
    START
    */

    long long n = 10;
    long long from = 1.350E9;
    long long to = 10E9;

    long long first_friendly = is_friendly_to(n, from, to);

    // Save results if we have any!
    if (first_friendly > n) {
        ofstream save_file;
        save_file.open("results.txt");
        save_file << n << " : " << first_friendly << '\n';
        save_file.close();
    }

    /*
    END
    */

    // Timer end
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    // This is fine, because it's not parallelized in any way.
    cout << "Seconds taken: " << elapsed_secs << '\n';

    return 0;
}