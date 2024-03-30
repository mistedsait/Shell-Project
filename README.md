# Shell-Project

# Group members
Miralem Masic
Anesa Cutuna

# Files
shell.c
clone.c
forkwaitexec.c
forkbomb.c
execle.c

# Answers to task 1.5

Q1: If we have a single-core, uniprocessor system that supports multiprogramming, how many processes can be in a running state in such a system, at any given time?
A1: Only one process can be active at any given time in a single-core, uniprocessor system that allows multiprogramming. It is possible for several processes to be in a state of readiness or waiting as they wait for the processor to execute them. Based on several factors like priority and waiting time, the operating system employs scheduling algorithms to decide which task should get access to the CPU next.


Q2: Explain why system calls are needed for a shared memory method of inter-process communication (IPC). If there are multiple threads in one process, are the system calls needed for sharing memory between those threads?

A2: System calls are necessary for inter-process communication (IPC) using shared memory since shared memory comprises a section of memory that is accessible by several processes. The shared memory IPC approach requires that many processes be able to access the same shared memory region simultaneously, which would not be possible without the use of system calls.

When a process wants to access shared memory, it has to use (call) an appropriate system call that is provided by the OS to establish a shared memory segment that later can be accessed by other processes. When a certain process calls a system call, it creates a space in memory that is shared between different parts of the program. This memory segment is mapped to the address space of the calling process, and the system call returns a pointer to the starting address of the shared memory. Other processes that want to access the created shared memory segment also need to call the same system call to map the shared memory to their own address spaces.

However, in case of multiple threads within a single process, system calls aren't needed for sharing memory between those threads. Threads within the same process share the same address space, and they can access the same memory locations without the use of system calls. It's actually often more efficient to share memory between threads within the same process instead of using system calls for inter-process communication. This is because using system calls involves additional overhead from invoking the system call and switching between different contexts, whereas sharing memory avoids these costs.

# Instructions
gcc filename.c -o filename

# outline
Shell.c has implementation of following commands and much:

wc with options(flags)
l - count lines
w - count words
c - count characters
b - count byte
cmatrix with flags
r - rainbow mode
s - space mode
B - bold letters mode
grep
c - lines that match the pattern
h - matched lines
l -list of file names
df
a - all system files
h - human readable form
exit

man commandName

Redirecting output to a file

Custom implemented commands: quote, kitty, content

Shell.c has implementation of following system calls: fork(), wait(), execle(), execvp(), forkbomb(), execvp(),

# Challenges

The more complex features of the C programming language are difficult to understand.
For the first time, we implemented the entire shell from scratch by building our own code for wc, grep, cmatrix, df, and other commands because we didn't grasp exactly what was requested of us to implement.
Despite the notion of piping's difficulty in understanding and application, we made a lot of effort to try to overcome the issue. We attempted a number of various strategies, but none of them provided the necessary, accurate answer.

# Sources
https://www.systutorials.com/how-to-get-the-hostname-of-the-node-in-c/
https://tuxthink.blogspot.com/2012/12/c-program-in-linux-to-find-username-of.html
https://brennan.io/2015/01/16/write-a-shell-in-c/
https://github.com/Sa3eedoo/Simple-shell-implementation/blob/main/shell.c
https://www.youtube.com/watch?v=rj7DOPPTkQA&t=340s&ab_channel=ServetGulnaroglu
https://www.geeksforgeeks.org/making-linux-shell-c/ https://github.com/TunsAdrian/Linux-Terminal/blob/master/Source%20code/shell.c https://blog.ehoneahobed.com/building-a-simple-shell-in-c-part-1 https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/ https://linux.die.net/man/


