# Devconsole
> A Console written in C

## Table Of Contents
- [Installation] (#Installation🛠️)
- [Motivation] (#Motivation🔥)
- [License] (#License)

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
- Creating of a child process with exec
- Strengthen knowledge of token parsing (adding tokens to the buffer)
- How to find out about shell built-in functions (e.g. cd) via `compgen`

## License
This project is open source and available under the [MIT License] (https://github.com/remyone/devconsole/blob/main/LICENSE)
