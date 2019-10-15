#ifndef STAFFVIEW_H
#define STAFFVIEW_H
#include <BaseView.h>
#include <iostream>
#include <StaffItem.h>
#include <string.h>
#include <Repository.h>
#include <iomanip>
#include <Constants.h>
#include <LoginUtils.h>
#include <LoginView.h>

using namespace std;

class StaffView : public BaseView <StaffItem>{
    public:
        StaffView();
        void addNewStaff();
        void printAllStaff();
        void printHeaderTitle();
        void printStaffById(bool isSearch);
        void deleteStaffById();
        void updateStaffByID(string accessLevel);
        void printUserPassword(string password);
        void resetStaffPassword();

        void printAllManagers();
        void printAllHumanResouce();
        void printStaffByDepartmentId(int deprtId);

    private:
        int getStaffId(string action);
        int getFieldOptionToUpdate();
        int getFiedlOptionToUpdateStaff();
        string getFiedNameAccordingToOption(int option);
        string getNewDataToUpdate(int option);
        string getNewDataToUpdateStaff(int option);
        void getStaffById(int id);
};



#endif // STAFFVIEW_H
