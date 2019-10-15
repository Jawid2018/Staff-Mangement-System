#include "LoginView.h"

void LoginView::displayLoginScreen(){
    system("clear");
    Utilities::printMainScreenWelcomeMessage();
    getLoginDetailsFromUser();
}

void LoginView::getLoginDetailsFromUser(){
    int id;
    string password;
    cout<<endl;
    cout<<endl;
    cout<<"\t Enter user ID --> ";
    cin>>id;
    cout<<"\t Enter password --> ";
    cin>>password;

    if(id == 0 || password == ""){
        Utilities::printInvlidLoginMessage();
        getLoginDetailsFromUser();
    }else{
        LoginView::setUserId(id);
        LoginView::userPassword = password;
        validateLoginDetails();
    }
}


void LoginView::validateLoginDetails(){
    Repository repository;
    string query = "SELECT * FROM "+DatabaseContract::STAFF_TABLE_NAME+"  WHERE "+DatabaseContract::ID+" = "+to_string(LoginView::getUserId());
   repository.selectData(DatabaseContract::LOGIN_CALLBACK,query);
}

int LoginView::getUserId(){
    return LoginView::userId;
}

void LoginView::setUserId(int userId){
    LoginView::userId = userId;
}

void LoginView::onUserDataFetchSuccess(StaffItem staffItem){
    LoginView::staffItem = staffItem;

    if(isLoginValid()){
        Utilities::printLoginMessage();
        std::this_thread::sleep_for (std::chrono::seconds(3));
        Utilities::printUserWelcomeMEssage(LoginView::staffItem.getName(),LoginView::staffItem.getCode());
        ApplicationFlowView::navigateToScreenByCode(staffItem.getCode());
    }else{
        Utilities::printInvlidLoginMessage();
        getLoginDetailsFromUser();
    }
}

bool LoginView::isLoginValid(){
    if(LoginView::userId == 0){
        return false;
    }
    if(LoginView::getUserId() == LoginView::staffItem.getId() &&
            LoginView::userPassword == LoginView::staffItem.getPassword()){
                return true;
    }

    return false;
}

void LoginView::setPassword(string password){
    LoginView::userPassword = password;
}

string LoginView::getPassword(){
    return LoginView::userPassword;
}

int LoginView::userId = 0;
string LoginView::userPassword = "";
StaffItem LoginView::staffItem = StaffItem();

