#include "DatabaseContract.h"

char* DatabaseContract::DATABAE_NAME ="staffManagementSystem.db";
string DatabaseContract::STAFF_TABLE_NAME = "staff_table";
string DatabaseContract::ID ="id";
string DatabaseContract::NAME ="name";
string DatabaseContract::DESIGNATION ="designation";
string DatabaseContract::DEPARTMENT_ID ="department_id";
string DatabaseContract::DOB ="dob";
string DatabaseContract::SALARY ="salary";
string DatabaseContract::CODE ="code";
string DatabaseContract::YEAR_OF_EXPERIENCE = "experience";
string DatabaseContract::PHONE_NUMBER ="phone_number";
string DatabaseContract::ADDRESS = "address";
string DatabaseContract::PASSWORD = "password";

string DatabaseContract::DEPARTMENT_TABLE_NAME = "department_table";
string DatabaseContract::DEPART_ID = "dept_id";
string DatabaseContract::DEPARTMENT_NAME = "department_name";

string DatabaseContract::ERROR_MESSAGE ="0";
string DatabaseContract::DATA = "Callback function called";

const string DatabaseContract::STAFF_ITEM_CALLBACK = "staff_item_callback";
const string DatabaseContract::DEPTMENT_ITEM_CALLBACK = "department_item_callback";
const string DatabaseContract::LOGIN_CALLBACK = "login_callback";
