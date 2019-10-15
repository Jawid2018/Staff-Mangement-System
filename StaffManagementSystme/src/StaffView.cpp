#include "StaffView.h"

StaffView::StaffView(){

}

template<>
StaffItem BaseView<StaffItem>::getDataFromConsole(){
    //create staffItem object to get data from user
    StaffItem staffItem;
    string input = " ";

    cout<<endl;
    cout<<"\tEnter staff details: "<<endl;

    getline(cin,input);
    cout<<"\t Name --> ";
    getline(cin,input);
    staffItem.setName(input);

    cout<<"\t Designation --> ";
    getline(cin,input);
    staffItem.setDesignation(input);

    cout<<"\t Date of birth --> ";
    getline(cin,input);
    staffItem.setDob(input);

    cout<<"\t Department ID --> ";
    getline(cin,input);
    //stoi function converts string to int
    staffItem.setDepartmentId(stoi(input));

    cout<<"\t Monthly salary --> ";
    getline(cin,input);
    //stod function converst string to double
    staffItem.setSalary(stod(input));

    cout<<"\t Code --> ";
    getline(cin,input);
    staffItem.setCode(stoi(input));

    cout<<"\t Year of experience --> ";
    getline(cin,input);
    staffItem.setExperience(stoi(input));

    cout<<"\t Address --> ";
    getline(cin,input);
    staffItem.setAddress(input);

    cout<<"\t Phone number --> ";
    getline(cin,input);
    staffItem.setPhoneNumber(input);

    staffItem.setPassword(Constants::PASSWORD);

    return staffItem;
}

template<>
void BaseView<StaffItem>::printDataToConsole(StaffItem staffItem){
    cout<<setw(10)<<staffItem.getId();
    cout<<setw(15)<<staffItem.getName();
    cout<<setw(15)<<staffItem.getDesignation();
    cout<<setw(18)<<staffItem.getDob();
    cout<<setw(10)<<staffItem.getSalary();
    cout<<setw(10)<<staffItem.getDepartmentId();
    cout<<setw(10)<<staffItem.getExperience();
    cout<<setw(10)<<staffItem.getCode();
    cout<<setw(15)<<staffItem.getAddress();
    cout<<setw(20)<<staffItem.getPhoneNumber();
    cout<<endl;
    cout<<endl;
}

void StaffView::addNewStaff(){
    StaffItem staffItem = getDataFromConsole();
    Repository repository;
    repository.insertData(staffItem);
}

void StaffView::printAllStaff(){
    Repository repository;

    printHeaderTitle();
    string query = "SELECT * from "+DatabaseContract::STAFF_TABLE_NAME;
    repository.selectData(DatabaseContract::STAFF_ITEM_CALLBACK,query);
}

void StaffView::printStaffById(bool isSearch){
    int id;
    if(isSearch){
        id = getStaffId("search");
    }else{
        id = LoginView::getUserId();
    }
    getStaffById(id);
}

void StaffView::printHeaderTitle(){
     cout<<endl;
     cout<<endl;
     cout <<"\t Id         Name       Designation          DOB      Salary    DeprID    Experience    Code        Address        Phone Number   "<<endl;
     cout <<"\t --------------------------------------------------------------------------------------------------------------------------------"<<endl;
}

void StaffView::deleteStaffById(){
    Repository repository;
    int id = getStaffId("delete");
    string query = "DELETE FROM "+DatabaseContract::STAFF_TABLE_NAME+" WHERE "+DatabaseContract::ID+" = "+to_string(id);
    repository.deleteData(query);
}

void StaffView::updateStaffByID(string accessLevel){
     Repository repository;
     string query;
     int userId, option;
     string fieldName;
     string newData;

     if(accessLevel == Constants::EMPLOYEE){
        userId = LoginView::getUserId();
        option = getFiedlOptionToUpdateStaff();
        newData = getNewDataToUpdateStaff(option);
     }else if(accessLevel == Constants::HR){
        userId = getStaffId("edit");
        option = getFieldOptionToUpdate();
        newData = getNewDataToUpdate(option);
    }

    fieldName = getFiedNameAccordingToOption(option);

     if(option == 3){
        query = "UPDATE "+DatabaseContract::STAFF_TABLE_NAME+" SET "+fieldName+" = "+newData+" WHERE "+DatabaseContract::ID+" = "+to_string(userId);
     }else{
        query = "UPDATE "+DatabaseContract::STAFF_TABLE_NAME+" SET "+fieldName+" = \'"+newData+"\' WHERE "+DatabaseContract::ID+" = "+to_string(userId);
     }


     repository.updateData(query);
     /**
      * Print the updated field if it is not password
     */

     if(option != 7){
        getStaffById(userId);
     }else{
        cout<<endl;
        LoginView::setPassword(newData);
      //  printUserPassword(LoginView::getPassword());
     }
}

int StaffView::getStaffId(string action){
     int id;
     cout<<"\t Enter ID to "<<action<<" -->  ";
     cin>>id;
     return id;
}

int StaffView::getFieldOptionToUpdate(){
    int option;
    cout<<endl;
    cout<<"\t Field to edit: "<<endl;
    cout<<"\t 1- Name,     2- Desination,      3- Salary,      4- Dob"<<endl;
    cout<<"\t Enter option --> ";

    cin>>option;
    return option;
}

int StaffView::getFiedlOptionToUpdateStaff(){
    int option;
    cout<<endl;
    cout<<"\t Field to edit: "<<endl;
    cout<<"\t 5- Address,      6- Phone Number,      7- Password"<<endl;
    cout<<"\t Enter option --> ";

    cin>>option;
    return option;
}

string StaffView::getFiedNameAccordingToOption(int option){
    switch (option){
        case 1:
            return DatabaseContract::NAME;
        case 2:
            return DatabaseContract::DESIGNATION;
        case 3:
             return DatabaseContract::SALARY;
        case 4:
             return DatabaseContract::DOB;
        case 5:
             return DatabaseContract::ADDRESS;
        case 6:
             return DatabaseContract::PHONE_NUMBER;
        case 7:
             return DatabaseContract::PASSWORD;
    }
}

string StaffView::getNewDataToUpdate(int option){
    string newData;
    switch (option){
       case 1:
            cout<<"\t Enter new name -> ";
            break;
       case 2:
            cout<<"\t Enter new designation -> ";
            break;
       case 3:
            cout<<"\t Enter new salary -> ";
            break;
       case 4:
            cout<<"\t Enter new date of birth -> ";
            break;
     }

    cin>>newData;
    return newData;
}

string StaffView::getNewDataToUpdateStaff(int option){
    string newData;
    switch (option){
    case 5:
        cout<<"\t Enter new address -> ";
        break;
    case 6:
        cout<<"\t Enter new phone number -> ";
        break;
    case 7:
        cout<<"\t Enter new password -> ";
        break;
    }

    cin>>newData;
    return newData;
}


void StaffView::getStaffById(int id){
    Repository repository;
    printHeaderTitle();
    string query = "SELECT * FROM "+DatabaseContract::STAFF_TABLE_NAME+" WHERE "+DatabaseContract::ID+" = " +to_string(id);
    repository.selectData(DatabaseContract::STAFF_ITEM_CALLBACK,query);
}

void StaffView::printAllManagers(){
     Repository repository;
     printHeaderTitle();
     string query = "SELECT * FROM "+DatabaseContract::STAFF_TABLE_NAME+" WHERE "+DatabaseContract::CODE+" = " +to_string(Constants::MANAGER_CODE);
     repository.selectData(DatabaseContract::STAFF_ITEM_CALLBACK,query);
}

void StaffView::printAllHumanResouce(){
     Repository repository;
     printHeaderTitle();
     string query = "SELECT * FROM "+DatabaseContract::STAFF_TABLE_NAME+" WHERE "+DatabaseContract::CODE+" = " +to_string(Constants::HR_CODE);
     repository.selectData(DatabaseContract::STAFF_ITEM_CALLBACK,query);
}

void StaffView::printStaffByDepartmentId(int deptId){
    Repository repository;
    printHeaderTitle();
    string query = "SELECT * FROM "+DatabaseContract::STAFF_TABLE_NAME+" WHERE "+DatabaseContract::DEPARTMENT_ID+" = " +to_string(deptId);
    repository.selectData(DatabaseContract::STAFF_ITEM_CALLBACK,query);

}

void StaffView::printUserPassword(string password){
    cout<<endl;
    cout<<"\t Your login password is -> [ "<<password<<" ]"<<endl;
    cout<<"\t Important! Your password is a confidential information, please don't share with anyone!"<<endl;

}

void StaffView::resetStaffPassword(){
    Repository repository;
    int userId = getStaffId("reset password");
    string password = Constants::PASSWORD;
    string query = "UPDATE "+DatabaseContract::STAFF_TABLE_NAME+" SET "+DatabaseContract::PASSWORD+" = \'"+password+"\' WHERE "+DatabaseContract::ID+" = "+to_string(userId);
    repository.updateData(query);
}










