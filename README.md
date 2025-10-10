# Pipex

`pipex` is a [42 School](https://42.fr) project that replicates the behavior of shell piping (`|`).
It teaches process creation, file descriptors, redirection, and inter-process communication through the `pipe()` and `execve()` system calls.

---

## 🧠 Project Overview

The goal of **pipex** is to reproduce the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

Your program must execute **two commands**, connecting the output of the first to the input of the second via a UNIX pipe.

---

## ⚙️ Usage

### 1. Clone and compile

```bash
git clone https://github.com/DMendes10/Pipex.git
cd pipex
make
```

This will generate the `pipex` executable.

---

### 2. Run the program

```bash
./pipex infile "cmd1" "cmd2" outfile
```

It should behave exactly like:

```bash
< infile cmd1 | cmd2 > outfile
```

### Example

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Equivalent to:

```bash
< infile grep hello | wc -l > outfile
```

---

## 🔧 Implementation Details

Your program must:

* Use **four file descriptors**:

  * `infile`, `outfile`, and two ends of the pipe.
* Use **`fork()`** to create child processes.
* Use **`dup2()`** to redirect input/output.
* Use **`execve()`** to execute commands.
* Handle **errors** (e.g. command not found, invalid files).
* Properly **close all FDs** and **free memory**.

---

## 🧮 Error Handling

The program should gracefully handle:

* Nonexistent input files
* Invalid permissions
* Commands not found
* Empty paths
* Memory allocation errors

Example:

```bash
./pipex infile "invalidcmd" "wc -l" outfile
bash: invalidcmd: command not found
```

---

## 🧠 Learning Goals

* Understanding **UNIX process control**
* Using **pipes** for inter-process communication
* Managing **file descriptors** properly
* Implementing **redirection** and **error propagation**

---

## 👤 Author

* **Name:** Diogo Mendes
* **42 Login:** Diomende
---

🧩 *Where there’s a pipe, there’s a way. *
