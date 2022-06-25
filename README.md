<h1 align="center">
	🎮 So_long
</h1>

<p align="center">
	<b><i>Can't eat without my fork!!!!!</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/m0hs1ne/philosophers?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/m0hs1ne/philosophers?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/m0hs1ne/philosophers?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/m0hs1ne/philosophers?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/m0hs1ne/philosophers?color=green" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _this project is a training to multi-threads/multi-process programming._

	The classic dining philosopher problem.
	This problem states that N philosophers seated around a circular table with one fork between each pair of philosophers. A philosopher may eat if he can pick up the two forks adjacent to him. One fork may be picked up by any one of its adjacent followers but not both.
	Each time a philosopher finish eating, they will drop drop their forks and start sleeping. Once they have finished sleeping, the will start thinking and waiting to eat.
	Simulation stops when a philosopher dies.
	Every philosopher needs to eat and they should never starve.
	Philosophers do not speak with each other.
	Philosophers do not know when another philospher is about to die.
	And of course, philosophers should avoid dying.



## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```

## 📋 Testing

![gif](https://github.com/m0hs1ne/philosophers/blob/main/test.gif)

