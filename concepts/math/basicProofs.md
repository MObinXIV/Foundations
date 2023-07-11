# Introduction to proofs

The methods of proof explored here are not only important for proving mathematical theorems but also have applications in computer science. These applications include verifying the correctness of computer programs, ensuring the security of operating systems, making inferences in artificial intelligence, establishing consistency in system specifications, and more. Understanding proof techniques is crucial in both mathematics and computer science fields.

## Direct proof

A direct proof is one of the most common methods used to construct a mathematical proof. It involves a straightforward and logical sequence of steps to establish the truth of a statement. In a direct proof, we start with the given information and use logical reasoning, axioms, and previously established theorems to reach a conclusion.

### The structure of a direct proof typically involves the following steps:

1. State the statement to be proved.
2. Clearly state any given information or assumptions.
3. Present the logical steps, using axioms, definitions, and previously proven theorems, to derive new information or conclusions.
4. Continue the logical progression until the desired statement is reached.
5. Conclude the proof by restating the original statement and noting that it has been logically established.

## Example

- Give a direct proof of the theorem “If n is an odd integer, then n2 is odd. 

Since n is an odd integer, we can express it as n = 2k + 1, where k is an integer.

Now, let's square both sides of the equation: n^2 = (2k + 1)^2.

Expanding the right side: n^2 = 4k^2 + 4k + 1.

We can rewrite this equation as: n^2 = 2(2k^2 + 2k) + 1.

Now, let's define a new integer m = 2k^2 + 2k.

We can rewrite the equation once again as: n^2 = 2m + 1.

Here, we can see that n^2 has the form 2m + 1, where m is an integer.

According to the definition of an odd integer, any integer of the form 2m + 1 is odd.

Therefore, we have shown that if n is an odd integer, then n^2 is odd.

---

## Proof by contraposition

when faced with difficulties in finding a direct proof, it is worth exploring other proof methods, such as proof by contraposition. By leveraging the logical equivalence between a conditional statement and its contrapositive, we can establish the truth of the original statement by proving its contrapositive instead. This expands our toolkit for proving theorems and allows us to overcome dead ends or obstacles encountered in direct proofs.
## Example

- Prove that if n is an integer and 3n + 2 is odd, then n is odd

we can express it as n = 2k, where k is an integer.

Substituting this into 3n + 2:

3n + 2 = 3(2k) + 2 = 6k + 2 = 2(3k + 1).

Here, we can see that 3n + 2 can be written as 2 times an integer (3k + 1), which means it is even.

Therefore, we have shown that if n is an even integer, then 3n + 2 is also even.

By proving the contrapositive, we have established the truth of the original statement. Thus, we have demonstrated that if 3n + 2 is odd, then n must be odd as well, using the proof by contraposition.
