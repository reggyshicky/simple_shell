## The Simple Shell: A customised Shell Project
This project was completed by Reginah Shikanda and Sosthene Timi as part of the ALX SE collaboration project requirement. A shell is a program that provides a user an interface for accessing the operating system's services. It allowes users to interact with the computer's operating system through a command-line interface and execute various commands and operations. This simple shell project is an  imitation of the bash but with limited features.

## The Simple Shell Capabilties
* Displays a prompt and waits for a user to type a command. The command line always end with a new line
* The prompt is displayed each time a command has been executed.
* The commands line are simple, no semicolons, no pipes, no redirections.
* The command lines are made of only one word.
* If an executable cannot be found, print an error message and display the prompt again.
* It handles Errors
* It handles the EOF condition (Ctrl+D).
* It handles command lines with arguments, handles the PATH, implements exit built-ins and handles comments.

## Simple Shell Compilation
The Customised shell will compiled using gcc -Wall -Werror -Wextra -pedantic -std=gnu89 * .c hsh

## Simple Shell Built-in Commands
1. cd - command that changes directory
2. unsetenv - command that removes an environment variable.
3. setenv - command that initializes a new environment/modifies existing one
4. exit - command that exits a simple shell
5. env - command that list current environment variables
6. pwd - command that prints the path of the current working directory.

### Shell Delimiters & Comment Commands
1. Semicolon(;) - serves as a command seperator that enables the execution of multiple commands on a single line by placing the semicolon between each command.
2. Harsh - Using a word starting with a harsh symbol in a CLI, designates the rest of the characters on that line as a comment, causing them to be ignored when the command is executed.
### Shell Authors File
This file will contain the names of all contributors towards this simple shell project.
