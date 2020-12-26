## Description

Code examples of algorithms for finding a substring(S) in a text(T) and tests for them


## File naming

- [brute_force.cpp](./code/brute_force.cpp): brute force
- [rk.cpp](./code/rk.cpp): Rabin–Karp algorithm
- [bmh.cpp](./code/bmh.cpp): Boyer–Moore–Horspool algorithm
- [kmp.cpp](./code/kmp.cpp): Knuth–Morris–Pratt algorithm


## Tests

+ Small tests
  + in_1 
    + T = banananobano
    + S = na
  + in_2 
    + T = barfoobarfoobarfoobarfoobarfoo
    + S = foobarfoo
  + in_3 
    + T = ataattaccaacatcataattaccaacatcataattaccaacatcataattaccaacatcatc
    + S = atc
+ Big tests
  + in_max_test_1

    *Use [generator](./helpers/max_test_1_generator.cpp) for create this test(This requires **100 MB** of free memory)*
    + T = (a^9999 + b)^1e4, but one of blocks consists 'a' except 'b'
    + S = a^1e4
  + in_max_test_2 
    + T = (a^999 + b)^1e3, but one of blocks consists 'a' except 'b'
    + S = a^1e3
  + in_max_test_3 
    + T=a^1e6
    + S=a^1e3


## Ask me anything

- Telegram: [@iaman](https://t.me/iaman)
- Email: [naumovich.artem@gmail.com](mailto:naumovich.artem@gmail.com)
