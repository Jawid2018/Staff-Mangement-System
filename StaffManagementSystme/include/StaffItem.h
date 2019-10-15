#ifndef TODOITEM_H
#define TODOITEM_H
#include <string>

using namespace std;

class StaffItem{
    private:
        int id;
        string name;
        string designation;
        string dob;
        int department_id;
        int salary;
        int code;
        int experience;
        string password;
        string address;
        string phoneNumber;

    public:
        StaffItem(int id,string name,string designation,string dob,int department_id,int salary,int code,int experience);
        StaffItem();
        string toString();

        int getId();
        string getName();
        string getDesignation();
        string getDob();
        int getDepartmentId();
        int getPriority();
        int getSalary();
        int getCode();
        int getExperience();
        string getAddress();
        string getPassword();
        string getPhoneNumber();

        void setId(int id);
        void setName(string name);
        void setDob(string dob);
        void setDepartmentId(int id);
        void setSalary(int salary);
        void setCode(int code);
        void setDesignation(string name);
        void setExperience(int exp);
        void setAddress(string address);
        void setPhoneNumber(string phoneNumber);
        void setPassword(string password);

};

#endif // TODOITEM_H
