# Check Digit Calculator / Kalkulator Cyfry Kontrolnej Księgi Wieczystej

Early version of my program for calculating the check digit of the old land and mortgage register number (Księga Wieczysta) in Poland.

The register check digit is my first project written in C after learning the basics of this programming language. Thanks to it, you can calculate the check digit of the old land and mortgage register number (Księga Wieczysta) in Poland.

## How to use it?

In Linux first you have to compile source code using command (tested on GNU Compiler Collection, for Debian 12 - Bookworm):

```
gcc check_digit.c -o check_digit
```

To execute the program use:

```
./check_digit <court_signature> <old_register_number>
```

You can compute a few of numbers writing out one after another, e.g.:

```
./check_digit <court_signature> <old_register_number> <old_register_number> <old_register_number>
```

For help, type:

```
./check_digit -h
```

If you don't know the signature of court, type:

```
./check_digit -c
```

## Version History

* 0.2
  * new option: help and court signatures list
* 0.1
  * Early version

## TODO

* help option,
* input data validation,
* import data file,
* export calculated data to JSON file.
