#include "DepartmentItem.h"

DepartmentItem::DepartmentItem(){
    DepartmentItem::id = 0;
    DepartmentItem::name = "";
    DepartmentItem::empCount = 0;
}

DepartmentItem::DepartmentItem(int id, string name, int empCount){
    DepartmentItem::id = id;
    DepartmentItem::name = name;
    DepartmentItem::empCount = empCount;
}

int DepartmentItem::getDepartmentId(){
    return DepartmentItem::id;
}

string DepartmentItem::getDepartmentName(){
    return DepartmentItem::name;
}

int DepartmentItem::getEmployeeCount(){
    return DepartmentItem::empCount;
}

void DepartmentItem::setDepartmentId(int id){
    DepartmentItem::id = id;
}

void DepartmentItem::setDepartmentName(string name){
    DepartmentItem::name = name;
}

void DepartmentItem::setEmpCount(int empCount){
    DepartmentItem::empCount = empCount;
}
