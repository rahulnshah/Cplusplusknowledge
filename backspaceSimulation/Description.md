## Description 
Write a C++ program that reads a text file, corrects mistakes in the text file by erasing specified characters in the file.  Use a stack to store individual characters in the text file.  Output the corrected content in a new text file caled outputFile.txt. 
The '#' denotes a backspace key here. 

## Pseudocode
open file for reading<br>

initialize an empty stack<br>
while all chars have not been read:<br>
&nbsp;&nbsp;&nbsp;&nbsp;if character is anything other than '#':<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;push character on the stack<br>
&nbsp;&nbsp;&nbsp;&nbsp;else:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if stack is not empty:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pop the last pushed character from the stack.
            
close file<br>

pop and attach all charachters from the stack to an empty string<br> 
reverse the string because popping takes place at the last character in the file<br> 

open output file in writing mode<br> 
overwrite the output file with the reversed string.  

- [Source code](backspaceSimulation.cpp) 

