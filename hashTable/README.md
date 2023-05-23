# Hash Table
A hash-table program backed by a doubly linked list (no tail pointer). Part of COSC-2436 (Data structures and algorithms).


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
for i in {1..50}; do ./a.out; done
```

When looking for specific output, you can specify by `grep`ing what you're looking for:

- Example looking for duplicate value messages:
    ```shell
    for i in {1..500}; do ./a.out | grep duplicate; done
    ```
- Example looking for failure messages:
    ```shell
    for i in {1..500}; do ./a.out | grep failed; done
    ```
