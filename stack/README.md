# Stack
A simple stack program. Part of COSC-2436 (Data structures and algorithms).

## [Assignment Instructions](./Assignment5Stacks.pdf)

## Use

Compile with CLI command:
```shell
g++ -I ./ *.cpp
```

Pass in an additional argument when running that determines stack size. Argument should be a positive integer.

Example: 
```shell
./a.out 10
```

## Test

You can automate CLI testing after compilation by running this script:

```shell
for i in {-5..5}; do ./a.out $i; done
```
