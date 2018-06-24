/*

Explanation and best practice on use of extern and globals:

https://stackoverflow.com/a/1433387

Using extern is only of relevance when the program you're building
consists of multiple source files linked together, where some of the
variables defined, for example, in source file file1.c need to be
referenced in other source files, such as file2.c.

It is important to understand the difference between defining a
variable and declaring a variable:

A variable is declared when the compiler is informed that a variable
exists (and this is its type); it does not allocate the storage
for the variable at that point.  A variable is defined when the
compiler allocates the storage for the variable.

You may declare a variable multiple times (though once is sufficient);
you may only define it once within a given scope. A variable
definition is also a declaration, but not all variable declarations
are definitions.

*/
#include "file3.h"
#include "prog1.h"
#include <stdio.h>

int main(void)
{
    use_it();
    global_variable += 19;
    use_it();
    printf("Increment: %d\n", increment());
    return 0;
}
