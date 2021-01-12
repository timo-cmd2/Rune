# Rune
A small programming language based upon Braille unicode symbols

> Note: More docs for syntax and setup on win10 to follow up soon.

### Setup

Clone the repo and ```cd``` into it. If you are on a Unix like env, fire up a terminal pf your choice and paste this commands.

```
gcc sources/*.c -o bin/rune
chmod +x bin/rune
```

You might eventually want to export the binary file to the ```$PATH``` variable. However lets get started by getting our hands dirty with compiling samples.
Type the commands in a unix shell and enjoy.

```
# after export call the rune binary
# withouth export youll need to provide an absolute path to the binary 
rune samples/hello.rune
```

Isnt that difficult right? Wanna see the code of a Rune program? 

#### Hello world in Rune:

```
 ⠆⠄⡒⡆⡘⠀⢐⠊⠦⢦⠗⢾⠿⠂⢢⢾⢦⢦⠮⢄
```

#### Licensing and Authors

```
Licensed under the CC1.0 License 
Built by Timo Sarkar and Contributors
Copyright 2020-2021 Timo Sarkar
```
