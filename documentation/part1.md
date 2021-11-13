# Programming Submission for Part 1 - WEC'21
> Paige Liebster, Aiden Fox-Ivey, Nicole Nassar

### Contents
1. IO 
2. Timing Logic
3. Keyboard Position 
4. Test Generation Script


## IO

The input for the program is handled in C++ using fstream. Since the file endings originally gave us some trouble, we opted to introduce some code to properly read CRLF formatted files and avoid rewriting over the buffer.  

File handling was implemented to avoid having any sort of issues where the program would hang without letting the user know what was occurring.   

Essentially, the logic reads information into a buffer and checks to ensure that if it ends with a carriage return, then it will remove the carriage return and carry on in Unix fashion.  

## Timing Logic

Timing logic flow starts with the assumption that no keys have been pressed, initializing `time_elapsed` at 0.0 and then invokes the separate rules as per the order of them. If a line being read in has a length longer than one, it will actually consider what consecutive letters might be pressed, but it otherwise simply determines whether the letter is a capital or is the second/third in a series.  

If the line is greater than one, it will iterate through the remaining ones, considering what was before and what was after, then computing the change time elapsed.

At the end, the function returns whatever value has been accumulated.

## Keyboard Position

The keyboard position takes the letter, turns it down to an index, divides it by 3 for most cases, which reveals the location. Otherwise, special cases are hard coded.

## Test Generation Script

A simple Python3 script has been included to allow generation of text separated values. Now, this generator does provide only Unix end line formats, so it's not necessarily as representative of the other ones, but can be used to test values up to millions of lines of inputs. 

The output from running a 1 million line file generated from this program took 151340 microseconds as measured by C++'s high resolution clock.

