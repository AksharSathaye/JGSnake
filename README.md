## Dedication

JGSnake is dedicated to the principles of the GNU Project and the Free Software Foundation.
In the incredibly unlikely (but wonderous) event that the GNU Project accepts this program into its repository of GNU programs, this program shall be renamed to GNU Snake.
It is developed with the spirit of free software in mind and aims to adhere to the values of freedom, openness, and collaboration that the GNU Project promotes.
Let us not be a snake ourselves by not sharing the source code with other people that would potentially benefit from it!
Feel free to modify, share, and enjoy the game under the terms of the [GNU General Public License (GPL)](https://www.gnu.org/licenses/gpl-3.0.html).

## What is JGSnake?

JGSnake is a fully libre implementation of the popular retro arcade game "Snake."
It is written in C++20, with the SFML graphics library.

(TODO: Add licensing of SFML in this project)

## Build Instructions

1. Clone the Repository.
```
$ git clone <this_repo_uri>
```
2. Install the `sfml` library and `g++` depending on your operating system (This example is for Arch Linux)
```
$ sudo pacman -S sfml base-devel make
```
3. Run the makefile, 
```
$ cd sfml-project
$ make clean
$ make
```
4. Run the program.
```
$ ./jgsnake
```