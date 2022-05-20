# Philosopher

# THREADS :

the first thing that you’re going to face while doing your research about threads is the comparison between them and processes.

## 1 - what is the difference between threads and processes?

basically, a process can contain many threads, those threads share the same code section, data section, and operating system resources ... but each one of them has its own stack and registers.

threads comprise of:

- thread ID :

an id that specifies each thread than the other.

- program counter :

A program counter is **a register in a computer processor that contains the address (location) of the instruction being executed at the current time**. As each instruction gets fetched, the program counter increases its stored value by 1.

- register set :
- stack.

type of threads :

1. user threads :  
2. Kernel threads : 

after dealing with (registers, the program counter and register set) I found myself asking the question, what are **Computer Registers?**

## 2 - **Computer Registers :**


**Registers** are a type of computer memory that is used by the CPU to store important informations about the running processes for example:

- register to hold the address of the instruction that is currently being executed.
- the number of instructions that have been executed.
- the output of an arithmetic operation / the input of it.
- the instruction code.

this table shows a set of registers, their names and what they are used for :

<img width="920" alt="Untitled (2)" src="https://user-images.githubusercontent.com/65429355/169482533-ace3fc01-6d54-44c5-81a2-3124a3fdc768.png">

processes are separated into two types :

- Single-threaded process:

in a single-threaded process, the process can perform only one task at a time.

- Multi-threaded process:

 A multi-threaded process can perform as many tasks as the number of threads which is much more efficient, faster and has too many benefits.

## 3 - Benefits :

- Responsiveness:

if you're using a Multi-threaded process the responsiveness of the program increase such as when ur code is using a single-threaded process and ur program has, for example :

<img width="384" alt="Untitled" src="https://user-images.githubusercontent.com/65429355/169482679-3c9eccfc-c49e-4c05-a1c7-92199b60e816.png">


As shown in the picture above ur program has to do task1 and task2 completely right so that task3 can be done, however, if our code is using a Multi-threaded process if I assign each task of those to a thread each task will run on its own and even If another task didn’t work which clearly makes ur program run faster and efficient, as shown below.

<img width="558" alt="Untitled (1)" src="https://user-images.githubusercontent.com/65429355/169482704-5e15b212-f3fc-4139-90da-e9945fa52f2e.png">


- Resource sharing and economy:

it comes by default that threads that are running under the same process share the same resources, so for that, it’s making our operation system more efficient because it won’t have to reserve resources for each individual thread as known allocating memory and resources cost much.

after seeing all these benefits we might think that threads are heaven in earth piece of code but there’s always a dark side.

### 4 - **disadvantage:**

### 4 - **disadvantage:**

- Data race:

*while dealing with too many threads we may have a couple of those threads trying to change in the same data location at the same time as threads work parallelly, which cause a datarace.*

for example:

if two threads are trying to increament a variable on the heap at the same time they may end up decreamenting it as the operation of “i++” actually goes throught three phases

1. reading the value of ‘i’ in this case let’s make it 8;
2. computing 8 + 1;
3. writing 9 in i; 

so one of our threads could be already in phase 1 while the other thread is in phase 2 so they will finaly not get the variable increamented or just get increamented by 1 instead of two.

- Concurrency:

to solve the data race problem you may think of using mutex.

mutex is used as lock to stop a thread until the other thread finishes what it’s doing, using the same example as above this time we will just use the mutex lock function in c supported by the library <pthread.h> to lock the mutex and stop others threads from working while this thread is increamenting in and then unlocking it for the others to work.

everything will work as expected but this time our code will take too long to work, as locking and unlocking the mutex is a heavy operation.
</br></br>
![1_cFUbDHxooUtT9KiBy-0SXQ](https://user-images.githubusercontent.com/65429355/169487679-5935c3c9-dce3-4942-87ba-6e332b305b01.jpeg)


# Resources :

- Videos :
    - [https://www.youtube.com/watch?v=LOfGJcVnvAk](https://www.youtube.com/watch?v=LOfGJcVnvAk)
    - [https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=1](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM&index=1)
- Articles :
    - [https://www.techopedia.com/definition/9523/stack](https://www.techopedia.com/definition/9523/stack)
    - [https://www.educative.io/edpresso/what-is-a-processor-register](https://www.educative.io/edpresso/what-is-a-processor-register)
    - [https://www.javatpoint.com/computer-registers](https://www.javatpoint.com/computer-registers)
