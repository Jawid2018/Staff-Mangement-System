#ifndef DEPARTMENTVIEW_H
#define DEPARTMENTVIEW_H
#include <BaseView.h>
#include <DepartmentItem.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <Repository.h>

using namespace std;

class DepartmentView : public BaseView<DepartmentItem>{
    public:
        DepartmentView();

        void addNewDepartment();
        void printAllDepartment();
        void printHeaderTitle();
        void printDepartmentById();
        void deleteDepartmentById();

    private:
        void selectDepartmentById(int id);
        int getDepartmentId(string action);
};

#endif // DEPARTMENTVIEW_H
