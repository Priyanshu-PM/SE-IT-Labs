#include<bits/stdc++.h>
#include<string.h>
#include<fstream>

using namespace std;

class Student {    
    
    public:
    string roll_no, name, division, address;

    Student takeInput() {
        Student s;
        cout << "Enter the roll number of the student : ";
        cin >> s.roll_no;
        cout << "Enter the name of the student : ";
        cin >> s.name;
        cout << "Enter the division of the student : ";
        cin >> s.division;
        cout << "Enter the address of the student : ";
        cin >> s.address;

        return s;
    }

};

class Database {
    private:
    fstream db;
    ifstream idb;
    string filename;

    public:

    Database(string f) {
        filename = f;
        createDatabase();
    }

    void createDatabase() {

        db.open(filename, fstream::app);

        if(!db) {
            cout << "Error in creating database !!\n";
        }
        else
            cout << "Database created successfully !!\n";
        db.close();
    }

    void addStudent(Student st) {

        db.open(filename, fstream::app);
        db <<st.roll_no <<","<<st.name<<","<<st.division<<","<<st.address<<"\n";
        cout << "Data added successfully !!\n";
        db.close();
    }

    void displayDatabase() {
        idb.open(filename);
        string line;
        bool flag = false;
        int i = 0;
        while(getline(idb, line)) {
            i++;
            flag = true;
            cout << "Student "<< i << " details : \n";
            cout << line << "\n";
        }

        if(!flag) {
            cout << "Database is empty !!";
        }
        cout << "\n";
    }

    void searchStudent() {

        // idb.open(filename);
        ifstream f(filename, ifstream::in);
        string key;
        cout << "Enter the roll no of the student : ";
        cin >> key;
        string line;
        bool flag = false;
        while(getline(f, line)) {
            if(line.find(key) != string::npos) {
                flag = true;
                cout << "Found record with roll number :\n";
                cout << line << "\n";
                break;
            }

        }
        if(!flag) {
            cout << "No record found with the given roll number !!\n";
        }
        f.close();
    }

    void deleteStudent() {
        idb.open(filename);
        string rollno;
        cout << "Enter the roll number to delete :";
        cin >> rollno;
        fstream newFile("new.txt", fstream::out);
        string line;
        while(getline(idb, line)) {

            if(line.find(rollno) == string::npos) {
                newFile << line << "\n";
            }
        }
        newFile.close();

        db.open(filename, fstream::out);
        newFile.open("new.txt", fstream::in);

        while(getline(newFile, line)) {
            db << line << "\n";
        }

        db.close();
        newFile.close();
        idb.close();
        
    }
};

int main() {

    Database db("priyanshu.txt");
    Student s1 = s1.takeInput();
    db.addStudent(s1);

    s1 = s1.takeInput();
    db.addStudent(s1);

    db.displayDatabase();

    db.searchStudent();
    db.deleteStudent();

    return 0;
}