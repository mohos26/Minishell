# Minishell

**Minishell** is a custom Unix-like command-line shell written in **C** as part of the 42 School curriculum.  
It aims to mimic core behaviors of Bash by handling commands, built-ins, environment variables, redirections, pipes, and signals using low-level POSIX system calls.

---

## 🐚 Overview

A shell is a command interpreter that reads user input, parses it, and executes system commands and built-ins.  
This project deepens your understanding of:

- **Process creation and management** with `fork`, `execve`, `waitpid`, etc. :contentReference
- **Input parsing and syntax handling**
- **File descriptor redirection and pipes** (`|`, `<`, `>`, `>>`, `<<`) :contentReference
- **Signal handling** (e.g., `Ctrl+C`, `Ctrl+D`, `Ctrl+\\`) :contentReference
- **Environment variable expansion** (`$HOME`, `$?`, etc.) :contentReference

Minishell respects the **42 coding standards (Norminette)** and is fully implemented in **C**.

---

## 🧰 Features

### ✓ Mandatory Features

- Prompt display and user input loop  
- Execution of system commands found in `$PATH`  
- Built-in commands:
  - `echo`
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`  
- Environment variable expansion  
- Redirections: `>`, `>>`, `<`, `<<` (here-document)  
- Pipes (`|`)  
- Signal handling for typical interactive shell behavior

### ✨ Optional / Bonus (if implemented)

*(Include here any bonus features you have — e.g., wildcard expansion, logical operators `&&`/`||`, enhanced line editing, etc.)*

---

## ⚙️ Requirements

Minishell is written in C and relies on:

- POSIX-compatible system calls
- GNU Make
- A C compiler (`gcc` or compatible)

---

## 🛠️ Build & Run

1. **Clone the repository**

   ```bash
   git clone https://github.com/mohos26/Minishell.git
   cd Minishell


2. **Compile**

   ```bash
   make
   ```

3. **Run the shell**

   ```bash
   ./minishell
   ```

   You should see your custom shell prompt. Now you can type commands!

---

## 📌 Usage Examples

Inside the shell:

```sh
$ echo Hello World
Hello World
$ pwd
/home/user
$ ls -l | grep txt
$ export MYVAR=42
$ echo $MYVAR
42
$ exit
```

*(Adjust examples based on features you’ve implemented.)*

---

## 🚀 How It Works (High-Level)

1. **Input Reading:** Read user input line.
2. **Lexing & Parsing:** Tokenize input and build command structures.
3. **Execution:** Fork processes and run external commands or built-ins.
4. **Redirections/Pipes:** Manage file descriptors for command chaining.
5. **Cleanup:** Free allocated memory and handle signals.

---

## 🧩 Project Structure

```
Minishell/
├── Makefile
├── src/
├── includes/
├── utils/
├── header.h
├── parser.c
├── executor.c
└── ...
```

*(Adjust to match your repository’s actual structure.)*

---

## 🧪 Testing & Debugging

You can add a test suite or use external testers like `minishell_tester` (if you have one) to validate behavior against Bash.
---

## 🙌 Acknowledgments

Thanks to the 42 School curriculum and community for the project specifications and inspiration.
