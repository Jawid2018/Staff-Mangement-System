#include "StaffItem.h"

//constractor with all attribute parameter
StaffItem::StaffItem(int id,string name,string designation,string dob,int department_id,int salary,int code,int exp){
    StaffItem::id = id;
    StaffItem::name = name;
    StaffItem::designation = designation;
    StaffItem::dob = dob;
    StaffItem::department_id = department_id;
    StaffItem::salary = salary;
    StaffItem::code = code;
    StaffItem::experience = exp;
}

//constractor without parameter
StaffItem::StaffItem(){
    StaffItem::id = 0;
    StaffItem::name = "";
    StaffItem::designation = "";
    StaffItem::dob = "";
    StaffItem::department_id = 0;
    StaffItem::salary = 0;
    StaffItem::code = 0;
    StaffItem::experience = 0;
    StaffItem::address = "";
    StaffItem::phoneNumber = "";
    StaffItem::password = "";
}

//getters

int StaffItem::getId(){
    return StaffItem::id;
}

string StaffItem::getName(){
    return StaffItem::name;
}

string StaffItem::getDesignation(){
    return StaffItem::designation;
}

string StaffItem::getDob(){
    return StaffItem::dob;
}

int StaffItem::getDepartmentId(){
    return StaffItem::department_id;
}

int StaffItem::getSalary(){
    return StaffItem::salary;
}

int StaffItem::getCode(){
    return StaffItem::code;
}

int StaffItem::getExperience(){
    return StaffItem::experience;
}

string StaffItem::getAddress(){
    return StaffItem::address;
}

string StaffItem::getPhoneNumber(){
    return StaffItem::phoneNumber;
}

string StaffItem::getPassword(){
    return StaffItem::password;
}

//setters

void StaffItem::setId(int id){
   StaffItem::id = id;
}

void StaffItem::setName(string name){
    StaffItem::name = name;
}

void StaffItem::setDob(string dob){
    StaffItem::dob = dob;
}

void StaffItem::setDepartmentId(int id){
    StaffItem::department_id = id;
}

void StaffItem::setSalary(int salary){
    StaffItem::salary = salary;
}

void StaffItem::setCode(int code){
    StaffItem::code = code;
}

void StaffItem::setDesignation(string name){
    StaffItem::designation = name;
}

void StaffItem::setExperience(int exp){
   StaffItem::experience = exp;
}

void StaffItem::setAddress(string address){
    StaffItem::address = address;
}

void StaffItem::setPhoneNumber(string phoneNumber){
    StaffItem::phoneNumber = phoneNumber;
}

void StaffItem::setPassword(string password){
    StaffItem::password = password;
}










