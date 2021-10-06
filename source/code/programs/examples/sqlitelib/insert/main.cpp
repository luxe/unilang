#include <sqlitelib.h>
#include "code/utilities/filesystem/paths/lib.hpp"

int main(){
    using namespace sqlitelib;
    
    //create database
    auto db = Sqlite(Full_Path_For_Tmp_File("test.db").c_str());
    
    //create table
    db.execute(R"(
  CREATE TABLE IF NOT EXISTS people (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    age INTEGER,
    data BLOB
    ))");
    

//insert records
auto stmt = db.prepare("INSERT INTO people (name, age, data) VALUES (?, ?, ?)");
stmt.execute("john", 10, std::vector<char>({ 'A', 'B', 'C', 'D' }));
stmt.execute("paul", 20, std::vector<char>({ 'E', 'B', 'G', 'H' }));
stmt.execute("mark", 15, std::vector<char>({ 'I', 'J', 'K', 'L' }));
stmt.execute("luke", 25, std::vector<char>({ 'M', 'N', 'O', 'P' }));
    

//select record
auto val = db.execute_value<int>("SELECT age FROM people WHERE name='john'");
std::cout << val << std::endl; // 10

}