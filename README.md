# TWANG
Implementation of a small programming language (inspired by LISP) in C for Software Systems at Olin College.

## Functionality:
- Addition, subtraction, multiplication, and division of positive, single digit integers (ex. "(* 7 3 1)")
- Comparison of positive, single digit integers using less than (<) or equal to (=)
- Conditional statements ("(if (this is true)(then do this)(else do this)))"

## Using TWANG

To download and set up the shell:
```
git clone https://github.com/iblancett/SoftSysTWANG
cd SoftSysTWANG/code
gcc math.c conditionals.c -o twang
```

To run the shell:
```
./twang
```
