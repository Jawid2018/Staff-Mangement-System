#include "Constants.h"

const int Constants::DIRECTOR_CODE = 400;
const int Constants::MANAGER_CODE = 200;
const int Constants::HR_CODE = 300;
const int Constants::EMPLOYEE_CODE = 100;

string Constants::PASSWORD = "password@123";

const string Constants::MANAGER ="MANAGER";
const string Constants::EMPLOYEE ="EMPLOYEE";
const string Constants::DIRECTOR ="DIRECTOR";
const string Constants::HR ="HR";

string Constants::getProfileByCode(int code){
    switch(code){
        case Constants::DIRECTOR_CODE:
            return Constants::DIRECTOR;

        case Constants::MANAGER_CODE:
            return Constants::MANAGER;

        case Constants::EMPLOYEE_CODE:
            return Constants::EMPLOYEE;

        case Constants::HR_CODE:
            return Constants::HR;
    }
}

bool Constants::isLoginDataValid(string password, int code){
    if((code == Constants::DIRECTOR_CODE || code == Constants::MANAGER_CODE
        || code == Constants::HR_CODE || code == Constants::EMPLOYEE_CODE) && password == Constants::PASSWORD){
            return true;
    }

    return false;
}
