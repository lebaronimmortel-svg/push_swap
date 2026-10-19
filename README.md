*This project has been created as part of the 42 curriculum by alexfuen.*

## Description
push_swap is an algorithmic project designed to sort a random set of integers using two stacks (`a` and `b`) and a strictly limited set of stack manipulation instructions. The objective is to produce the smallest possible sequence of operations to sort stack `a` in ascending order, minimizing time complexity and move count.

**push_swap** incorporates the following main features:
- A sorting engine `push_swap` that parses and validates input integers from CLI arguments.
- Supports both multiple arguments (`./push_swap 2 1 3 6 5 8`) and quoted formatted strings (`./push_swap "2 1 3 6 5 8"`).
- Outputs the sequence of operations separated by newlines to standard output.

Memory is properly managed throughout; all allocated nodes, arrays, and parsed strings are freed on exit without memory leaks.

## Instructions
To compile and run the project, the standard `Makefile` rules apply:
- Run `make` or `make all` to compile the mandatory executable `push_swap`.
- Run `make bonus` to compile the bonus checker executable `checker`.
- Other available `Makefile` rules include `clean`, `fclean`, and `re`.

### Execution

Run `push_swap` by passing integer values either as separate parameters or within a quoted string:
```bash
./push_swap 15 87 36 95 21 12
./push_swap "15 87 36 95 21 12"
```
To count the total number of operations generated:
```bash
./push_swap 15 87 36 95 21 12 | wc -l
```

## Resources

Resources for this project were:
 - https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0 — Detailed explanation of the Turk mechanical algorithm
 - https://medium.com/@ayogun/push-swap-c1f5d2d41e97 — Overview of stack manipulation and complexity optimizations
 - https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474 — Comparison of various sorting approaches for push_swap
 - https://stackoverflow.com/questions/75100698/push-swap-what-is-the-most-efficient-way-to-sort-given-values-using-a-limited-s — Algorithmic discussions on instruction optimization