Exercise 1.

Create a calculator program that can do basic operations: Addition, subtraction, multiplication and division. 
In your program, create a user interface that asks for basic calculation operations. 
All calculations should be executed in a utility library.

Exercise 2.

Refactor your code so that you can add parameters when you call your calculator from the command line. 
for example the command "./calculator --sum 1 2" returns the correct calculation. 
You can use a third party library for this called cxxopts 
https://github.com/jarro2783/cxxopts Links to an external site..

Exercise 3.

Add asserts that makes sure that the the program runs only with correct input values.

Optional Exercise 4.

Add a new feature to the calculator that can encrypt and decrypt the Caesars Cipher 
https://en.wikipedia.org/wiki/Caesar_cipher Links to an external site..

A tip to make this is to remember that C++ handles characters as ASCII codes. 
You can try and see what gets outputted by std::cout << int('a').

https://theasciicode.com.ar/ Links to an external site. here you can see ascii codes.
