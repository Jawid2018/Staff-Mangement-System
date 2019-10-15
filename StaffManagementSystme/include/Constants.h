#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

using namespace std;

class Constants{
    public:
        static const int MANAGER_CODE;
        static const int DIRECTOR_CODE;
        static const int HR_CODE;
        static const int EMPLOYEE_CODE;

        static string PASSWORD;

        static const string MANAGER;
        static const string DIRECTOR;
        static const string HR;
        static const string EMPLOYEE;

        static string getProfileByCode(int code);
        static bool isLoginDataValid(string password,int code);


};

#endif // CONSTANTS_H
