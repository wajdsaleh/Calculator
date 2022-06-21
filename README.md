# Calculator
This program is using **Stack application** concept to create a calculator.
# What is a Stack application?
Stack application is using a stack coding concept to convert infix expressions to postfix or prefix expressions and vice versa.
This concept helped me create a calculator program.
# How does this calculator work?
It's similar to the normal calculator but with few differences.
Its first converts infix to postfix which is how compiler work with any arithmetic expression which its face while it read a normal code.
After converting, it takes the postfix expression and evaluates it based on how it was entered, I will list an example below.
After evaluating, it asks the user if s/he wants to continue evaluating the same previous result or start again (restarting the calculator), or exit.
# Example
Let's say we have;
infix: 5 % 4-7 * 9/3^6^8^9^7- 2 + 4
The program will convert it to postfix expression;
postfix: 54%79 * 36897^^^^/-2-4+
And then evaluate it;
result: 3

![Screenshot (790)](https://user-images.githubusercontent.com/74684120/174764310-bd90fcbe-c222-480a-8cf6-6da380b373dd.png)


# Concepts used
I used loops, strings, stack, goto and selection statements (if, else & switch).
