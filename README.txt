CS530 Assignment 1
Carlos Lopez
cssc4002

This project includes my source code xed.cpp, my Makefile, and this README file. My xed.cpp was written using the CLion IDE. It was tested using a .txt file I wrote up. It was compiled using g++. 

Compilation instruction:
g++ xed.cpp -o xed

Operation instruction:
./xed <filename>
./xed -b <filename>

My program contains only a main method where everything is done. It takes the last command argument as the input file name and checks if binary output is requested but does hexadecimal by default. Binary output is defined through the -b command so if the count of commands is longer than just the executable and file input then binary output is done instead of hex. This means that when the second operation instruction is written, argc will be greater than 2 so my variable that tracks the base (either 2 or 16) will be initialized to 2. Otherwise, when the first operation instruction is written, then by default the base will be 16 and my while loop that has logic for hex output will occur.

 I could have done separate functions for printing in hex and printing in binary but I couldn’t find a way to pass my ifstream object as a parameter. An easier way would be to pass every char read from the file into a function but then I would have to add a bunch of conditions in my single while loop which I think would look ugly. So, I did two different loops for binary or hex which was easier for me and I believe looks better. 
