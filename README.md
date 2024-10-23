# checkDigit
Early version of my program to calculate the check digit of the old land and mortgage register number.

The register check digit is my first project written in C after learning the basics of this programming language. Thanks to it, you can calculate the check digit of the old land and mortgage register number.

##How to use it?

In Linux first you have to compile source code using command:
```
gcc source.c -o output
```
To execute the program use:
```
./output <court_signature> <old_register_number>
```
You can compute a few of numbers writing out one after another:
```
./output <court_signature> <old_register_number> <old_register_number> <old_register_number>
```
## Version History
* 0.1
    * Early version