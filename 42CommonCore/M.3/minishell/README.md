*This project has been created as part of the 42 curriculum by mosriji and Claude.*

# 🐚 minishell

## Description

**minishell** is a project from the 42 school curriculum that consists of building a simplified Unix shell from scratch in C. The goal is to reproduce the core behavior of **bash** (Bourne Again Shell), implementing features such as command execution, pipes, redirections, environment variable expansion, and built-in commands.

This project is a deep dive into how a Unix shell works under the hood — from parsing user input to managing processes, file descriptors, and signals. It is also a significant exercise in project architecture, team collaboration, and rigorous memory management.

### Key Features

- **Interactive prompt** with a working command line interface
- **Command execution** by searching through `PATH` or using absolute/relative paths
- **Built-in commands**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Pipes** (`|`) to chain commands
- **Redirections**: input (`<`), output (`>`), append (`>>`), heredoc (`<<`)
- **Environment variables** expansion (e.g., `$HOME`, `$?`)
- **Single and double quote** handling
- **Signal handling**: `Ctrl+C`, `Ctrl+D`, `Ctrl+\` behave like bash
- **History** support via readline

---

## Instructions

### Requirements

- A Unix-based system (Linux or macOS)
- `gcc` or `cc` compiler
- `make`
- `readline` library installed

On Ubuntu/Debian:
```bash
sudo apt-get install libreadline-dev
```

### Compilation

Clone the repository and compile the project:

```bash
git clone https://github.com/mohebnazeer/minishell.git
cd minishell
make
```

This will produce a `minishell` executable in the project directory.

### Execution

```bash
./minishell
```

A prompt will appear. Type commands just like in bash:

```bash
minishell$ echo "Hello, World!"
Hello, World!

minishell$ ls -la | grep .c

minishell$ cat < infile.txt > outfile.txt

minishell$ export MY_VAR=42 && echo $MY_VAR
42

minishell$ exit
```

### Cleanup

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile from scratch
```

---

## Resources

### Documentation & References

- [Bash Reference Manual (GNU)](https://www.gnu.org/software/bash/manual/bash.html) — The official bash documentation, essential for understanding expected behavior.
- [The Open Group Base Specifications — Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) — POSIX standard for shell behavior.
- [readline Library Documentation](https://tiswww.case.edu/php/chet/readline/rltop.html) — Official docs for the GNU readline library used for the interactive prompt.
- [fork(2), execve(2), waitpid(2) — Linux man pages](https://man7.org/linux/man-pages/) — Core system calls used for process management.
- [Writing Your Own Shell — Stephen Brennan's Tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/) — A beginner-friendly walkthrough of building a shell in C.
- [CS:APP Chapter on Unix I/O and Processes](https://csapp.cs.cmu.edu/) — Great theoretical background on processes, signals, and file descriptors.

### Articles & Tutorials

- [Building a Shell in C — CodeVault YouTube series](https://www.youtube.com/c/CodeVault) — Practical video tutorials covering process creation and pipes.
- [Understanding File Descriptors and Redirections](https://www.digitalocean.com/community/tutorials/an-introduction-to-linux-i-o-redirection) — Clear explanation of I/O redirection concepts.
- [Unix Signals — signal(7) man page](https://man7.org/linux/man-pages/man7/signal.7.html)

### AI Usage
AI was used during this project for debugging (memory leaks etc..), understanding concepts and code review.