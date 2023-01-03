# wb (wordbook) 

wb is a lightweight vocabulary note management application that provides listing, deletion, insertion and showing functions.
by doing that it helps user to manage words and fasters the learning process.


## Programming Language and Tools

Programming Language: C, Bash <br>
Compiler: GNU GCC <br>
Build Tool: CMake 

## Dependencies

NCurses Library <br>
CMake (MIN 3.22)

## Installation

### Step 1: Download the Source codes

https://github.com/MertGunduz/wb

### Step 2: Change permissions of INSTALL.sh

```sh
chmod 755 INSTALL.sh
```
running this command will change the permission of the INSTALL.sh

### Step 3: Run INSTALL.sh

```sh
./INSTALL.sh
```
running this bash file will build the application and create the folders.
##### Note: it can ask for sudo permission

### Step 4: Test Application

try running
```sh
wb -h
```
if there are some output related to wb then it means it is successfully builded

## How to use

### Adding Words

```sh
wb -a
wb --add
```
opens a ncurses terminal UI and prompts vocabulary data from the user

### Listing Words

```sh
wb -l
wb --list
```
opens a ncurses terminal UI and lists every word in the words.txt file

### Showing Words

```sh
wb -w [WORD NAME]
wb --word [WORD NAME]
```
outputs the vocabulary notes of the given word cli-argument

### Deleting Words

```sh
wb -d [WORD NAME]
wb --delete [WORD NAME]
```
deletes the word from the words.txt and the word file

### Help

```sh
wb -h
wb --help
```
outputs a detailed manuel about wb

### Showing Version

```sh
wb -v
wb --version
```
outputs the version of wb

### Showing Github

```sh
wb -g
wb --github
```
outputs the source code link of wb

### Exporting Data

```sh
wb -E
wb --export
```
creates a file named wbdata.txt and exports the application data to it

### Importing Data

```sh
wb -I
wb --import
```
imports the data to the system if wbdata.txt is in the working directory
