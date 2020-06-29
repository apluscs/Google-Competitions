## Fast Exponentiation
To raise x to the y'th power in logarithmic time, we square x every time and includes it in the multiplication of res if res's corresponding bit is set.
https://cp-algorithms.com/algebra/binary-exp.html explains it better than I do.

## Modular Inverse
The modular inverse (in a mod world of "mod") x to b: (bx) % mod == 1

If b and m are relatively prime, x = b^(totient(mod)-1) % m
Luckily for us, b and m are relatively prime because b is prime. Even more luckily for us, the totient for primes is mod - 1. So that's why we raise i - 1 to the m - 2 power.

https://mathworld.wolfram.com/TotientFunction.html
https://mathworld.wolfram.com/ModularInverse.html#:~:text=A%20modular%20inverse%20of%20an,3%2C%202%2C%20and%204. 