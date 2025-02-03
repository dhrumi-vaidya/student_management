#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
     int roll_no;
     string name;
     string dob;
     int contact;
     string address;
     char div;
     int cls;
     int maths, english, science;

public:
     Student(int roll = 0, string name = "D", string dateofb = "1-1-03", int p_contact = 1234567890, string addr = "abxcy", char div = 'A', int cls = 1)
     {
          roll_no = roll;
          name = name;
          dob = dateofb;
          contact = p_contact;
          address = addr;
          div = div;
          cls = cls;
     }

     void getdetails(int roll_no);
     void setdetails();
     void showgrades(int roll_no);
     void showresult(int roll_no);
     void showAllStudents();
};

void Student::setdetails()
{
     cout << "Enter your name: ";
     cin >> name;
     cin.ignore();
     cout << "Enter Your Roll No: ";
     cin >> roll_no;
     cin.ignore();
     cout << "Enter your class: ";
     cin >> cls;
     cin.ignore();
     cout << "Enter your division: ";
     cin >> div;
     cin.ignore();
     cout << "Enter your Date Of Birth: ";
     cin >> dob;
     cin.ignore();
     cout << "Enter your address: ";
     cin >> address;
     cin.ignore();
     cout << "Enter your parents contact no.: ";
     cin >> contact;

     ofstream ofs("Student.txt", ios::app);
     ofs << name << " " << roll_no << " " << cls << " " << div << " " << dob << " " << address << " " << contact << endl;
     ofs.close();
     cout << "Details Saved Successfully!" << endl;
}

void Student::getdetails(int roll_no)
{
     ifstream ifs("Student.txt");
     bool found = false;
     while (ifs >> name >> this->roll_no >> cls >> div >> dob >> address >> contact)
     {
          if (this->roll_no == roll_no)
          {
               cout << "Student found!" << endl;
               cout << "Name: " << name << endl;
               cout << "Roll No: " << roll_no << endl;
               cout << "Class: " << cls << endl;
               cout << "Division: " << div << endl;
               cout << "Date of Birth: " << dob << endl;
               cout << "Address: " << address << endl;
               cout << "Contact Number: " << contact << endl;
               found = true;
               break;
          }
     }
     ifs.close();
     if (!found)
     {
          cout << "Student not found!" << endl;
     }
}

void Student::showresult(int roll_nom)
{
     ifstream ifs("Student.txt");
     int existing_student;
     while (ifs >> name >> roll_no >> cls >> div >> dob >> address >> contact)
     {
          int existing_student = roll_no;
          // cout << existing_student << endl;
          // cout << roll_nom << endl;
          if (existing_student == roll_nom)
          {
               cout << "Result: " << endl;
               ifstream ifs("generateMarks.txt");
               bool found = false;
               while (ifs >> this->roll_no >> maths >> english >> science)
               {
                    if (this->roll_no == roll_no)
                    {
                         cout << "Maths: " << maths << endl;
                         cout << "English: " << english << endl;
                         cout << "Science: " << science << endl;
                         found = true;
                         break;
                    }
               }
               ifs.close();
               if (!found)
               {
                    cout << "Student's result not generated yet" << endl;
               }
          }

          else
          {
               cout << "Sorry your are not a registered student " << endl;
          }
     }
}
void Student::showgrades(int roll_nom)
{
     ifstream ifs("Student.txt");
     int existing_student;
     while (ifs >> name >> roll_no >> cls >> div >> dob >> address >> contact)
     {
          int existing_student = roll_no;
          // cout << existing_student << endl;
          // cout << roll_nom << endl;
          if (existing_student == roll_nom)
          {
               cout << "Grade of roll number " << roll_no << " is: ";
               ifstream ifs("generateMarks.txt");
               bool found = false;
               int maths, english, science;
               while (ifs >> this->roll_no >> maths >> english >> science)
               {
                    if (this->roll_no == roll_no)
                    {
                         int total = maths + english + science;
                         double average = total / 3.0;

                         char grade;
                         if (average >= 90)
                         {
                              grade = 'A';
                         }
                         else if (average >= 75)
                         {
                              grade = 'B';
                         }
                         else if (average >= 50)
                         {
                              grade = 'C';
                         }
                         else
                         {
                              grade = 'D';
                         }

                         cout << grade << endl;
                         found = true;
                         break;
                    }
                    ifs.close();
                    if (!found)
                    {
                         cout << "Student not registered" << endl;
                    }
               }
          }
          else
          {
               cout << "No Grade generated as student is not registered " << endl;
          }
     }
}

void Student::showAllStudents()
{
     ifstream ifs("Student.txt");
     string name;
     int roll_no, cls, contact;
     char div;
     string dob, address;
     while (ifs >> name >> roll_no >> cls >> div >> dob >> address >> contact)
     {
          cout << "Name: " << name << ", Roll No: " << roll_no << ", Class: " << cls << ", Division: " << div << ", DOB: " << dob << ", Address: " << address << ", Contact: " << contact << endl;
     }
     ifs.close();
}

class Teacher
{
private:
     int tr_id;
     string tr_name;
     int result;
     char grade;
     int clss;
     char divi;

public:
     Teacher() {}
     Teacher(int id, string t_name, int stu_result, char stu_grade, int tr_cls, char tr_divi)
     {
          tr_id = id;
          tr_name = t_name;
          result = stu_result;
          grade = stu_grade;
          clss = tr_cls;
          divi = tr_divi;
     }

     void TeacherRegistration();
     void dispDetails(int tr_id);
     void generateResult(int roll_no);
     void generateGrade();
     void showDetailsOfAllStudents(); // shows roll_no, teacher_name, grade of all students;
};

void Teacher::TeacherRegistration()
{
     cout << "Enter your name: ";
     cin >> tr_name;
     cin.ignore();
     cout << "Enter Your ID: ";
     cin >> tr_id;
     cout << "Enter your class: ";
     cin >> clss;
     cout << "Enter your division: ";
     cin >> divi;
     ofstream ofs("Teacher.txt", ios::app);
     ofs << tr_name << " " << tr_id << " " << clss << " " << divi << endl;
     ofs.close();
     cout << "Details Saved Successfully!" << endl;
}

void Teacher::dispDetails(int tr_id)
{
     ifstream ifs("Teacher.txt");
     bool found = false;
     while (ifs >> tr_name >> this->tr_id >> clss >> divi)
     {
          if (this->tr_id == tr_id)
          {
               cout << "Teacher Found!" << endl;
               cout << "Name: " << tr_name << endl;
               cout << "Teacher ID: " << tr_id << endl;
               cout << "Class: " << clss << endl;
               cout << "Division: " << divi << endl;
               found = true;
               break;
          }
     }
     ifs.close();
     if (!found)
     {
          cout << "Teacher not found!" << endl;
     }
}

void Teacher::generateResult(int roll_nom)
{
     ifstream ifs("Student.txt");
     string name;
     int roll_no, cls, contact;
     char div;
     string dob, address;
     int existing_student;
     while (ifs >> name >> roll_no >> cls >> div >> dob >> address >> contact)
     {
          int existing_student = roll_no;
          cout << existing_student << endl;
          cout << roll_nom << endl;

          if (existing_student == roll_nom)
          {
               int maths, science, english;
               cout << "Enter marks:" << endl;
               cout << "Maths marks: ";
               cin >> maths;
               cin.ignore();
               cout << "English marks: ";
               cin >> english;
               cin.ignore();
               cout << "Science marks: ";
               cin >> science;

               ofstream ofs("generateMarks.txt", ios::app);
               ofs << roll_no << " " << maths << " " << english << " " << science << endl;
               ofs.close();
               cout << "Marks stored successfully" << endl;
          }
          else
          {
               cout << "Student not found" << endl;
          }
     }
     ifs.close();
}

void Teacher::generateGrade()
{

     ifstream ifs("generateMarks.txt");
     int roll_no, maths, english, science;
     while (ifs >> roll_no >> maths >> english >> science)
     {
          int total = maths + english + science;
          double average = total / 3.0;

          char grade;
          if (average >= 90)
          {
               grade = 'A';
          }
          else if (average >= 75)
          {
               grade = 'B';
          }
          else if (average >= 50)
          {
               grade = 'C';
          }
          else
          {
               grade = 'D';
          }

          cout << "Roll No: " << roll_no << " Grade: " << grade << endl;
     }
     ifs.close();
}

void Teacher::showDetailsOfAllStudents()
{
     ifstream ifs("generateMarks.txt");
     int roll_no, maths, english, science;
     while (ifs >> roll_no >> maths >> english >> science)
     {
          cout << "Roll No: " << roll_no << ", Maths: " << maths << ", English: " << english << ", Science: " << science << endl;
     }
     ifs.close();
}

int main()
{
     int roll_no;
     string s_name;
     string dob;
     int s_contact;
     string address;
     int tr_id;
     string tr_name;
     int marks;
     int role_choice;

     cout << "Student Management System" << endl;
     // cout << "Role 1: Student " << endl
     //      << "Role 2: Teacher " << endl;
     do
     {
          cout << "Role 1: Student " << endl
               << "Role 2: Teacher " << endl;
          cout << "Select your role (Enter 0 to exit): ";
          cin >> role_choice;

          if (role_choice == 1)
          {
               cout << "Welcome Student!" << endl;
               Student s;
               int op_choices;
               do
               {
                    cout << "Select the desired operation:" << endl;
                    cout << "1. New Student Registration" << endl;
                    cout << "2. Show Student Details" << endl;
                    cout << "3. Show Result" << endl;
                    cout << "4. Show Grade" << endl;
                    cout << "5. Show All Students" << endl;
                    cout << "6. Exit" << endl;
                    cin >> op_choices;

                    switch (op_choices)
                    {
                    case 1:
                    {
                         cout << "OP 1" << endl;
                         s.setdetails();
                         break;
                    }
                    case 2:
                    {
                         cout << "Enter Roll No: ";
                         cin >> roll_no;
                         s.getdetails(roll_no);
                         break;
                    }
                    case 3:
                    {
                         cout << "Enter Roll No: ";
                         cin >> roll_no;
                         s.showresult(roll_no);
                         break;
                    }
                    case 4:
                    {
                         cout << "Enter Roll No: ";
                         cin >> roll_no;
                         s.showgrades(roll_no);
                         break;
                    }
                    case 5:
                         s.showAllStudents(); // Show all students
                         break;
                    case 6:
                         break;
                    default:
                         cout << "Invalid option!" << endl;
                         break;
                    }
               } while (op_choices != 6);
          }
          else if (role_choice == 2)
          {
               cout << "Welcome Teacher!" << endl;
               Teacher t;
               int top_choices;
               do
               {
                    cout << "Select the desired operation:" << endl;
                    cout << "1. Teacher Registration" << endl;
                    cout << "2. Display Teacher Details" << endl;
                    cout << "3. Generate Result" << endl;
                    cout << "4. Generate Grade" << endl;
                    cout << "5. Show All Students" << endl;
                    cout << "6. Exit" << endl;
                    cin >> top_choices;

                    switch (top_choices)
                    {
                    case 1:
                         t.TeacherRegistration();
                         break;
                    case 2:
                         cout << "Enter Teacher ID: ";
                         cin >> tr_id;
                         t.dispDetails(tr_id);
                         break;
                    case 3:
                         cout << "Enter the roll no of student: ";
                         cin >> roll_no;
                         t.generateResult(roll_no);
                         break;
                    case 4:
                         t.generateGrade();
                         break;
                    case 5:
                         t.showDetailsOfAllStudents();
                         break;
                    case 6:
                         break;
                    default:
                         cout << "Invalid option!" << endl;
                         break;
                    }
               } while (top_choices != 6);
          }
     } while (role_choice != 0);

     return 0;
}
