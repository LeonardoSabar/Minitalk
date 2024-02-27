# minitalk

Para acessar a versão em português deste README [clique aqui](https://github.com/LeonardoSabar/Minitalk/blob/master/README_pt_br.md).

<p align="center">
<img src="https://github.com/LeonardoSabar/Minitalk/blob/master/minitalk.gif" width="800px" alt="mandatory"/><br>
</p>

## Description

The minitalk project is a C programming assignment where students create a client-server communication system using UNIX signals. The client sends a string message to the server by encoding it into binary and sending it bit by bit using signals. This project helps students understand signal handling and inter-process communication concepts.

## Code style

The code style used in this project is the [Norminette](https://github.com/42School/norminette)
created by the 42 school and used in all related ANSI C projects in the context of the school.


<br>


## Installation

This project use the external library [Libft](https://github.com/LeonardoSabar/printf) and [printf]()
developed in the 42 school curriculum, to clone this project and this library use the command:

```sh
git clone --recursive git@github.com:LeonardoSabar/minitalk.git
```

**<em> this command will clone the project and the Libft submodule </em>**


</br>

To compile the **mandatory** part use:
```sh
make
```

To compile the **bonus** part use:

```sh
make bonus
```

## Usage

After compiling the project, the executables files with the names **server** and **client** will be created. First, you should execute the .server file to generate the PID, and then execute the .client file (preferably in a new terminal, parallel to the .server), along with the PID and the message as arguments:

Examples:

```sh
./server
```

```sh
./client "PID NUMBER" "MESSAGE TO NE SENT"
```

**<em> If the message to be sent is a sentence, you should use quotes to pass it as a single argument.</em>**

## Appreciation

To all my colleagues at 42 SP school, who helped me during the development of this project.
