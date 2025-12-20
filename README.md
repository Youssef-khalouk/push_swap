* This project has been created as part of the 42 curriculum by ykhalouk.*

<h1 style="color:white;">PUSH_SWAP</h1>

## Description

**push_swap** is a sorting algorithm project,
The goal is to sort a list of integers using **two stacks** (`A` and `B`) and a **limited set of operations**, while producing the **smallest possible number of moves**.

The program receives a sequence of integers as arguments and outputs a list of instructions that sort the numbers in ascending order inside stack `A`.

Only the following operations are allowed:
- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

This project focuses on:
- Algorithmic thinking
- Data structures (linked lists / stacks)
- Optimization
- Low-level memory management in C

---


## Dependencies

### C standard library

- malloc, free
- write

### My own functions

- ft_atoi
- ft_split
- linked list 

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

### Execution
```
./push_swap 4 2 3 1
```
<h1 style="color:white;">BONUS - CHECKER</h1>

This project also includes a **bonus program called `checker`**.

The checker reads a list of instructions from **standard input**, applies them to
stack A and stack B, and verifies whether the result is correct.

- If stack A is sorted in ascending order and stack B is empty, it prints `OK`
- Otherwise, it prints `KO`
- If an invalid instruction is encountered, it prints `Error`

## Dependencies

### C standard library

- malloc, free
- write

### My own functions

- ft_atoi
- ft_split
- linked list 

## Instructions

### Bonus compilation

```bash
make bonus
```

