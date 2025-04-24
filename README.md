# SIMPLE SHELL - Holberton School

![Logo](https://i.imgur.com/s97X7hD.gif)

### 📄 Description
Simple Shell is a project that implements a basic UNIX shell in C. This shell allows users to execute simple commands with no arguments, without support for pipes, redirections, or any other advanced features. It provides a command-line interface that waits for a user to input a command, executes it, and handles errors, including EOF (End of File) conditions.

### 🔐 Requierments
- Ubuntu 20.04 LTS or any Linux distribution that supports POSIX-compliant shells.
- gcc for compiling C code.
- The shell uses the execve system call to execute external commands.

### 🔍 Files

| FILE  |DESCRIPTION|
| :--------------------: | :--------------------------: |
|`advanced.c` | Files with all the advanced task functions.|
|`env.c` |Files with all environnement function|
|`print_prompt.c` |File with the function that print the prompt.|
|`read_line.c` |File with the function that read the line of the user_input.|
|`tokenize.c` |File with the function that tokenize the user_input.|
|`shell.c`  |contains the functionsearch for a command in the PATH |
|`shell.h`   |Header file with all the prototypes of the functions.|
|`AUTHORS`|File with the authors of the project.|
|`man_1_simple_shell`| File of the man page of the shell.|
|`README.md`| File with the description of the project.|

## 🤔 Flowchart

![Mon image](https://imgur.com/JIRFPRK.png)

### 📄 Features

| Feature | Description |
| :--------------------: | :--------------------------: |
  |🔨**Command Execution:** |Executes external commands   (**ls**... ) using **==fork()==** and **==execve()==**.|                                                          
 |🧩 **Argument handling:** |The shell can handle arguments passed to commands (**ls -a**).|
  |🤖 **Built-in commands:** |Implementation of the **exit** command which allows you to quit the shell.|
|🧭**Path searching:** |Shell searches for commands in the directories specified by the **PATH** environmentvariable.|
|⚠️ **Error handling:** |Shell handles basics errors such as invalid commands or system call failures|
 |✏️**Two modes:**  |
|| - **Interactive mode:** The shell displays a prompt and waits for the user to type a command.|
||- **Non-interactive mode:** The shell reads commands from a file or a pipe and executes them.|

### Installation

Clone the repository from GitHub:
```bash
  git clone https://github.com/Ancelin-31/holbertonschool-simple_shell.git
```
Compile the project with gcc:
```bash
 gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Navigate to the project directory:
```bash
  cd holbertonschool-simple_shell
```

### Usage/Examples

1- Run the shell with the following command:
```bash
./hsh
```

2- Once the shell is running, it will prompt you for input. For example
The shell will execute the command and display the output:
```bash
$ ls
file1.txt  file2.txt  file3.txt
```

4- If the command is not found, it will show an error message:
```bash
./hsh: 1: command: not found
```

5- To exit the shell, type exit:
```bash
$ exit
```
6- If you press Ctrl+D, the shell will also terminate.

## Man Page

To access the man page, run the following command:
```man ./man_1_simple_shell```

![Logo](https://i.imgur.com/FoZtmro.png)
![Logo](https://i.imgur.com/mhQb50O.png)

###  Limitations

- It does not handle pipes, redirections, or any other advanced features.

###  🧑💻 Authors

[Ancelin Chevallier](https://github.com/Ancelin-31)

[Nael El Afia](https://github.com/Naellito)

**This is a simple shell project developed as part of the Holberton School curriculum.**
![Logo](https://i.imgur.com/EM7yY9D.png)
