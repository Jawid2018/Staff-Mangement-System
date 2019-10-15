
#include "Repository.h"

Repository::Repository()
{}

void Repository::insertData(StaffItem staffItem){
    Database db;

    string sql = "INSERT INTO "+DatabaseContract::STAFF_TABLE_NAME+ " ( "
    +DatabaseContract::NAME+", "
    +DatabaseContract::DESIGNATION+", "
    +DatabaseContract::DOB+", "
    +DatabaseContract::SALARY+", "
    +DatabaseContract::CODE+", "
    +DatabaseContract::YEAR_OF_EXPERIENCE+", "
    +DatabaseContract::PHONE_NUMBER+", "
    +DatabaseContract::ADDRESS+", "
    +DatabaseContract::PASSWORD+", "
    +DatabaseContract::DEPARTMENT_ID+" ) "
    +"VALUES ( \'"
    +staffItem.getName()+"\', \'"
    +staffItem.getDesignation()+"\', \'"
    +staffItem.getDob()+"\', "
    +to_string(staffItem.getSalary())+", "
    +to_string(staffItem.getCode())+", "
    +to_string(staffItem.getExperience())+", \'"
    +staffItem.getPhoneNumber()+"\', \'"
    +staffItem.getAddress()+"\', \'"
    +staffItem.getPassword()+"\', "
    +to_string(staffItem.getDepartmentId())+"); ";

    db.insertData(sql);
}

void Repository::insertData(DepartmentItem departmentItem){
    Database db;

    string sql = "INSERT INTO "+DatabaseContract::DEPARTMENT_TABLE_NAME+" ( "
    +DatabaseContract::DEPARTMENT_NAME+" ) "
    +"VALUES (\'"
    +departmentItem.getDepartmentName()+"\');";

    db.insertData(sql);
}

int Repository::selectData(string callbackName,string sql){
    Database db;
    int isSelected = db.selectData(callbackName,sql);
    return isSelected;
}

void Repository::deleteData(string sql){
    Database db;
    db.deleteData(sql);
}

void Repository::updateData(string sql){
    Database db;
    db.updateData(sql);
}























