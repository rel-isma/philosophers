# Philosopher

## Description
Philosopher is a program developed for the 1337 School assignment in the field of philosophy. It simulates a group of philosophers sitting at a round table, engaging in activities such as eating, thinking, and sleeping. The goal of the program is to implement the necessary logic and synchronization mechanisms to ensure that the philosophers can eat without deadlocking or starving.

The program can be run in two modes: the mandatory part and the bonus part.

## Mandatory Part
In the mandatory part, the philosophers are represented as threads, and the forks on the table are protected using mutexes. Each philosopher thread alternates between eating, thinking, and sleeping according to the following rules:

- While eating, a philosopher holds two forks (one in each hand) and consumes their meal.
- While thinking, a philosopher contemplates philosophical questions and does not engage in any other activity.
- While sleeping, a philosopher rests and prepares for the next round of activities.

The program takes the following arguments:
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die`: The time in milliseconds. If a philosopher doesn't start eating within this time since the beginning of their last meal or the start of the simulation, they die.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to finish eating. They must hold two forks during this time.
- `time_to_sleep`: The time in milliseconds a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If specified, the simulation stops when all philosophers have eaten at least this many times. Otherwise, the simulation stops when a philosopher dies.

The program logs the state changes of each philosopher, including when they take a fork, eat, sleep, think, or die. The log format includes a timestamp and the philosopher's number.

## Bonus Part
In the bonus part, the program uses processes and semaphores to simulate the philosophers and forks. All forks are placed in the middle of the table, and their availability is represented by a semaphore. Each philosopher is a separate process, and the main process manages the simulation.

The arguments and rules for the bonus part are the same as the mandatory part.

## How to Run
To compile the program, navigate to the appropriate directory (`philo/` for the mandatory part or `philo_bonus/` for the bonus part) and run the `make` command. This will generate the executable file (`philo` for the mandatory part or `philo_bonus` for the bonus part).

To run the program, execute the generated executable with the required arguments, as described earlier.

## Additional Information
- The program must adhere to the norm, a set of coding standards specified by 1337 School.
- The use of global variables is not allowed.
- All heap-allocated memory must be freed appropriately to avoid leaks.
- The program should not have any data races.
- The Makefile provided with the program should contain the necessary rules for compilation and execution.

## Contact
If you have any questions, suggestions, or feedback, please feel free to reach out to me.

- Email: relismaiyly@gmail.com
- GitHub: https://github.com/rel-isma/
