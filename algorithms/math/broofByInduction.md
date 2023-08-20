# Induction & Recursion




## Why:

 inductive logic gives us an empirical, rational tool for drawing useful probable conclusions from incomplete information. While not as certain as deduction, it is essential for learning, predicting, theorizing, and navigating the uncertainty of life. We need induction to generalize intelligently from specific data points and observations.

## Why for programmers:

inductive reasoning allows programmers to learn, model, predict, infer, generalize, abstract, test, and debug code in a rigorous, principled way from limited information. It complements deduction as a core skill for programming.

## What:

Mathematical induction is a deductive proof technique used in mathematics and computer science. The key ideas are:

 The key ideas are:

It aims to prove that a statement is true for all natural numbers.
It involves two steps:

1. Proving the statement is true for the first natural number (usually 1 or 0).
2. Proving that if the statement holds for any arbitrary natural number k, then it must also hold for k+1.

- If these two steps can be proven, then by the inductive reasoning, the statement must be true for all natural numbers.
- It relies on the inductive premise that if a statement holds for an initial number, and any given number implies it also holds for the next number, then it must hold for all subsequent numbers.

- **Important note** ->It is extremely important to note that mathematical induction can be used
only to prove results obtained in some other way. It is not a tool for discovering formulae or
theorems.

## How:

to apply Induction , we follow these basic steps:

1. Base Case -> We first prove that the statement is true for the smallest value of the natural number, usually 1 or 0 (depending on the convention).
2. Inductive Step-> We then prove that if the statement is true for any arbitrary natural number k, it must also be true for the next natural number k+1.
By combining these two steps, we can prove that the statement is true for all natural numbers greater than or equal to the base case value.

## Example :

Show that if n is a positive integer, then
1 + 2 + ⋯ + n = n(n + 1)
/2
.

- Base Case:

for n=1.

p(1)-> 1=1*2/2 -> so it's true 

- Inductive step:

for the purpose of induction, we assume that p(k)=k(k+1)/2 is true.
we need to show that p(k+1) => (k+1)(k+2)/2 is true.

1+2+3+4....k+(k+1)=

(1+2+3+4...k)+(k+1)=k(k+1)/2 +(k+1)=

k^2+3k+2/2=

(k+1)(k+2)/2.

This last equation shows that P(k + 1) is true under the assumption that P(k) is true. This completes the inductive step.
We have completed the basis step and the inductive step, so by mathematical induction we
know that P(n) is true for all positive integers n. That is, we have proven that 1 + 2 + ⋯ + n =
n(n + 1)∕2 for all positive integers n
