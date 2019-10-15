#ifndef LOGINVIEW_H
#define LOGINVIEW_H
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <Constants.h>
#include <ApplicationFlowView.h>
#include <Repository.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>

using namespace std;
class LoginView{

    public:
        static void displayLoginScreen();
        static int getUserId();
        static StaffItem staffItem;
        static void onUserDataFetchSuccess(StaffItem staffItem);
        static void setPassword(string password);
        static string getPassword();

    private:
        static int userId;
        static string userPassword;

        static void setUserId(int userId);
        static void validateLoginDetails();
        static void getLoginDetailsFromUser();
        static bool isLoginValid();
};

#endif // LOGINVIEW_H
