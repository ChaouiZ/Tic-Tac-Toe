#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include "Header.h"

/*
Practice Tic-Tac-Toe project.

Goals:
    1. Knock off the rust.
    2. Review lessons learned in Programming II.
    3. Have fun.

I plan to implement the basic logic, and then make it way more complicated than I need to by adding
pointers, OO organization, vectors, and recursion. After I get all that done, I want to make it
into Ultimate Tic-tac-toe (Tictic - Tactac - Toetoe, as I call it) (Tic-Tac-Toe in which every
square is itself a game of Tic-Tac-Toe).
*/
/*
               |              |
               |              |
     1111      |     2222     |     3333
       11      |    22  22    |    33  33
       11      |       22     |       333
       11      |      22      |    33  33
     111111    |    222222    |     3333
               |              |
               |              |
               |              |
_____________________________________________
               |              |
               |              |
    44  44     |    555555    |     6666
    44  44     |    55        |    66
    444444     |    55555     |    66666
        44     |        55    |    66  66
        44     |    55555     |     6666
               |              |
               |              |
_____________________________________________
               |              |
               |              |
     777777    |     8888     |     9999
        77     |    88  88    |    99  99
       77      |     8888     |     99999
      77       |    88  88    |        99
     77        |     8888     |     9999
               |              |
               |              |
Win Conditions:
[ 1,2,3 | 4,5,6 | 7,8,9 | 1,4,7 | 2,5,8 | 3,6,9 | 1,5,9 | 3,5,7 ]

         ^   ^
       1 | 2 | 3
    < - - - - - - >
       4 | 5 | 6
    < - - - - - - >
       7 | 8 | 9
         #   #
*/

int main()
{

    printBoard();
    game();

    return 0;
}

