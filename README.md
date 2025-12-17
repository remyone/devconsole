# Devconsole 🖥️>_
> A Console written in C

## Table Of Contents
- [Installation](#Installation)
- [Motivation](#Motivation)
- [@TODO](#@TODO)
- [License](#License)

## Installation 🛠️
```bash
git clone https://github.com/remyone/devconsole.git
cd devconsole/
gcc main.c execution.c -o main
./main
```

## Motivation 🔥
The main motivation is to learn C linux library functions (e.g. opendir) and increase familiarity with the `<string.h>` functions and parsing directories . Here are some of the concepts I've learned writing this program: 
- How to parse directories and take info from them
- How to work with [fork](https://man7.org/linux/man-pages/man2/fork.2.html) and [exec](https://man7.org/linux/man-pages/man3/exec.3.html)
- Strengthen knowledge of token parsing (adding tokens to the buffer)
- How to find out about shell built-in functions (e.g. cd) via [compgen](https://www.gnu.org/software/bash/manual/html_node/Programmable-Completion-Builtins.html) 

## @TODO
### Shell work itself
 [-] Add a pipiline (1 and more)
 [-] Get the access to shell built-in functions (e.g. `cd`) and control them (to call them)

### Shell
 [-] Change a "my console in original console" to my console that runs in GUI (e.g. Qt)


## License
This project is open source and available under the [MIT License](https://github.com/remyone/devconsole/blob/main/LICENSE)
