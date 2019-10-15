#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <StaffItem.h>
#include <iostream>
#include <sqlite3.h>
#include <Database.h>
#include <DepartmentItem.h>

class Repository
{
    public:
        Repository();
        void insertData(StaffItem staffItem);
        void insertData(DepartmentItem departmentItem);

        int selectData(string callbackName,string sql);
        void deleteData(string sql);
        void updateData(string sql);
};

#endif // REPOSITORY_H
