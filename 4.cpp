#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
struct teacher
{
    string name;
    string userName;
    string Password;
    int tClass;
    int age;
};
struct student
{
    string name;
    string userName;
    string Password;
    int sClass;
    int rollNo;
    char grade;
};
//  Managing Teacher  (Administrator)
void AddTeacher(teacher Teacher[]);
void DeleteTeacher(teacher Teacher[]);
void UpdateTeacher(teacher Teacher[]);
void DisplayTeacher(teacher Teacher[]);
void SearchTeacher(teacher Teacher[]);
void DisplayTeacherId(teacher Teacher[]);
//Managing Student  (Administrator)
void AddStudent(student Student[]);
void DeleteStudent(student Student[]);
void UpdateStudent(student Student[]);
void DisplayStudent(student Student[]);
void SearchStudent(student Student[]);
void DisplayStudentId(student Student[]);
// Teacher Login
void AddMarksOfStudent(student Student[], int marks[][5], int classcheck);
void AddStudentsGrade(student Student[], int classCheck);
void ViewStudentsWithGrade(student Student[], int classCheck);
void ViewStudentsWithMarks(student Student[],int marks[][5],int classcheck);
void SearchStudentsWithMarks(student Student[],int marks[][5],int classcheck);
//Student Login
void ViewGradeByStudent(student Student[], int rollNoCheck);
void ViewMarksByStudent(student Student[],int marks[][5], int rollNoCheck);
//validations
void SaveData(teacher Teacher[] , student Student[],int marks[][5]);
void loadData(teacher Teacher[], student Student[],int marks[][5]);
int AgeRestriction(int age);
int valid(int input);
int classRestriction(int validClass);
int RollNoRestriction(int rollNo);
int main()
{
    const int studentSize = 10;
    const int tSize = 5;
    teacher Teacher[tSize];
    student Student[studentSize];
    string names, userName, passWord, search;
    int marks[studentSize][tSize];
    int input, input1, input2, loggedInUserType;
    int classs, rollNos;

    for (int i = 0; i < tSize; i++)
    {
        Teacher[i].name = "nv";
        Teacher[i].age = -1;
        Teacher[i].userName = "nv";
        Teacher[i].tClass = -1;
        Teacher[i].Password = "nv";
    }
    for (int i = 0; i < studentSize; i++)
    {
        Student[i].name = "nv";
        Student[i].rollNo = -1;
        Student[i].userName = "nv";
        Student[i].sClass = -2;
        Student[i].Password = "nv";
    }
    for (int i = 0; i < studentSize; i++)
    {
        for (int j = 0; j < tSize; j++)
        {
            marks[i][j] = 0;
        }
    }
    loadData(Teacher,Student,marks);
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
                if (userName == Teacher[i].userName && passWord == Teacher[i].Password && classs == Teacher[i].tClass)
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
                if (userName == Student[i].userName && passWord == Student[i].Password && rollNos == Student[i].rollNo)
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
                            AddTeacher(Teacher);
                        }

                        else if (input1 == 2)
                        {
                            DeleteTeacher(Teacher);
                        }

                        else if (input1 == 3)
                        {
                            UpdateTeacher(Teacher);
                        }

                        else if (input1 == 4)
                        {
                            DisplayTeacher(Teacher);
                        }

                        else if (input1 == 5)
                        {
                            SearchTeacher(Teacher);
                        }
                        else if (input1 == 6)
                        {
                            DisplayTeacherId(Teacher);
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
                            AddStudent(Student);
                        }

                        else if (input1 == 2)
                        {
                            DeleteStudent(Student);
                        }

                        else if (input1 == 3)
                        {
                            UpdateStudent(Student);
                        }
                        else if (input1 == 4)
                        {
                            DisplayStudent(Student);
                        }
                        else if (input1 == 5)
                        {
                            SearchStudent(Student);
                        }
                        else if (input1 == 6)
                        {
                            DisplayStudentId(Student);
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
                    AddMarksOfStudent(Student, marks, classs);
                }

                else if (input1 == 3)
                {
                    ViewStudentsWithGrade(Student, classs);
                }

                else if (input1 == 2)
                {
                    AddStudentsGrade(Student, classs);
                }
                else if (input1 == 4)
                {
                    ViewStudentsWithMarks(Student,marks,classs);
                }
                else if(input1 == 5)
                {
                    SearchStudentsWithMarks(Student,marks,classs);
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
                        ViewMarksByStudent(Student,marks,rollNos);                        
                    }
                    else if (input1 == 2)
                    {
                        ViewGradeByStudent(Student,rollNos);
                    }
                }
            } while (input1 != 0);
        }

    } while (input != 0);
    SaveData(Teacher,Student,marks);
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
void AddTeacher(teacher Teacher[])
{
    string add, username;
    int age, classss;
    bool teacherFlag = false;
    for (int i = 0; i < 5; i++)
    {
        if (Teacher[i].name == "nv")
        {
            cout << "Enter teacher's name : ";
            cin.ignore(256, '\n');
            getline(cin, add);
            Teacher[i].name = add;
            cout << "Enter teacher's Age(Between 20 and 60) : ";
            cin >> age;
            age = AgeRestriction(age);
            Teacher[i].age = age;
            cout << "Assign Class to teacher(Between 1 and 10) : ";
            cin >> classss;
            classss = classRestriction(classss);
            Teacher[i].tClass = classss;
            cout << "Generate username for teacher : ";
            cin.ignore(256, '\n');
            getline(cin, Teacher[i].userName);
            cout << "Generate password for teacher : ";
            cin >> Teacher[i].Password;
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
void DeleteTeacher(teacher Teacher[])
{
    string dele;
    cout << "Enter teacher's name to delete : ";
    cin.ignore(256, '\n');
    getline(cin, dele);
    bool teacherFlag = false;
    for (int i = 0; i < 5; i++)
    {
        if (Teacher[i].name != "nv" && dele == Teacher[i].name)
        {

            Teacher[i].name = "nv";
            Teacher[i].tClass = -1;
            Teacher[i].age = -1;
            Teacher[i].userName = "nv";
            Teacher[i].Password = "nv";
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

void UpdateTeacher(teacher Teacher[])
{
    bool teacherFlag = false;
    string update;
    int choose, age, classss;
    cout << "Enter teacher's name to update teacher's details : ";
    cin.ignore(256, '\n');
    getline(cin, update);
    for (int i = 0; i < 5; i++)
    {
        if (Teacher[i].name != "nv" && update == Teacher[i].name)
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
                    cout << "Update name of " << Teacher[i].name << " : ";
                    cin.ignore(256, '\n');
                    getline(cin, Teacher[i].name);
                    cout << "Teacher's name has been succefully updated." << endl;
                    teacherFlag =true;
                    break;
                }
                else if (choose == 2)
                {
                    cout << "Update class of " << Teacher[i].name << " : ";
                    cin >> classss;
                    classss = classRestriction(classss);
                    Teacher[i].tClass = classss;
                    cout << "Teacher's class has been succefully updated." << endl;
                    teacherFlag =true;
                    break;
                }
                else if (choose == 3)
                {
                    cout << "Update age of " << Teacher[i].name << " : ";
                    cin >> age;
                    age = AgeRestriction(age);
                    Teacher[i].age = age;
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

void DisplayTeacher(teacher Teacher[])
{
    bool teacherFlag = false;
    cout << setw(30) << " Teacher " << setw(35);
    cout << " Class " << setw(25) << " Age " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (Teacher[i].name != "nv" && Teacher[i].tClass != -1 && Teacher[i].age != -1)
        {
            cout << setw(28) << Teacher[i].name << setw(32);
            cout << Teacher[i].tClass << setw(24) << Teacher[i].age << endl;
            teacherFlag = true;
        }
    }
    if(teacherFlag == false)
    {
        cout <<"No teachers were added."<<endl;
    }
}

void SearchTeacher(teacher Teacher[])
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
                if (Teacher[i].name != "nv" && Teacher[i].name == search)
                {
                    cout << setw(28) << Teacher[i].name << setw(32);
                    cout << Teacher[i].tClass << setw(24) << Teacher[i].age << endl;
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
                if (Teacher[i].name != "nv" && Teacher[i].tClass == searching)
                {
                    cout << setw(28) << Teacher[i].name << setw(32);
                    cout << Teacher[i].tClass << setw(24) << Teacher[i].age << endl;
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
                if (Teacher[i].name != "nv" && Teacher[i].age == searching)
                {
                    cout << setw(28) << Teacher[i].name << setw(32);
                    cout << Teacher[i].tClass << setw(24) << Teacher[i].age << endl;
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

void DisplayTeacherId(teacher Teacher[])
{
    bool teacherFlag = false;
    cout << setw(30) << " Teacher " << setw(35);
    cout << " UserName " << setw(25) << " Password " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (Teacher[i].name != "nv" && Teacher[i].userName != "nv" && Teacher[i].Password != "nv")
        {
            cout << setw(28) << Teacher[i].name << setw(32);
            cout << Teacher[i].userName << setw(24) << Teacher[i].Password << endl;
            teacherFlag =true;
        }
    }
    if(teacherFlag == false)
    {
        cout <<"No Teachers were added."<<endl;
    }
}
void AddStudent(student Student[])
{
    bool studentFlag = false;
    string add;
    int classss, rollNo;
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name == "nv")
        {
            cout << "Enter student's name : ";
            cin.ignore(256, '\n');
            getline(cin, add);
            Student[i].name = add;
            cout << "Enter student's Class : ";
            cin >> classss;
            classss = classRestriction(classss);
            Student[i].sClass = classss;
            cout << "Enter student's Roll No : ";
            cin >> rollNo;
            rollNo = RollNoRestriction(rollNo);
            Student[i].rollNo = rollNo;
            cout << "Generate student username : ";
            cin.ignore(256, '\n');
            getline(cin, Student[i].userName);
            cout << "Generate student password : ";
            cin >> Student[i].Password;
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
void DeleteStudent(student Student[])
{
    bool studentFlag = false;
    string del;
    cout << "Enter student's name to delete : ";
    cin.ignore(256, '\n');
    getline(cin, del);
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && del == Student[i].name)
        {

            Student[i].name = "nv";
            Student[i].rollNo = -1;
            Student[i].sClass = -2;
            Student[i].userName = "nv";
            Student[i].Password = "nv";
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
void UpdateStudent(student Student[])
{
    bool studentFlag = false;
    string update;
    int choose, classss, rollNo;
    cout << "Enter student's name to update student's details : ";
    cin.ignore(256, '\n');
    getline(cin, update);
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && update == Student[i].name)
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
                    cout << "Update name of " << Student[i].name << " : ";
                    cin.ignore(256, '\n');
                    getline(cin, Student[i].name);
                    cout << "Student's name has been succefully updated." << endl;
                    studentFlag = true;
                    break;
                }
                else if (choose == 2)
                {
                    cout << "Update class of " << Student[i].name << " : ";
                    cin >> classss;
                    classss = classRestriction(classss);
                    Student[i].sClass= classss;
                    cout << "Student's class has been succefully updated." << endl;
                    studentFlag = true;
                    break;
                }
                else if (choose == 3)
                {
                    cout << "Update roll no of " << Student[i].name << " : ";
                    cin >> rollNo;
                    rollNo = RollNoRestriction(rollNo);
                    Student[i].rollNo = rollNo;
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
void DisplayStudent(student Student[]) // view students(administrator)
{
    bool studentFlag = false;
    cout << setw(30) << " Student " << setw(35);
    cout << " Class " << setw(25) << " Roll No " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && Student[i].sClass != -2 && Student[i].rollNo != -1)
        {
            cout << setw(28) << Student[i].name << setw(32);
            cout << Student[i].sClass << setw(24) << Student[i].rollNo << endl; 
            studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"no students were added to display."<<endl;
    }
}
void SearchStudent(student Student[]) // search student (administrator)
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
                if (Student[i].name != "nv" && Student[i].name == search )
                {
                    cout << setw(28) << Student[i].name << setw(32);
                    cout << Student[i].sClass << setw(24) << Student[i].rollNo << endl;
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
                if (Student[i].name != "nv" && Student[i].sClass == searching)
                {
                    cout << setw(28) << Student[i].name << setw(32);
                    cout << Student[i].sClass << setw(24) << Student[i].rollNo << endl;
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
                if (Student[i].name != "nv" && Student[i].rollNo == searching)
                {
                    cout << setw(28) << Student[i].name << setw(32);
                    cout << Student[i].sClass << setw(24) << Student[i].rollNo << endl;
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
void DisplayStudentId(student Student[]) // view username and password of studnets(administrator)
{
    bool studentFlag = false;
    cout << setw(30) << " Student " << setw(35);
    cout << " UserName " << setw(25) << " Password " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && Student[i].userName != "nv" && Student[i].Password != "nv")
        {
            cout << setw(28) << Student[i].name << setw(32);
            cout << Student[i].userName << setw(24) << Student[i].Password << endl;
            studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students were added to displayed."<<endl;
    }
}
void ViewStudentsWithGrade(student Student[],int classCheck) // view student grade (teacher)
{
    bool studentFlag = false;
    cout << endl;
    cout << setw(30) << " Student " << setw(35);
    cout << " Grade " << setw(25) << " Roll No " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && classCheck == Student[i].sClass)
        {
            cout << setw(28) << Student[i].name << setw(32);
            cout << Student[i].grade << setw(24) << Student[i].rollNo << endl;
            studentFlag = true;
        }
    }
    if(studentFlag == false)
    {
        cout <<"No students to displayed."<<endl;
    }
}
void AddStudentsGrade(student Student[], int classCheck) // add student grade (teacher)
{
    bool studentFlag = false;
    string search;
    cout << "Enter name of student to enter his grade : ";
    cin.ignore(256, '\n');
    getline(cin, search);
    for (int i = 0; i < 10; i++)
    {

        if (Student[i].name == search && classCheck == Student[i].sClass)
        {
            cout << "Enter Grade of " << Student[i].name << " : ";
            cin >> Student[i].grade;
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
void ViewGradeByStudent(student Student[], int rollNoCheck) // view grade (student)
{
    bool studentFlag = false;
    cout << endl;
    cout << setw(30) << " Student " << setw(35);
    cout << " Grade " << setw(25) << " Roll No " << endl;
    cout << "*********************************************************************************" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && Student[i].rollNo == rollNoCheck)
        {

            cout << setw(28) << Student[i].name << setw(32);
            cout << Student[i].grade << setw(24) << Student[i].rollNo << endl;
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
void SaveData(teacher Teacher[], student Student[],int marks[][5]) // save data
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
        if (Teacher[i].name != "nv" && Teacher[i].userName != "nv" && Teacher[i].tClass != -1 && Teacher[i].age != -1 && Teacher[i].Password != "nv")
        {
            teacherout << Teacher[i].name << "," << Teacher[i].userName<< "," << Teacher[i].Password << "," << Teacher[i].tClass << "," << Teacher[i].age  << endl;
        }
    }
    teacherout.close();    //save data of students
    studentout.open("student.txt");
    for (int i = 0; i < 10; i++)
    {
        if (Student[i].name != "nv" && Student[i].userName != "nv" && Student[i].sClass != -2 && Student[i].rollNo != -1 && Student[i].Password != "nv")
        {
            studentout << Student[i].name <<"," << Student[i].userName <<"," << Student[i].Password << "," << Student[i].sClass << "," << Student[i].rollNo  << endl;
        }
    }
    studentout.close();
    marksout.open("marks.txt");   //save marks of students
    for(int i=0 ; i < 10 ; i++)
    {
        if(Student[i].name != "nv" && marks[i][0] != 0 && marks[i][1] && marks[i][2] != 0 && marks[i][3] != 0 && marks[i][4] != 0)
        {
            marksout << Student[i].grade << "," << marks[i][English] << "," <<marks[i][Urdu]<<","
                     <<marks[i][Math]<<","<<marks[i][Science]<<","<<marks[i][Islamiyat] <<endl;
                     
        }
    }
    marksout.close();
}
//load data from files
void loadData(teacher Teacher[],student Student[],int marks[][5]) // load data
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
        getline(studentIn , Student[i].name , ',');
        getline(studentIn , Student[i].userName , ',');
        getline(studentIn , Student[i].Password , ',');
        studentIn >> Student[i].sClass;
        studentIn.ignore();
        studentIn >> Student[i].rollNo;
        studentIn.ignore();
    }
    studentIn.close();
    ifstream teacherIn("teacher.txt");  // load data of teachers
    for (int i=0;i<5;i++)
    {
        getline(teacherIn , Teacher[i].name , ',');
        getline(teacherIn , Teacher[i].userName, ',');
        getline(teacherIn , Teacher[i].Password , ',');
        teacherIn >> Teacher[i].tClass;
        teacherIn.ignore();
        teacherIn >> Teacher[i].age;
        teacherIn.ignore();
    }
    teacherIn.close();
    ifstream marksIn("marks.txt");  //load data of student marks 
    for(int i=0;i < 10;i++)
    {
        marksIn >> Student[i].grade;
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
int AgeRestriction(int age) // age restriction
{
    while (true)
    {
        if (age >= 20 && age <= 60)
        {
            return age;
        }
        else
        {
            cout << "Age should be greater than 20 and less than 60." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter Age again : ";
            cin >> age;
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
int RollNoRestriction(int rollNo)  // roll no restriction
{
    while (true)
    {
        if (rollNo >= 1 && rollNo <= 35)
        {
            return rollNo;
        }
        else
        {
            cout << "Class should be between 1 and 35." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter roll no again : ";
            cin >> rollNo;
        }
    }
}
void ViewMarksByStudent(student Student[],int marks[][5],int rollNoCheck) // view marks by student(student)
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
        if (Student[i].name != "nv" && Student[i].rollNo == rollNoCheck && marks[i][0] != 0)
        {
            cout << Student[i].name << setw(20) << marks[i][English] << setw(20) << marks[i][Urdu]
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
void AddMarksOfStudent(student Student[], int marks[][5], int classcheck)  //add marks of student (teacher)
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

        if (Student[i].name == names && classcheck == Student[i].sClass)
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
void ViewStudentsWithMarks(student Student[],int marks[][5],int classcheck)   //view student with marks(teacher)
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
        if (Student[i].name != "nv" && classcheck == Student[i].sClass )
        {
            cout << Student[i].name << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
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
void SearchStudentsWithMarks(student Student[],int marks[][5],int classcheck)
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
    cout << setw(48) << "2.Student's Roll No " << endl;
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
                if (Student[i].name == search && classcheck == Student[i].sClass && marks[i][0] != 0)
                {
                    cout << Student[i].name << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
                    << setw(20) << marks[i][Urdu] << setw(20) << marks[i][Science]
                    << setw(20) << marks[i][Islamiyat] << endl;
                    studentFlag = true;
                    break;
                }
            }
        }
        else if (choose == 2)
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
                if (Student[i].name != "nv" && classcheck == Student[i].sClass && marks[i][0] != 0 && Student[i].rollNo == searching)
                {
                    cout << Student[i].name << setw(19) << marks[i][English] << setw(20) << marks[i][Math]
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
