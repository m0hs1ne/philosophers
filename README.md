# philosophers

## Info

42 Cursus - philosophers: this project is a training to multi-threads/multi-process programming.

- Status: finished
- Result: 100%

## The philosophers problem

The classic dining philosopher problem.

This problem states that N philosophers seated around a circular table with one fork between each pair of philosophers. A philosopher may eat if he can pick up the two forks adjacent to him. One fork may be picked up by any one of its adjacent followers but not both. 

Each time a philosopher finish eating, they will drop drop their forks and start sleeping. Once they have finished sleeping, the will start thinking and waiting to eat.

Simulation stops when a philosopher dies.

Every philosopher needs to eat and they should never starve.

Philosophers do not speak with each other.

Philosophers do not know when another philospher is about to die.

And of course, philosophers should avoid dying.

## Solutions

[philo](https://github.com/m0hs1ne/philosophers/tree/main/philo): philosophers with threads and mutex.

- One fork between each pair of philosophers.

- All the forks are in the middle of the table.

## How to use

Clone the repo

```sh
git clone https://github.com/m0hs1ne/philosophers.git
```
Go to `philo` folder and run `make`

```sh
cd ./philo && make
```

- *Makefile rules: `all`, `clean`, `fclean`, `re`).*

Usage

```sh
./philo [N PHILOS] [DIE TIME] [EAT TIME] [SLEEP TIME] (OPT)[PHILO EAT N TIMES]
```

- last argument is optional.

Example

```sh
./philo 4 800 200 200
```

##

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/m0hs1ne/philosophers?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/m0hs1ne/philosophers?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/m0hs1ne/philosophers" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/m0hs1ne/philosophers?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/m0hs1ne/philosophers?color=green" />
</p>