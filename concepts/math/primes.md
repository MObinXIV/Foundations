# Prime Numbers

---

prime number is a number which only accept to be divided by itself only and the 1.

## Some facts about primes:

1. **2** is only the even prime number.
2. Every prime can be written as (6b+1) or (6n-1) except 2 & 3,n is a natural number.
3. Goldbach conjecture: every integer>2 can be expressed as the sum of 2 primes.
4. (p-1)! = (p-1)%p
5. 2 & 3 are only consecutive that are primes.

## Sieve of Eratosthenes:

The Sieve of Eratosthenes is an ancient algorithm devised by the Greek mathematician Eratosthenes to find all prime numbers up to a given limit. It works by iteratively sieving out composite (non-prime) numbers.

### summary of the algorithm:

1. Create a list or array of size n+1, initially assuming all numbers are prime.
2. Start with the first prime number, 2.
3. Iterate through the list and mark all multiples of 2 as composite.
4. Find the next unmarked number, which is a prime number, and mark its multiples as composite.
5. Repeat step 4 until you reach the square root of the limit.
The remaining unmarked numbers in the list are prime numbers.


The algorithm efficiently eliminates composite numbers by marking their multiples. It only needs to iterate up to the square root of the limit because any composite number has a prime factor less than or equal to its square root.

By the end of the algorithm, the list contains only the prime numbers up to the given limit. The Sieve of Eratosthenes has a time complexity of approximately O(n log log n) and is useful for prime number generation and related problems in number theory and computational algorithms.