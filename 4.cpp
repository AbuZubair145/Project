#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//  Managing Teacher  (Administrator)
void AddTeacher(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[]);
void DeleteTeacher(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[]);
void UpdateTeacher(string tName[], int tClass[], int tAge[]);
void DisplayTeacher(string tName[], int tClass[], int tAge[]);
void SearchTeacher(string tName[], int tClass[], int tAge[]);
void DisplayTeacherId(string tName[], string tUserName[], string tPassword[]);
//Managing Student  (Administrator)
void AddStudent(string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[]);
void DeleteStudent(string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[]);
void UpdateStudent(string sName[], int sClass[], int sRollNo[]);
void DisplayStudent(string sName[], int sClass[], int sRollNo[]);
void SearchStudent(string sName[], int sClass[], int sRollNo[]);
void DisplayStudentId(string sName[], string sUserName[],string sPassword[]);
// Teacher Login
void AddMarksOfStudent(string sName[], int marks[][5], int sclass[], int classcheck);
void AddStudentsGrade(string sName[], char grade[], int sClass[], int classCheck);
void ViewStudentsWithGrade(string sName[], char grade[], int sRollNo[],int sClass[], int classCheck);
void ViewStudentsWithMarks(string sName[],int marks[][5],int sClass[],int classcheck);
void SearchStudentsWithMarks(string sName[],int marks[][5],int sClass[],int sRollNo[],int classcheck);
//Student Login
void ViewGradeByStudent(string sName[], char grade[], int sRollNo[], int rollNoCheck);
void ViewMarksByStudent(int marks[][5], string sName[], int sRollNo[], int rollNoCheck);
//validations
void SaveData(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[], string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[],int marks[][5],char grades[]);
void loadData(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[], string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[],int marks[][5],char grades[]);
int AgeRestriction(int tAge);
int valid(int input);
int classRestriction(int validClass);
int RollNoRestriction(int sRollNo);
int main()
{

    const int tSize = 5;
    const int studentSize = 10;
    string names, userName, passWord, search;
    char grades[studentSize];
    int marks[studentSize][tSize];
    string tUserName[tSize], teacher[tSize], tPassword[tSize];
    string students[studentSize], sUserName[studentSize], sPassword[studentSize];
    int input, input1, input2, loggedInUserType, teacherClass[tSize], teacherSAge[tSize], studentRollNo[studentSize];
    int classs, studentClass[studentSize], rollNos;

    for (int i = 0; i < tSize; i++)
    {
        teacher[i] = "nv";
        teacherSAge[i] = -1;
        teacherClass[i] = -1;
        tUserName[i] = "nv";
        tPassword[i] = "nv";
    }
    for (int i = 0; i < studentSize; i++)
    {
        students[i] = "nv";
        studentClass[i] = -2;
        studentRollNo[i] = -1;
        grades[i] = ' ';
        sUserName[i] = "nv";
        sPassword[i] = "nv";
    }
    for (int i = 0; i < studentSize; i++)
    {
        for (int j = 0; j < tSize; j++)
        {
            marks[i][j] = 0;
        }
    }
    loadData(teacher , tUserName , teacherClass , teacherSAge , tPassword , students ,sUserName ,studentClass , studentRollNo , sPassword , marks , grades);
    cout << "***************************************************************************************" << endl;
    cout << setw(60) << "School Management System " << endl;
    cout << "***************************************************************************************" << endl;

    do
    {
        cout << endl;
        cout << setw(40) << "1.Administrator Login " << endl;
        cout << setw(34) << "2.Teacher Login " << endl;
        cout << setw(34) << "3.Student Login " << endl;
        cout << setw(25) << "0.Exit " << endl;
        cout << endl;
        cout << "Choose an option : ";
        input = valid(input);
        switch (input)
        {

        case 1:
            cout << "Enter the username : ";
            cin >> userName;
            cout << "Enter the password : ";
            cin >> passWord;
            if (userName == "zubair" && passWord == "145")
            {
                loggedInUserType = 1;
            }
            else
            {
                loggedInUserType = -1;
                cout << "You have entered wrong information." << endl;
                break;
            }
            break;

        case 2:
            cout << "Enter the username : ";
            cin >> userName;
            cout << "Enter the password : ";
            cin >> passWord;
            cout << "Enter class in which you teach : ";
            cin >> classs;
            for (int i = 0; i < tSize; i++)
            {
                if (userName == tUserName[i] && passWord == tPassword[i] && classs == teacherClass[i])
                {
                    loggedInUserType = 2;
                    break;
                }
            }
            if (loggedInUserType != 2)
            {
                cout << "Wrong information." << endl;
                loggedInUserType = -1;
            }
            break;

        case 3:
            cout << "Enter the username : ";
            cin >> userName;
            cout << "Enter the password : ";
            cin >> passWord;
            cout << "Enter your Roll No : ";
            cin >> rollNos;
            for (int i = 0; i < tSize; i++)
            {
                if (userName == sUserName[i] && passWord == sPassword[i] && rollNos == studentRollNo[i])
                {
                    loggedInUserType = 3;
                    break;
                }
            }
            if (loggedInUserType != 3)
            {
                cout << "Wrong information." << endl;
                loggedInUserType = -1;
            }
            break;

        case 0:

            cout << "Thank you for using our system." << endl;
            loggedInUserType = -1;
            break;

        default:

            cout << "You have entered wrong credentials.";
        }

        if (loggedInUserType == 1)
        {
            do
            {

                cout << "***************************************************************************************" << endl;
                cout << setw(55) << "Administrator" << endl;
                cout << "***************************************************************************************" << endl;
                cout << endl;
                cout << setw(30) << "1.Teachers " << endl;
                cout << setw(30) << "2.Students " << endl
                     << endl;
                cout << setw(15) << "To Whom You want to manage : ";
                input2 = valid(input2);

                if (input2 == 1)
                {
                    do
                    {

                        cout << "***************************************************************************************" << endl;
                        cout << setw(60) << "Managing Teacher " << endl;
                        cout << "***************************************************************************************" << endl;
                        cout << setw(30) << "1.Add a teacher "
                             << setw(30) << "2.Delete a teacher " << endl;
                        cout << setw(33) << "3.Update a teacher "
                             << setw(27) << "4.Display teachers " << endl;
                        cout << setw(31) << "5.Search Teacher "
                             << setw(24) << "6.Display UID " << endl;
                        cout << setw(23) << "0.Logout " << endl;
                        cout << endl;
                        cout << "Choose an option : ";
                        input1 = valid(input1);

                        if (input1 == 1)
                        {
                            AddTeacher(teacher, tUserName, teacherClass, teacherSAge, tPassword);
                        }

                        else if (input1 == 2)
                        {
                            DeleteTeacher(teacher, tUserName, teacherClass, teacherSAge, tPassword);
                        }

                        else if (input1 == 3)
                        {
                            UpdateTeacher(teacher, teacherClass, teacherSAge);
                        }

                        else if (input1 == 4)
                        {
                            DisplayTeacher(teacher, teacherClass, teacherSAge);
                        }

                        else if (input1 == 5)
                        {
                            SearchTeacher(teacher, teacherClass, teacherSAge);
                        }
                        else if (input1 == 6)
                        {
                            DisplayTeacherId(teacher, tUserName, tPassword);
                        }
                    } while (input1 != 0);
                }
                else if (input2 == 2)
                {
                    do
                    {
                        cout << "***************************************************************************************" << endl;
                        cout << setw(60) << "Managing Students " << endl;
                        cout << "***************************************************************************************" << endl;
                        cout << setw(30) << "1.Add a student "
                             << setw(30) << "2.Delete a student " << endl;
                        cout << setw(33) << "3.Update a student "
                             << setw(27) << "4.Display students " << endl;
                        cout << setw(31) << "5.Search Student ";
                        cout << setw(24) << "6.Display UID " << endl;
                        cout << setw(23) << "0.Logout " << endl;
                        cout << endl;
                        cout << "Choose an option : ";
                        input1 = valid(input1);

                        if (input1 == 1)
                        {
                            AddStudent(students, sUserName, studentClass, studentRollNo, sPassword);
                        }

                        else if (input1 == 2)
                        {
                            DeleteStudent(students, sUserName, studentClass, studentRollNo, sPassword);
                        }

                        else if (input1 == 3)
                        {
                            UpdateStudent(students, studentClass, studentRollNo);
                        }
                        else if (input1 == 4)
                        {
                            DisplayStudent(students, studentClass, studentRollNo);
                        }
                        else if (input1 == 5)
                        {
                            SearchStudent(students, studentClass, studentRollNo);
                        }
                        else if (input1 == 6)
                        {
                            DisplayStudentId(students, sUserName, sPassword);
                        }
                    } while (input1 != 0);
                }
                else
                {
                    cout << endl;
                    cout << setw(40) << "Wrong input." << endl;
                    cout << endl;
                    cout << "Choose your option again : " << endl;
                }

            } while (input1 != 0);
        }

        else if (loggedInUserType == 2)
        {
            do
            {
                cout << "***************************************************************************************" << endl;
                cout << setw(60) << " Teacher Login " << endl;
                cout << "***************************************************************************************" << endl;
                cout << setw(45) << "1.Enter Marks of Students "
                     << setw(30) << "2.Enter Grade of students " << endl;
                cout << setw(46) << "3.View students with grade ";
                cout << setw(30) << "4.View students with marks " << endl;
                cout << setw(36) << "5.Search Student ";
                cout << setw(22) << "0.Logout " << endl;
                cout << endl;
                cout << "Choose your option : ";
                input1 = valid(input1);

                if (input1 == 1)
                {
                    AddMarksOfStudent(students, marks, studentClass, classs);
                }

                else if (input1 == 3)
                {
                    ViewStudentsWithGrade(students, grades, studentRollNo, studentClass, classs);
                }

                else if (input1 == 2)
                {
                    AddStudentsGrade(students, grades, studentClass, classs);
                }
                else if (input1 == 4)
                {
                    ViewStudentsWithMarks(students,marks,studentClass,classs);
                }
                else if(input1 == 5)
                {
                    SearchStudentsWithMarks(students,marks,studentClass,studentRollNo,classs);
                }

            } while (input1 != 0);
        }

        else if (loggedInUserType == 3)
        {
            do
            {
                cout << "***************************************************************************************" << endl;
                cout << setw(60) << "Student Login " << endl;
                cout << "***************************************************************************************" << endl;
                cout << endl;
                cout << setw(32) << "1.View Marks " << endl;
                cout << setw(32) << "2.View grade " << endl;
                cout << setw(28) << "0.Logout " << endl;
                cout << endl;
                cout << "Choose an option : ";
                input1 = valid(input1);
                {
                    if (input1 == 1)
                    {
                        ViewMarksByStudent(marks,students,studentRollNo,rollNos);                        
                    }
                    else if (input1 == 2)
                    {
                        ViewGradeByStudent(students, grades, studentRollNo,rollNos);
                    }
                }
            } while (input1 != 0);
        }

    } while (input != 0);
    SaveData(teacher, tUserName, teacherClass, teacherSAge, tPassword, students, sUserName, studentClass, studentRollNo, sPassword,marks,grades);
}

int valid(int input)
{
    while (!(cin >> input))
    {
        cout << endl;
        cout << "************************************************************************************" << endl;
        cout << "                       Invalid Option                                               " << endl;
        cout << "************************************************************************************" << endl;
        cout << endl;
        cout << "Choose your option again : ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return input;
}
//  ADD teacher
void AddTeacher(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[])
{
    string add, username;
    int age, classss;
    bool teacherFlag = false;
    for (int i = 0; i < 5; i++)
    {
        if (tName[i] == "nv")
        {
            cout << "Enter teacher's name : ";
            cin.ignore(256, '\n');
            getline(cin, add);
            tName[i] = add;
            cout << "Enter teacher's Age(Between 20 and 60) : ";
            cin >> age;
            age = AgeRestriction(age);
            tAge[i] = age;
            cout << "Assign Class to teacher(Between 1 and 10) : ";
            cin >> classss;
            classss = classRestriction(classss);
            tClass[i] = classss;
            cout << "Generate username for teacher : ";
            cin.ignore(256, '\n');
            getline(cin, tUserName[i]);
            cout << "Generate password for teacher : ";
            cin >> tPassword[i];
            cout << "Teacher Add Succefully." << endl;
            teacherFlag = true;
            break;
        }
    }
    if(teacherFlag == false)
    {
        cout <<"No space for new teacher."<<endl;
    }

}
// Delete Teacher
void DeleteTeacher(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[])
{
    string dele;
    cout << "Enter teacher's name to delete : ";
    cin.ignore(256, '\n');
    getline(cin, dele);
    bool teacherFlag = false;
    for (int i = 0; i < 5; i++)
    {
        if (tName[i] != "nv" && dele == tName[i])
        {

            tName[i] = "nv";
            tClass[i] = -1;
            tAge[i] = -1;
            tUserName[i] = "nv";
            tPassword[i] = "nv";
            cout << "Teacher Delete Succefully." << endl;
            teacherFlag = true;
            break;
        }
    }
    if(teacherFlag == false)
    {
        cout <<"Teacher not found."<<endl;
    }
}

void UpdateTeacher(string tName[], int tClass[], int tAge[])
{
    bool teacherFlag = false;
    string update;
    int choose, age, classss;
    cout << "Enter teacher's name to update teacher's details : ";
    cin.ignore(256, '\n');
    getline(cin, update);
    for (int i = 0; i < 5; i++)
    {
        if (tName[i] != "nv" && update == tName[i])
        {
            cout << "What do you want to change : " << endl;
            cout << setw(45) << "1.Teacher's name " << endl;
            cout << setw(46) << "2.Teacher's class " << endl;
            cout << setw(44) << "3.Teacher's age " << endl;
            cout << endl;
            cout << "Enter your choice : ";
            choose = valid(choose);
            {
                if (choose == 1)
                {
                    cout << "Update name of " << tName[i] << " : ";
                    cin.ignore(256, '\n');
                    getline(cin, tName[i]);
                    cout << "Teacher's name has been succefully updated." << endl;
                    teacherFlag =true;
                    break;
                }
                else if (choose == 2)
                {
                    cout << "Update class of " << tName[i] << " : ";
                    cin >> classss;
                    classss = classRestriction(classss);
                    tClass[i] = classss;
                    cout << "Teacher's class has been succefully updated." << endl;
                    teacherFlag =true;
                    break;
                }
                else if (choose == 3)
                {
                    cout << "Update age of " << tName[i] << " : ";
                    cin >> age;
                    age = AgeRestriction(age);
                    tAge[i] = age;
                    cout << "Teacher's age has been succefully updated." << endl;
                    teacherFlag =true;
                    break;
                }
            }
        }
    }
    if(teacherFlag == false)
    {
        cout <<"Teacher not found"<<endl;
    }
}

void DisplayTeacher(string tName[],int tClass[], int tAge[])
{
    bool teacherFlag = false;
    cout << setw(30) << " Teacher " << setw(35);
    cout << " Class " << setw(25) << " Age " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (tName[i] != "nv" && tClass[i] != -1 && tAge[i] != -1)
        {
            cout << setw(28) << tName[i] << setw(32);
            cout << tClass[i] << setw(24) << tAge[i] << endl;
            teacherFlag = true;
        }
    }
    if(teacherFlag == false)
    {
        cout <<"No teachers were added."<<endl;
    }
}

void SearchTeacher(string tName[],int tClass[], int tAge[])
{
    bool teacherFlag = false;
    int choose, searching;
    string search;
    cout << "You Want to search Teacher by " << endl;
    cout << endl;
    cout << setw(45) << "1.Teacher's name " << endl;
    cout << setw(46) << "2.Teacher's class " << endl;
    cout << setw(44) << "3.Teacher's age " << endl;
    cout << endl;
    cout << "Enter an option : ";
    choose = valid(choose);
    {
        if (choose == 1)
        {
            cout << "Enter Teacher's Name : ";
            cin.ignore(256, '\n');
            getline(cin, search);
            cout << endl;
            cout << setw(30) << " Teacher " << setw(35);
            cout << " Class " << setw(25) << " Age " << endl;
            cout << "*********************************************************************************" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (tName[i] != "nv" && tName[i] == search)
                {
                    cout << setw(28) << tName[i] << setw(32);
                    cout << tClass[i] << setw(24) << tAge[i] << endl;
                    teacherFlag = true;
                    break;
                }
            }
        }
        else if (choose == 2)
        {
            cout << "Enter Teacher's Class : ";
            cin >> searching;
            searching = classRestriction(searching);
            cout << endl;
            cout << setw(30) << " Teacher " << setw(35);
            cout << " Class " << setw(25) << " Age " << endl;
            cout << "*********************************************************************************" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (tName[i] != "nv" && tClass[i] == searching)
                {
                    cout << setw(28) << tName[i] << setw(32);
                    cout << tClass[i] << setw(24) << tAge[i] << endl;
                    teacherFlag =true;
                    break;
                }
            }
        }
        else if (choose == 3)
        {
            cout << "Enter Teacher's Age : ";
            cin >> searching;
            searching = AgeRestriction(searching);
            cout << endl;
            cout << setw(30) << " Teacher " << setw(35);
            cout << " Class " << setw(25) << " Age " << endl;
            cout << "*********************************************************************************" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (tName[i] != "nv" && tAge[i] == searching)
                {
                    cout << setw(28) << tName[i] << setw(32);
                    cout << tClass[i] << setw(24) << tAge[i] << endl;
                    teacherFlag =true;
                    break;
                }
            }
        }
    }
    if(teacherFlag == false)
    {
        cout <<"Teacher not found."<<endl;
    }
}

void DisplayTeacherId(string tName[], string tUserName[], string tPassword[])
{
    bool teacherFlag = false;
    cout << setw(30) << " Teacher " << setw(35);
    cout << " UserName " << setw(25) << " Password " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (tName[i] != "nv" && tUserName[i] != "nv" && tPassword[i] != "nv")
        {
            cout << setw(28) << tName[i] << setw(32);
            cout << tUserName[i] << setw(24) << tPassword[i] << endl;
            teacherFlag =true;
        }
    }
    if(teacherFlag == false)
    {
        cout <<"No Teachers were added."<<endl;
    }
}
void AddStudent(string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[])
{
    bool studentFlag = false;
    string add;
    int classss, rollNo;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] == "nv")
        {
            cout << "Enter student's name : ";
            cin.ignore(256, '\n');
            getline(cin, add);
            sName[i] = add;
            cout << "Enter student's Class : ";
            cin >> classss;
            classss = classRestriction(classss);
            sClass[i] = classss;
            cout << "Enter student's Roll No : ";
            cin >> rollNo;
            rollNo = RollNoRestriction(rollNo);
            sRollNo[i] = rollNo;
            cout << "Generate student username : ";
            cin.ignore(256, '\n');
            getline(cin, sUserName[i]);
            cout << "Generate student password : ";
            cin >> sPassword[i];
            cout << "Student Add Succefully." << endl;
            studentFlag = true;
            break;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No more space available."<<endl;
    }
}
void DeleteStudent(string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[])
{
    bool studentFlag = false;
    string del;
    cout << "Enter student's name to delete : ";
    cin.ignore(256, '\n');
    getline(cin, del);
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && del == sName[i])
        {

            sName[i] = "nv";
            sRollNo[i] = -1;
            sClass[i] = -2;
            sUserName[i] = "nv";
            sPassword[i] = "nv";
            cout << "Student Delete Succefully." << endl;
            studentFlag = true;
            break;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No student found."<<endl;
    }
}
// update student
void UpdateStudent(string sName[],int sClass[], int sRollNo[])
{
    bool studentFlag = false;
    string update;
    int choose, classss, rollNo;
    cout << "Enter student's name to update student's details : ";
    cin.ignore(256, '\n');
    getline(cin, update);
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && update == sName[i])
        {
            cout << "What do you want to change : " << endl;
            cout << setw(45) << "1.Student's name " << endl;
            cout << setw(46) << "2.Student's class " << endl;
            cout << setw(48) << "3.Student's roll no " << endl;
            cout << endl;
            cout << "Enter your choice : ";
            choose = valid(choose);
            {
                if (choose == 1)
                {
                    cout << "Update name of " << sName[i] << " : ";
                    cin.ignore(256, '\n');
                    getline(cin, sName[i]);
                    cout << "Student's name has been succefully updated." << endl;
                    studentFlag = true;
                    break;
                }
                else if (choose == 2)
                {
                    cout << "Update class of " << sName[i] << " : ";
                    cin >> classss;
                    classss = classRestriction(classss);
                    sClass[i] = classss;
                    cout << "Student's class has been succefully updated." << endl;
                    studentFlag = true;
                    break;
                }
                else if (choose == 3)
                {
                    cout << "Update roll no of " << sName[i] << " : ";
                    cin >> rollNo;
                    rollNo = RollNoRestriction(rollNo);
                    sRollNo[i] = rollNo;
                    cout << "Student's roll no has been succefully updated." << endl;
                    studentFlag = true;
                    break;
                }
                else
                {
                    cout << "Invalid input." << endl;
                }
            }
        }
    }
    if(studentFlag == false)
    {
        cout <<"No student found."<<endl;
    }
}
void DisplayStudent(string sName[],int sClass[], int sRollNo[]) // view students(administrator)
{
    bool studentFlag = false;
    cout << setw(30) << " Student " << setw(35);
    cout << " Class " << setw(25) << " Roll No " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && sClass[i] != -2 && sRollNo[i] != -1)
        {
            cout << setw(28) << sName[i] << setw(32);
            cout << sClass[i] << setw(24) << sRollNo[i] << endl; 
            studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"no students were added to display."<<endl;
    }
}
void SearchStudent(string sName[], int sClass[], int sRollNo[]) // search student (administrator)
{
    bool studentFlag = false;
    int choose, searching;
    string search;
    cout << "You Want to search Student by " << endl;
    cout << endl;
    cout << setw(45) << "1.Student's name " << endl;
    cout << setw(46) << "2.Student's class " << endl;
    cout << setw(48) << "3.Student's Roll No " << endl;
    cout << endl;
    cout << "Enter an option : ";
    choose = valid(choose);
    {
        if (choose == 1)
        {
            cout << "Enter Student's Name : ";
            cin.ignore(256, '\n');
            getline(cin, search);
            cout << endl;
            cout << setw(30) << " Student " << setw(35);
            cout << " Class " << setw(25) << " Roll No " << endl;
            cout << "*********************************************************************************" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sName[i] != "nv" && sName[i] == search )
                {
                    cout << setw(28) << sName[i] << setw(32);
                    cout << sClass[i] << setw(24) << sRollNo[i] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
        else if (choose == 2)
        {
            cout << "Enter Student's Class : ";
            cin >> searching;
            searching = classRestriction(searching);
            cout << endl;
            cout << setw(30) << " Student " << setw(35);
            cout << " Class " << setw(25) << " Roll No " << endl;
            cout << "*********************************************************************************" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sName[i] != "nv" && sClass[i] == searching)
                {
                    cout << setw(28) << sName[i] << setw(32);
                    cout << sClass[i] << setw(24) << sRollNo[i] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
        else if (choose == 3)
        {
            cout << "Enter Student's Roll No : ";
            cin >> searching;
            searching = RollNoRestriction(searching);
            cout << endl;
            cout << setw(30) << " Student " << setw(35);
            cout << " Class " << setw(25) << " Roll No " << endl;
            cout << "*********************************************************************************" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sName[i] != "nv" && sRollNo[i] == searching)
                {
                    cout << setw(28) << sName[i] << setw(32);
                    cout << sClass[i] << setw(24) << sRollNo[i] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students found."<<endl;
    }
}
void DisplayStudentId(string sName[], string sUserName[],string sPassword[]) // view username and password of studnets(administrator)
{
    bool studentFlag = false;
    cout << setw(30) << " Student " << setw(35);
    cout << " UserName " << setw(25) << " Password " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && sUserName[i] != "nv" && sPassword[i] != "nv")
        {
            cout << setw(28) << sName[i] << setw(32);
            cout << sUserName[i] << setw(24) << sPassword[i] << endl;
            studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students were added to displayed."<<endl;
    }
}
void ViewStudentsWithGrade(string sName[], char grade[], int sRollNo[],int sClass[], int classCheck) // view student grade (teacher)
{
    bool studentFlag = false;
    cout << endl;
    cout << setw(30) << " Student " << setw(35);
    cout << " Grade " << setw(25) << " Roll No " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && classCheck == sClass[i])
        {
            cout << setw(28) << sName[i] << setw(32);
            cout << grade[i] << setw(24) << sRollNo[i] << endl;
            studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students to displayed."<<endl;
    }
}
void AddStudentsGrade(string sName[], char grade[], int sClass[], int classCheck) // add student grade (teacher)
{
    bool studentFlag = false;
    string search;
    cout << "Enter name of student to enter his grade : ";
    cin.ignore(256, '\n');
    getline(cin, search);
    for (int i = 0; i < 10; i++)
    {

        if (sName[i] == search && classCheck == sClass[i])
        {
            cout << "Enter Grade of " << sName[i] << " : ";
            cin >> grade[i];
            cout <<"Student's grade has been given."<<endl;
            studentFlag = true;
            break;
        }
    }
    if(studentFlag == false)
    {
        cout <<"NO student found."<<endl;
    }
}
void ViewGradeByStudent(string sName[], char grade[], int sRollNo[], int rollNoCheck) // view grade (student)
{
    bool studentFlag = false;
    cout << endl;
    cout << setw(30) << " Student " << setw(35);
    cout << " Grade " << setw(25) << " Roll No " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && sRollNo[i] == rollNoCheck)
        {

            cout << setw(28) << sName[i] << setw(32);
            cout << grade[i] << setw(24) << sRollNo[i] << endl;
            studentFlag = true;
            break;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No student found."<<endl;
    }
}
// save data in files
void SaveData(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[], string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[],int marks[][5],char grades[]) // save data
{
    enum courses
    {
        English,
        Urdu,
        Math,
        Science,
        Islamiyat
    };
    ofstream teacherout;
    ofstream studentout;
    ofstream marksout ;
    ofstream gradesout ;
    teacherout.open("teacher.txt");  //save data of teachers
    for (int i = 0; i < 5; i++)
    {
        if (tName[i] != "nv" && tUserName[i] != "nv" && tClass[i] != -1 && tAge[i] != -1 && tPassword[i] != "nv")
        {
            teacherout << tName[i] << "," << tUserName[i]<< "," << tPassword[i] << "," << tClass[i] << "," << tAge[i]  << endl;
        }
    }
    teacherout.close();    //save data of students
    studentout.open("student.txt");
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && sUserName[i] != "nv" && sClass[i] != -2 && sRollNo[i] != -1 && sPassword[i] != "nv")
        {
            studentout << sName[i] <<"," << sUserName[i] <<"," << sPassword[i] << "," << sClass[i] << "," << sRollNo[i]  << endl;
        }
    }
    studentout.close();
    marksout.open("marks.txt");   //save marks of students
    for(int i=0 ; i < 10 ; i++)
    {
        if(sName[i] != "nv" && marks[i][0] != 0 && marks[i][1] && marks[i][2] != 0 && marks[i][3] != 0 && marks[i][4] != 0)
        {
            marksout << grades[i] << "," << marks[i][English] << "," <<marks[i][Urdu]<<","
                     <<marks[i][Math]<<","<<marks[i][Science]<<","<<marks[i][Islamiyat] <<endl;
                     
        }
    }
    marksout.close();
}
//load data from files
void loadData(string tName[], string tUserName[], int tClass[], int tAge[], string tPassword[], string sName[], string sUserName[], int sClass[], int sRollNo[], string sPassword[],int marks[][5],char grades[]) // load data
{
    enum courses
    {
        English,
        Urdu,
        Math,
        Science,
        Islamiyat
    };
    ifstream studentIn("student.txt"); // load data of students
    for(int i=0 ; i<10 ; i++)
    {
        getline(studentIn , sName[i] , ',');
        getline(studentIn , sUserName[i] , ',');
        getline(studentIn , sPassword[i] , ',');
        studentIn >> sClass[i];
        studentIn.ignore();
        studentIn >> sRollNo[i];
        studentIn.ignore();
    }
    studentIn.close();
    ifstream teacherIn("teacher.txt");  // load data of teachers
    for (int i=0;i<5;i++)
    {
        getline(teacherIn , tName[i] , ',');
        getline(teacherIn , tUserName[i], ',');
        getline(teacherIn , tPassword[i] , ',');
        teacherIn >> tClass[i];
        teacherIn.ignore();
        teacherIn >> tAge[i];
        teacherIn.ignore();
    }
    teacherIn.close();
    ifstream marksIn("marks.txt");  //load data of student marks 
    for(int i=0;i < 10;i++)
    {
        marksIn >> grades[i];
        marksIn.ignore();
        marksIn >> marks[i][English];
        marksIn.ignore();
        marksIn >> marks[i][Urdu];
        marksIn.ignore();
        marksIn >> marks[i][Math];
        marksIn.ignore();
        marksIn >>marks[i][Science];
        marksIn.ignore();
        marksIn >>marks[i][Islamiyat];
        marksIn.ignore();
    }
    marksIn.close();
}
int AgeRestriction(int tAge) // age restriction
{
    while (true)
    {
        if (tAge >= 20 && tAge <= 60)
        {
            return tAge;
        }
        else
        {
            cout << "Age should be greater than 20 and less than 60." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter Age again : ";
            cin >> tAge;
        }
    }
}
int classRestriction(int validCLass) // class Restriction
{
    while (true)
    {
        if (validCLass >= 1 && validCLass <= 10)
        {
            return validCLass;
        }
        else
        {
            cout << "Class should be between 1 and 10." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter class again : ";
            cin >> validCLass;
        }
    }
}
int RollNoRestriction(int sRollNo)  // roll no restriction
{
    while (true)
    {
        if (sRollNo >= 1 && sRollNo <= 35)
        {
            return sRollNo;
        }
        else
        {
            cout << "Class should be between 1 and 35." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter roll no again : ";
            cin >> sRollNo;
        }
    }
}
void ViewMarksByStudent(int marks[][5], string sName[], int sRollNo[], int rollNoCheck) // view marks by student(student)
{
    bool studentFlag = false;
    enum courses
    {
        English,
        Urdu,
        Math,
        Science,
        Islamiyat
    };
    cout << endl;
    cout << "Students" << setw(20) << "English" << setw(20) << "Math"
         << setw(20) << "Urdu" << setw(20) << "Science"
         << setw(20) << "Islamiyat" << endl;
    cout << "******************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && sRollNo[i] == rollNoCheck && marks[i][0] != 0)
        {
            cout << sName[i] << setw(20) << marks[i][English] << setw(20) << marks[i][Urdu]
                 << setw(20) << marks[i][Math] << setw(20) << marks[i][Science]
                 << setw(20) << marks[i][Islamiyat] << endl;
                 studentFlag =true;
            break;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No student found."<<endl;
    }
}
void AddMarksOfStudent(string sName[], int marks[][5], int sclass[], int classcheck)  //add marks of student (teacher)
{
    bool studentFlag = false;
    string names;
    enum courses
    {
        English,
        Urdu,
        Math,
        Science,
        Islamiyat
    };
    cout << "Enter the name of student to add marks : ";
    cin.ignore();
    getline(cin, names);
    for (int i = 0; i < 10; i++)
    {

        if (sName[i] == names && classcheck == sclass[i])
        {
            cout << "Enter marks of English : ";
            cin >> marks[i][English];
            cout << "Enter marks of Urdu : ";
            cin >> marks[i][Urdu];
            cout << "Enter marks of Math : ";
            cin >> marks[i][Math];
            cout << "Enter marks of Science : ";
            cin >> marks[i][Science];
            cout << "Enter marks of Islamiyat : ";
            cin >> marks[i][Islamiyat];
            cout <<"Student's marks have been added."<<endl;
            studentFlag = true;
            break;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No student found."<<endl;
    }
}
void ViewStudentsWithMarks(string sName[],int marks[][5],int sClass[],int classcheck)   //view student with marks(teacher)
{
    bool studentFlag = false;
    enum courses
    {
        English,
        Urdu,
        Math,
        Science,
        Islamiyat
    };
    cout << endl;
    cout << "Students" << setw(20) << "English" << setw(20) << "Math"
         << setw(20) << "Urdu" << setw(20) << "Science"
         << setw(20) << "Islamiyat" << endl;
    cout << "************************************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (sName[i] != "nv" && classcheck == sClass[i] )
        {
            cout << sName[i] << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
                 << setw(20) << marks[i][Urdu] << setw(20) << marks[i][Science]
                 << setw(20) << marks[i][Islamiyat] << endl;
                 studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students were added to displayed."<<endl;
    }
}
void SearchStudentsWithMarks(string sName[],int marks[][5],int sClass[],int sRollNo[],int classcheck)
{
    enum courses
    {
        English,
        Urdu,
        Math,
        Science,
        Islamiyat
    };
    bool studentFlag = false;
    int choose, searching;
    string search;
    cout << "You Want to search Student by " << endl;
    cout << endl;
    cout << setw(45) << "1.Student's name " << endl;
    cout << setw(46) << "2.Student's class " << endl;
    cout << setw(48) << "3.Student's Roll No " << endl;
    cout << endl;
    cout << "Enter an option : ";
    choose = valid(choose);
    {
        if (choose == 1)
        {
            cout << "Enter Student's Name : ";
            cin.ignore(256, '\n');
            getline(cin, search);
            cout << endl;
            cout << "Students" << setw(20) << "English" << setw(20) << "Math"
                << setw(20) << "Urdu" << setw(20) << "Science"
                << setw(20) << "Islamiyat" << endl;
            cout << "************************************************************************************************" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sName[i] == search && classcheck == sClass[i] && marks[i][0] != 0)
                {
                    cout << sName[i] << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
                    << setw(20) << marks[i][Urdu] << setw(20) << marks[i][Science]
                    << setw(20) << marks[i][Islamiyat] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
        else if (choose == 2)
        {
            cout << "Enter Student's Class : ";
            cin >> searching;
            searching = classRestriction(searching);
            cout << endl;
            cout << "Students" << setw(20) << "English" << setw(20) << "Math"
                << setw(20) << "Urdu" << setw(20) << "Science"
                << setw(20) << "Islamiyat" << endl;
            cout << "************************************************************************************************" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sName[i] !="nv" && classcheck == sClass[i] && marks[i][0] != 0 && sClass[i] == searching)
                {
                    cout << sName[i] << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
                    << setw(20) << marks[i][Urdu] << setw(20) << marks[i][Science]
                    << setw(20) << marks[i][Islamiyat] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
        else if (choose == 3)
        {
            cout << "Enter Student's Roll No : ";
            cin >> searching;
            searching = RollNoRestriction(searching);
            cout << endl;
            cout << "Students" << setw(20) << "English" << setw(20) << "Math"
                << setw(20) << "Urdu" << setw(20) << "Science"
                << setw(20) << "Islamiyat" << endl;
            cout << "************************************************************************************************" << endl;
            for (int i = 0; i < 10; i++)
            {
                if (sName[i] != "nv" && classcheck == sClass[i] && marks[i][0] != 0 && sRollNo[i] == searching)
                {
                    cout << sName[i] << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
                    << setw(20) << marks[i][Urdu] << setw(20) << marks[i][Science]
                    << setw(20) << marks[i][Islamiyat] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students found."<<endl;
    }   
}
