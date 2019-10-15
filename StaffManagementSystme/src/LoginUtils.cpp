#include "LoginUtils.h"


void LoginUtils::login(string password){

}

int LoginUtils::getUserId(){
    return LoginUtils::userId;
}

void LoginUtils::setUserId(int userId){
    LoginUtils::userId = userId;
}

void LoginUtils::onUserDataFetchSuccess(StaffItem staffItem){
    LoginUtils::staffItem = staffItem;

    if(isLoginValid()){
            Utilities::printUserWelcomeMEssage(staffItem::getName());

    }
}

bool LoginUtils::isLoginValid(){
    if(LoginUtils::userId == 0){
        return false;
    }
}



int LoginUtils::userId = 0;
