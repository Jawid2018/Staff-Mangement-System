#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <iostream>
#include <Constants.h>

using namespace std;

class Utilities{
    public:
        Utilities();

        static void printEmpolyeeOptionsMenu();
        static void printManagerOptionsMenu();
        static void printHrOptionsMenu();
        static void printDirectorOptionsMenu();
        static void printUserWelcomeMEssage(string userName, int code);
        static void printInvlidLoginMessage();
        static void printMainScreenWelcomeMessage();
        static void printLoginMessage();

       static char *stringToChar(string text);

       private:
            static void printHeader();
};

#endif // UTILITIES_H
