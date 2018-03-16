### Twang - a Lisp interpreter in C
#### Emily Lepert and Isa Blancett

The goal of this project is to create our own basic LISP interpreter in C. Our interpreter has the ability to take in mathematical and conditional LISP commands, interpret them in C, and output the appropriate result.

Our learning goal is to get more familiar with C.

To get started we found a couple tutorials on basic Lisp interpreters. We also found an example of an [open source Lisp interpreter project](https://github.com/rui314/minilisp) which we used to figure out what we wanted to implement.

We were able to implement mathematical functionality (adding, subtracting, dividing, multiplying) and comparative operators (<, =) (file [here](https://github.com/iblancett/SoftSysTWANG/blob/master/code/math.c)). We were also able to interpret conditionals that used mathematical statements (file [here](https://github.com/iblancett/SoftSysTWANG/blob/master/code/conditionals.c)). We also added a test suite for our functions (files [here](https://github.com/iblancett/SoftSysTWANG/blob/master/code/test_conditionals.c) and [here](https://github.com/iblancett/SoftSysTWANG/blob/master/code/test_math.c)).

In LISP conditionals are formatted as such: "(if (statement is true) (then do this) (else do this))". For example, "(if (< 5 6) (+ 9 1) ( + 1 2))" checks to see if 5 is less than 6. If it is, it adds 9 and 1 together, if it isn't it adds 1 and 2 together. In this case it would add 9 and 1 together.

Here is an example of a mathematical command the shell of our program can take: typing "(+ 5 6)" would result in "11" being returned.

<img width="100" src="https://raw.githubusercontent.com/iblancett/SoftSysTWANG/master/images/adding.png">

Below are more examples of our shell working:

In this case, 6 is equal to 6, so the interpreter adds 9 and 8 together and returns 17.

<img width="400" src="https://raw.githubusercontent.com/iblancett/SoftSysTWANG/master/images/trueIFeq.png">

In this case, 6 is not equal to 7, so the interpreter subtracts 4 from 5 and returns 1.

<img width="400" src="https://raw.githubusercontent.com/iblancett/SoftSysTWANG/master/images/falseIFeq.png">

Our initial proposal for our MVP was to complete a LISP tutorial and add functionality. We reached that MVP in this project as we completed a tutorial on interpreting addition, division, and multiplication in C. We then added subtraction, comparators, and conditionals. Our stretch goal was to create our own language and the interpreter for the language in C. We did not get close to achieving that goal, but we have learned more about what goes into designing a language and the interpreter for the language. 
We both got opportunities to work on our learning goals and practiced writing programs in C.
