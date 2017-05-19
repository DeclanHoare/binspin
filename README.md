# binspin

*like rot13 for binary*

binspin is a tiny program that follows the Unix philosophy. Its "One
Thing" is to turn your files sideways.

## Building

`gcc binspin.c -o binspin`

## Usage

```
cat orig | ./binspin > spin
rm orig
cat spin | ./binspin > orig
```
