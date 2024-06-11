# Carbon Shell 
Carbon shell is a *modern* shell intended to blow your expecations out of the water.
It has incredible features such as *echo*, *exit*, and so much more!

## Prerequisites 

This program is intended to run in a Unix-like environment (macOS, Linux, FreeBSD, etc.).

You will also need to have [make](https://www.gnu.org/software/make/) installed to build the 
project. 

## Installation

1. Clone the repository to your chosen directory. This is often done with a command along the 
lines of
```
git clone https://github.com/kaedyn01/carbon-shell.git
```

2. Next, you'll need to build the project. You can do this by running the following command:
```
make build 
```
This will build the program and put a working executable named *csh* in the build folder.

## Usage 

You can then run the program by typing in the following commands whilst at the top of the project
directory:
```
./build/csh
```

You can then use Carbon Shell like you would use any other shell. 

## Testing 

If you would like to test the program's functionality you can do so by running the following
command at the top of the project directory:
```
make run_test
```
This will build the shell and test program, outputting the results of the test to the standard
output.
