#ifndef LOGINUTILS_H
#define LOGINUTILS_H
#include <string>
#include <StaffItem.h>

using namespace std;

class LoginUtils
{
     private:
        static int userId;
        static StaffItem staffItem;

     public:
        static int getUserId();
        static void setUserId(int userId);
        static void onUserDataFetchSuccess(StaffItem staffItem);
        static void login(string password);
        static bool isLoginValid();
};

#endif // LOGINUTILS_H
