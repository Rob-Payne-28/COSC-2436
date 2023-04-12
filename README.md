# Binary Search Tree
A binary search tree program. Part of COSC-2436 (Data structures and algorithms).


## Use

Compile with CLI command:
```shell
g++ -I ./ *.cpp
```

Run compiled file:

```shell
./a.out
```

## Test

You can automate CLI testing after compilation by running this script:

```shell
for i in {1..500}; do ./a.out; done
```

When looking for specific output, you can specify by greping what you're looking for:

- Example looking for duplicate value messages:
    ```shell
    for i in {1..500}; do ./a.out | grep duplicate; done
    ```
- Example looking for failure messages:
    ```shell
    for i in {1..500}; do ./a.out | grep failed; done
    ```
