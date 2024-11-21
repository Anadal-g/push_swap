
# Push_Swap 42

Push_swap is a simple algorithm project, you need to sort data. You have at your disposal a set of int values, two stacks, and a set of instructions to manipulate both. You should use as few instructions as possible.

# Operations

 Operaciones | Explicación |
| :--- | :--- |
| sa | swap a - swap a - swaps the first two elements on top of stack a.|
| sb | swap b - swap the first two elements on top of the stack b. |
| ss | swap a y swap b at the same time. |
| pa | push a -  takes the first element of stack b and puts it on top of stack a. |
| pb | push b -  takes the first element of stack a and puts it on top of stack b. |
| ra | rotate a - moves all elements of the stack up to one position, the first element becomes the last. |
| rb | rotate b - moves all elements of stack b up one position, the first element becomes the last. |
| rr | ra y rb a la vez. |
| rra | reverse rotate a - moves all elements of the stack down to one position, the last element becomes the first. |
| rrb | reverse rotate b - moves all elements of the stack b down one position, the last element becomes the first. |
| rrr | rra y rrb at the same time. |


# How to use

To clone and run this project, just follow this instructions

 Clone this repository
 
`$ git clone https://github.com/anadal-g/push_swap`

 Go into the repository

`$ cd push_swap`

 Run make command

`$ make`

 Run the executable along with the number sequence of your choice

`$ ./push_swap 5 2 1 4 7 8 3 0`
