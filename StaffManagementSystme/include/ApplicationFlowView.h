#ifndef APPLICATIONFLOWVIEW_H
#define APPLICATIONFLOWVIEW_H
#include <iostream>
#include <string>
#include <Constants.h>
#include <LoginView.h>
#include <stdlib.h>
#include <StaffView.h>
#include <Database.h>
#include <LoginView.h>

class ApplicationFlowView{

    public:
        ApplicationFlowView();
        static void navigateToScreenByCode(int code);
        static int optionCode;

    private:
        static void employeeOperations();
        static void humanResourceOperations();
        static void directorOperations();
        static void managerOperations();

        static void displayBaseOptions();
        static void displayOptions(int code);
        static int getOption();
        static void baseNaviagation(int code);
};

#endif // APPLICATIONFLOWVIEW_H
