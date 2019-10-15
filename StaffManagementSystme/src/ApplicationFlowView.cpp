#include "ApplicationFlowView.h"

ApplicationFlowView::ApplicationFlowView(){}

void ApplicationFlowView::navigateToScreenByCode(int code){
     baseNaviagation(code);
}

void ApplicationFlowView::humanResourceOperations(){
    StaffView staffView;
    DepartmentView departmentView;

    int option = getOption();
    switch(option){
        case 1:
            staffView.printStaffById(false);
            break;
        case 2:
            staffView.updateStaffByID(Constants::EMPLOYEE);
            break;
        case 3:
            staffView.printUserPassword(LoginView::getPassword());
            break;
        case 4:
            staffView.addNewStaff();
            break;
        case 5:
            staffView.printAllStaff();
            break;
        case 6:
            staffView.printStaffById(true);
            break;
        case 7:
            staffView.updateStaffByID(Constants::HR);
            break;
        case 8:
            staffView.resetStaffPassword();
            break;
        case 9:
            staffView.deleteStaffById();
            break;
        case 10:
            departmentView.printAllDepartment();
            break;
        case 11:
            departmentView.printDepartmentById();
            break;
        default:
         cout<<endl;
         cout<<"\t Invalid option! Try again"<<endl;
    }

    baseNaviagation(Constants::HR_CODE);
}

void ApplicationFlowView::directorOperations(){
    StaffView staffView;
    DepartmentView departmentView;
    Database db;

    int option = getOption();
    switch(option){
        case 1:
            staffView.printStaffById(false);
            break;
        case 2:
            staffView.updateStaffByID(Constants::EMPLOYEE);
        case 3:
            staffView.printUserPassword(LoginView::getPassword());
            break;
        case 4:
            staffView.printAllStaff();
            break;
        case 5:
            staffView.printStaffById(true);
            break;
        case 6:
            staffView.printAllHumanResouce();
            break;
        case 7:
           staffView.printAllManagers();
            break;
        case 8:
            departmentView.printAllDepartment();
            break;
        case 9:
            departmentView.printDepartmentById();
            break;
        case 10:
            departmentView.addNewDepartment();
            break;
        case 11:
            departmentView.deleteDepartmentById();
            break;
        case 12:
            cout<<endl;
            cout<<"\tCation!!! This is a very dangersous action. All data will be deleted permanently."<<endl;
            /**
               in this version of app, don't allow director to drop table.
            */
            //db.dropTable(DatabaseContract::STAFF_TABLE_NAME);
            break;
        case 13:
            cout<<endl;
            cout<<"\tCation!!! This is a very dangersous action. All data will be deleted permanently."<<endl;
            // db.dropTable(DatabaseContract::DEPARTMENT_TABLE_NAME);
            break;
        default:
         cout<<endl;
         cout<<"\t Invalid option! Try again"<<endl;
    }

    baseNaviagation(Constants::DIRECTOR_CODE);
}

void ApplicationFlowView::managerOperations(){
    StaffView staffView;

    int option = getOption();
    switch(option){
        case 1:
            staffView.printStaffById(false);
            break;
        case 2:
            staffView.updateStaffByID(Constants::EMPLOYEE);
            break;
        case 3:
            staffView.printUserPassword(LoginView::getPassword());
            break;
        case 4:
            staffView.printStaffByDepartmentId(LoginView::staffItem.getDepartmentId());
         default:
          cout<<endl;
          cout<<"\t Invalid option! Try again"<<endl;
    }

     baseNaviagation(Constants::MANAGER_CODE);
}

void ApplicationFlowView::employeeOperations(){
    StaffView staffView;
    int option = getOption();
    if(option == 1){
        staffView.printStaffById(false);
    }else if(option == 2){
        staffView.updateStaffByID(Constants::EMPLOYEE);
    }else if(option == 3){
        staffView.printUserPassword(LoginView::getPassword());
    }else{
        cout<<endl;
        cout<<"\t Invalid option! Try again"<<endl;
    }

    baseNaviagation(Constants::EMPLOYEE_CODE);
}


void ApplicationFlowView::displayOptions(int code){

    if(code == Constants::HR_CODE){
        Utilities::printHrOptionsMenu();
        humanResourceOperations();
    }else if(code == Constants::EMPLOYEE_CODE){
        Utilities::printEmpolyeeOptionsMenu();
        employeeOperations();
    }else if(code == Constants::DIRECTOR_CODE){
        Utilities::printDirectorOptionsMenu();
        directorOperations();
    }else{
        Utilities::printManagerOptionsMenu();
        managerOperations();
    }
}

int ApplicationFlowView::getOption(){
    int option;
    cout<<"\t Enter option --> ";
    cin>>option;

    return option;
}

void ApplicationFlowView::displayBaseOptions(){
    cout<<endl;
    cout<<"\t 1- Options menu "<<endl;
    cout<<"\t 2- Logout"<<endl;
    cout<<"\t 3- Exit"<<endl;
}

void ApplicationFlowView::baseNaviagation(int code){
    displayBaseOptions();
    int option = getOption();

    switch(option){
        case 1:
            displayOptions(code);
            break;
         case 2:
            LoginView::displayLoginScreen();
            break;
         case 3:
            exit(0);
            break;
         default:
            cout<<endl;
            cout<<"\t Invalid option! Please try again"<<endl;
            baseNaviagation(code);
    }
}

int ApplicationFlowView::optionCode = 0;















