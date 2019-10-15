#ifndef DEPARTMENTITEM_H
#define DEPARTMENTITEM_H
#include <string>
using namespace std;

class DepartmentItem{
    public:
        DepartmentItem();
        DepartmentItem(int id, string name, int empCount);

        int getDepartmentId();
        string getDepartmentName();
        int getEmployeeCount();

        void setDepartmentId(int id);
        void setDepartmentName(string name);
        void setEmpCount(int empCount);


    private:
        int id;
        string name;
        int empCount;

};

#endif // DEPARTMENTITEM_H
