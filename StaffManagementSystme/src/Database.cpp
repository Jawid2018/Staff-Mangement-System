#include "Database.h"
using namespace std;

Database::Database(){}

void  Database::createDatabase(){

}

void Database::opentDatabase(){
    int rec = sqlite3_open(DatabaseContract::DATABAE_NAME,&db);
    if( rec ) {
        cout<<"Failed to open datbase"<<endl;
    }else{
     //   cout<<"Opened database successfully"<<endl;
    }

   // sqlite3_busy_timeout(db, 1000);
}

void Database::closeDatabase(){
      //  cout<<"database close method called";
        if(db != NULL){
            sqlite3_close(db);
        // cout<<"Database closed"<<endl;
       }
}

int Database::createTables(){
      Database::opentDatabase();
      char *errorMessage;

      string sql = "CREATE TABLE "+DatabaseContract::STAFF_TABLE_NAME + " ( "
      +DatabaseContract::ID +" INTEGER PRIMARY KEY AUTOINCREMENT, "
      +DatabaseContract::NAME +" TEXT NOT NULL, "
      +DatabaseContract::DESIGNATION +" TEXT NOT NULL, "
      +DatabaseContract::DOB +" TEXT NOT NULL, "
      +DatabaseContract::SALARY +" INT NOT NULL, "
      +DatabaseContract::CODE +" INT NOT NULL, "
      +DatabaseContract::YEAR_OF_EXPERIENCE+" INT NOT NULL, "
      +DatabaseContract::PHONE_NUMBER+" TEXT NOT NULL, "
      +DatabaseContract::ADDRESS+" TEXT NOT NULL, "
      +DatabaseContract::PASSWORD+" TEXT, "
      +DatabaseContract::DEPARTMENT_ID+" INT NOT NULL);" ;

      cout<<"table creation query ---> "<<sql<<endl;
      int isCreated = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

       if(isCreated != SQLITE_OK){
            cout<<"Failed to create table"<<endl;
            cout<<"Error --> "<<errorMessage<<endl;
            sqlite3_free(errorMessage);
       }else{
            cout<<"Tables created sucssfully"<<endl;
       }

      Database::closeDatabase();
      return isCreated;
}

int Database::createDepartmentTable(){
    Database::opentDatabase();
    char *errorMessage;

    string sql = "CREATE TABLE "+DatabaseContract::DEPARTMENT_TABLE_NAME+" ( "
    +DatabaseContract::DEPART_ID+" INTEGER PRIMARY KEY AUTOINCREMENT, "
    +DatabaseContract::DEPARTMENT_NAME+" TEXT NOT NULL); ";

    cout<<"table creation query ---> "<<sql<<endl;
    int isCreated = sqlite3_exec(db, sql.c_str(), NULL, 0, &errorMessage);

    if(isCreated != SQLITE_OK){
        cout<<"Failed to create table"<<endl;
        cout<<"Error --> "<<errorMessage<<endl;
        sqlite3_free(errorMessage);
    }else{
            cout<<"Tables created sucssfully"<<endl;
    }

    Database::closeDatabase();
    return isCreated;
}

int Database::insertData(string sql){
    Database::opentDatabase();
    char *errorMessage;

  //  cout<<"Insert query---> "<<sql<<endl;
    int isInsered = sqlite3_exec(db, sql.c_str(), NULL, 0,&errorMessage);

    if( isInsered != SQLITE_OK ){
        cout<<"Failed to insert."<<endl;
        cout<<"Error --> "<<errorMessage<<endl;
        sqlite3_free(errorMessage);
     } else {
        cout<<endl;
      //  cout<<"\tFeedback ->  insert operation succesfful"<<endl;
     }

    Database::closeDatabase();
    return isInsered;
 }

int Database::deleteData(string query){
    Database::opentDatabase();
    char *errorMessage;

    int isDeleted = sqlite3_exec(db, query.c_str(), NULL, 0,&errorMessage);

    if( isDeleted != SQLITE_OK ){
        cout<<"Failed to delete."<<endl;
        cout<<"Error --> "<<errorMessage<<endl;
        sqlite3_free(errorMessage);
     } else {
        cout<<endl;
        cout<<"        Feedback ->  Delete operation succesfful"<<endl;
     }

    Database::closeDatabase();
    return isDeleted;
 }

int Database::updateData(string query){
    Database::opentDatabase();
    char *errorMessage;

    int isUpdated = sqlite3_exec(db, query.c_str(), NULL, 0,&errorMessage);

    if(isUpdated != SQLITE_OK){
        cout<<"Failed to update."<<endl;
        cout<<"Error --> "<<errorMessage<<endl;
        sqlite3_free(errorMessage);
     } else {
        cout<<endl;
        cout<<"        Feedback -->  Update operation succesfful"<<endl;
     }

    Database::closeDatabase();
    return isUpdated;
 }


int Database::callback(void *data, int argc, char **argv, char **azColName){

      if(Database::callbackName == DatabaseContract::STAFF_ITEM_CALLBACK || Database::callbackName == DatabaseContract::LOGIN_CALLBACK){
            StaffView staffView;
            StaffItem staffItem;
            /**
                atoi() function is used to convert string to integer
            */
            staffItem.setId(atoi(argv[0]));
            staffItem.setName(argv[1]);
            staffItem.setDesignation(argv[2]);
            staffItem.setDob(argv[3]);
            staffItem.setSalary(atoi(argv[4]));
            staffItem.setCode(atoi(argv[5]));
            staffItem.setExperience(atoi(argv[6]));
            staffItem.setPhoneNumber(argv[7]);
            staffItem.setAddress(argv[8]);
            staffItem.setPassword(argv[9]);
            staffItem.setDepartmentId(atoi(argv[10]));

            if(Database::callbackName == DatabaseContract::STAFF_ITEM_CALLBACK){
                staffView.printDataToConsole(staffItem);
            }else{
                Database::staffItem = staffItem;
            }
        }else if(Database::callbackName == DatabaseContract::DEPTMENT_ITEM_CALLBACK){
            DepartmentView departmentView;
            DepartmentItem departmentItem;

            departmentItem.setDepartmentId(atoi(argv[0]));
            departmentItem.setDepartmentName(argv[1]);

            departmentView.printDataToConsole(departmentItem);
        }
        return 0;
}

 int Database::selectData(string callbackName,string sql){
    char *errorMessage;
    Database::callbackName = callbackName;

    Database::opentDatabase();
  //  cout<<"Select query ---> "<<sql<<endl;

    int isSelected = sqlite3_exec(db, sql.c_str(),callback, 0, &errorMessage);
    if(isSelected != SQLITE_OK){
        cout<<"Failed to select data."<<endl;
        cout<<"Error --> "<<errorMessage<<endl;
        sqlite3_free(errorMessage);
     } else {
     //   cout<<"Select operation successfull"<<endl;
     }
    Database::closeDatabase();
    if(callbackName == DatabaseContract::LOGIN_CALLBACK){
        LoginView::onUserDataFetchSuccess(Database::staffItem);
    }
    return isSelected;
 }

// when database object destroyed colose the opened dabase
 Database::~Database(){
    if(db != NULL){
    //    sqlite3_close(db);
      //  cout<<"Database closed"<<endl;
    }
 }

int Database::dropTable(string tableName){
    char *errorMessage;
    string query = "DROP TABLE "+tableName;

    Database::opentDatabase();
    int isDropped = sqlite3_exec(db, query.c_str(),NULL, 0, &errorMessage);
    if(isDropped != SQLITE_OK){
        cout<<"Failed drop."<<endl;
        cout<<"Error --> "<<errorMessage<<endl;
        sqlite3_free(errorMessage);
     } else {
        cout<<tableName<<" dropped succesffuly!"<<endl;
     }

     Database::closeDatabase();
     return isDropped;
 }

string Database::callbackName = "";
StaffItem Database::staffItem = StaffItem();





