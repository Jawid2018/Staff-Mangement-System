#include "DepartmentView.h"

DepartmentView::DepartmentView(){}

template<>
DepartmentItem BaseView<DepartmentItem>::getDataFromConsole(){
    DepartmentItem departmentItem;
    string input = " ";

    getline(cin,input);
    cout<<"\t Enter department name --> ";
    getline(cin,input);
    departmentItem.setDepartmentName(input);

    return departmentItem;
}


template<>
void BaseView<DepartmentItem>::printDataToConsole(DepartmentItem departmentItem){
    cout<<setw(10)<<departmentItem.getDepartmentId();
    cout<<setw(24)<<departmentItem.getDepartmentName();
    cout<<endl;
}

void DepartmentView::addNewDepartment(){
    Repository repository;

    DepartmentItem departmentItem = getDataFromConsole();
    repository.insertData(departmentItem);
}

void DepartmentView::printAllDepartment(){
    Repository repository;

    printHeaderTitle();
    string query = "SELECT * from "+DatabaseContract::DEPARTMENT_TABLE_NAME;
    repository.selectData(DatabaseContract::DEPTMENT_ITEM_CALLBACK,query);
}

void DepartmentView::printDepartmentById(){
    int id = getDepartmentId("to print details");
    selectDepartmentById(id);
}

void DepartmentView::printHeaderTitle(){
     cout<<endl;
     cout<<endl;
     cout <<"\t Id        Department Name     "<<endl;
     cout <<"\t ------------------------------"<<endl;
}

void DepartmentView::deleteDepartmentById(){
    Repository repository;
    int id = getDepartmentId("delete");
    string query = "DELETE FROM "+DatabaseContract::DEPARTMENT_TABLE_NAME+" WHERE "+DatabaseContract::DEPART_ID+" = "+to_string(id);
    repository.deleteData(query);
}

int DepartmentView::getDepartmentId(string action){
     int id;
     cout<<"\t Enter Department ID to "<<action<<" -->  ";
     cin>>id;
     return id;
}

void DepartmentView::selectDepartmentById(int id){
    Repository repository;
    printHeaderTitle();
    string query = "SELECT * FROM "+DatabaseContract::DEPARTMENT_TABLE_NAME+" WHERE "+DatabaseContract::DEPART_ID+" = " +to_string(id);
    repository.selectData(DatabaseContract::DEPTMENT_ITEM_CALLBACK,query);
}
