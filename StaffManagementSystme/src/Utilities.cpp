#include "Utilities.h"

Utilities::Utilities()
{
    //ctor
}

 //this function converts string to a char of pointer
 char * Utilities::stringToChar(string text){
   return const_cast<char*>(text.c_str());
}

void Utilities::printEmpolyeeOptionsMenu(){
    printHeader();
    cout<<"\t 1-  My Profile "<<endl;
    cout<<"\t 2-  Edit Profile "<<endl;
    cout<<"\t 3-  My password "<<endl;
}

void Utilities::printManagerOptionsMenu(){
    printEmpolyeeOptionsMenu();
    cout<<"\t 4-  Generate Reoprt (My Department Staffs)"<<endl;
}

void Utilities::printHrOptionsMenu(){
    printEmpolyeeOptionsMenu();
    cout<<"\t 4-  Add new staff"<<endl;
    cout<<"\t 5-  Generate Report (Staffs)"<<endl;
    cout<<"\t 6-  Search (Staff)"<<endl;
    cout<<"\t 7-  Edit Staff details"<<endl;
    cout<<"\t 8-  Reset Password (set default)"<<endl;
    cout<<"\t 9-  Delete Staff From System"<<endl;
    cout<<"\t 10- Generate Report (Departments)"<<endl;
    cout<<"\t 11- Search (Department)"<<endl;
}

void Utilities::printDirectorOptionsMenu(){
    printEmpolyeeOptionsMenu();
    cout<<"\t 4-  Generate Report (All staffs)"<<endl;
    cout<<"\t 5-  Search (Staff)"<<endl;
    cout<<"\t 6-  Gnerate Report (Human Resource)"<<endl;
    cout<<"\t 7-  Gnerate Report (Managers)"<<endl;
    cout<<"\t 8-  Generate Report (Departments)"<<endl;
    cout<<"\t 9-  Search (Department)"<<endl;
    cout<<"\t 10- Add New Department"<<endl;
    cout<<"\t 11- Delete Department"<<endl;
    cout<<"\t 12- Drop Staff Table"<<endl;
    cout<<"\t 13- Drop Department Table"<<endl;
}

void Utilities::printMainScreenWelcomeMessage(){
    cout<<endl;
    cout<<endl;
    cout<<"\t \t \t Welcome to Spotlight Staff Management System"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t \t \t \t   ******* LOGIN *******                                "<<endl;
}

void Utilities::printHeader(){
    cout<<endl;
    cout<<"\tAvailable Options:"<<endl;
}

void Utilities::printUserWelcomeMEssage(string userName,int code){
    system("clear");
    string profile = Constants::getProfileByCode(code);
    cout<<endl;
    cout<<"\tAccess Granted to The System as --> ____ "<<profile<<" _____"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t \t \t \t *********** Dear "<<userName<<", Welcome Back! ************";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
}

void Utilities::printInvlidLoginMessage(){
    cout<<endl;
    cout<<"\t Invalid user ID or password. Please try again.";
}

void Utilities::printLoginMessage(){
        cout<<endl;
        cout<<endl;
        cout<<"\t \t \t Please wait...! We are login you in.";
        cout<<endl;
}


