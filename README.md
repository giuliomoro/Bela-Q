# Using Q on Bela

This is a minimal program that uses the Q library from within a Bela project. It is a port of Q's `delay.cpp` example. Hopefully a comparison between the two should give you an idea of what the process was.

## Pre-requisites

This program assumes that you have the Q library installed in /root/Q on your Bela board.

## Build options

As of image v0.3.x, Bela ships with `clang++-3.9` and `g++-6.3`, none of which fully supports the `c++17` standard required by Q. However, by forcing Bela to use `g++` and telling it to use `c++17` (which it only supports experimentally and partially), allows this program to build. Additionally, the compiler needs to know where to find the header files for the Q library. All of this is achieved by passing the following options to `make`:

```
CPPFLAGS="-I ~/Q/q_lib/include -I ~/Q/infra/include -std=c++17" COMPILER=gcc
```

These options are already saved in this project's `settings.json`, so if you run it from the IDE, it should build and run out of the box (assuming the pre-requisites are met). If you are building the program from the command-line by invoking `make`, you should do:

```
make CPPFLAGS="-I ~/Q/q_lib/include -I ~/Q/infra/include -std=c++17" COMPILER=gcc PROJECT=Bela-Q run
```

If you are using one of the Bela scripts, you should pass these options after the `-m` flag (and be careful with the use of quotes). For instance

```
build_project.sh -m 'CPPFLAGS="-I ~/Q/q_lib/include -I ~/Q/infra/include -std=c++17" COMPILER=gcc' Bela-Q
```
