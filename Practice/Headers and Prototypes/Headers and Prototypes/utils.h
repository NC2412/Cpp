
// '#pragma once' does the same thing as the mulitple lines of code.


/* When your program is built, there are several stages.
   The first stage is the preprocessor.
        the preprosessor looks for # symbols.
        # statements don't need ; because they are not statements directly to the C++ compiler.
    
    These header files keep prototypes organized and easy to access and look at.
*/

// #ifndef devines UTILS_H_ as the symbol of this file.
// The naming convention is the name of the file with an _ at the end.
#ifndef UTILS_H_
// #define defines the file, if not defined already, and allows the following code to run.
#define UTILS_H_
// Both of the statements above ensure this header cannot be defined or called multiple times.

// Functions must be defined after the upper headers and before the #endif.
void do_something();

// #endif ends the file.
#endif