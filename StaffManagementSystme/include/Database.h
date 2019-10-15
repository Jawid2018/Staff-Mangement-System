#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <sqlite3.h>
#include<StaffItem.h>
#include <Utilities.h>
#include <iostream>
#include <DatabaseContract.h>
#include <StaffView.h>
#include <DepartmentItem.h>
#include <DepartmentView.h>
#include <LoginView.h>


using namespace std;

class Database {
    public:
        Database();
        ~Database();
        sqlite3 *db;
        static StaffItem staffItem;
        static string callbackName;

        static int callback(void *data, int argc, char **argv, char **azColName);
        void opentDatabase();
        void closeDatabase();

        int insertData(string query);
        int updateData(string query);
        int deleteData(string query);
        int selectData(string callbackName,string query);

        void createDatabase();
        int createTables();
        int createDepartmentTable();
        int dropTable(string tableName);
};
#endif // DATABASE_H
