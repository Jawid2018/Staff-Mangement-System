#ifndef DATABASECONTRACT_H
#define DATABASECONTRACT_H
#include <string>

using namespace std;

class DatabaseContract{

public:
static char* DATABAE_NAME;

static string STAFF_TABLE_NAME ;
static string ID;
static string NAME;
static string DESIGNATION;
static string DEPARTMENT_ID;
static string DOB;
static string SALARY;
static string CODE;
static string YEAR_OF_EXPERIENCE;
static string PHONE_NUMBER;
static string ADDRESS;
static string PASSWORD;

static string DEPARTMENT_TABLE_NAME;
static string DEPART_ID;
static string DEPARTMENT_NAME;

static string ERROR_MESSAGE;
static string DATA;

static const string STAFF_ITEM_CALLBACK;
static const string DEPTMENT_ITEM_CALLBACK;
static const string LOGIN_CALLBACK;


};




#endif
