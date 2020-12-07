#include <iostream>

using namespace std;

struct Student{
    string name;
    string major;
    int age;
    int has_scholarship=false;

    void createStudent(string _name, string _major, int _age) {
        name = _name;
        major = _major;
        age = _age;
    }

    void showStudent() {
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Major: " << major << endl;
        cout << "Age: " << age << endl;
    }

    void setHasScholarship(bool _val) {
        has_scholarship = _val;
    }

    bool getHasScholarship() {
        return has_scholarship;
    }
};

struct Course{
    string name;
    int duration;
    Student* students[100];
    int current_students = 0;

    void createCourse(string _name, int _duration) {
        name = _name;
        duration = _duration;
    }

    void addStudent(Student* _student) {
        if (current_students < 100) {
            students[current_students] = _student;           
            current_students++;
        }
    }

    Student* removeStudent(Student* _student) {
        bool found = false;
        Student* tmp=nullptr;
        for (int i = 0; i <= current_students; i++) {
            if (students[i] == _student) {
                found = true;
                tmp = students[i];
                students[i] = students[i + 1];
            }
            else if (found) {
                if (i != current_students) {
                    students[i] = students[i + 1];
                }
            }
        }
        if (found) {
            current_students--;
        }
        return tmp;
    }


    void showCourseDetails() {
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Duration: " << duration << endl;
        cout << "Students: \n";
        for (int i = 0; i < current_students; i++) {
            students[i]->showStudent();
        }
    }
};

struct University{
    string name;
    Course* courses[100];
    int current_courses=0;
    int current_students=0;

    void createUniversity(string _name) {
        name = _name;
    }

    void addCourse(Course* _course) {
        if (current_courses < 100) {
            courses[current_courses] = _course;
            current_courses++;
        }
    }

    int getCurrentStudents() {
        current_students = 0;
        for (int i = 0; i < current_courses; i++) {
            current_students += courses[i]->current_students;
        }
        return current_students;
    }

    void showUniversityDetails() {
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Current students: " << getCurrentStudents() << endl;
        for (int i = 0; i < current_courses; i++) {
            courses[i]->showCourseDetails();
        }
    }
};





int main() {
    Student karol = { "Karol","cs",18 };
    Student marek = { "Marek","mth",23 };
    Student* pt1 = &karol;
    Student* pt2 = &marek;
    Course P1;
    P1.createCourse("Programownaie 1", 1);
    P1.addStudent(pt1);
    P1.addStudent(pt2);
    P1.showCourseDetails();

    Student kamil = { "Kamil","tcs",29 };
    Student* pt3 = &kamil;
    P1.addStudent(pt3);
    P1.showCourseDetails();

    Student* pt4 = P1.removeStudent(pt1);
    P1.showCourseDetails();

    // pt4->showStudent();
    Course* ptc1 = &P1;
    University uj;
    uj.createUniversity("Uniwersytet Jagielonski");
    uj.addCourse(ptc1);
    uj.showUniversityDetails();


    Student ola;
    Student* pt5 = &ola;
    ola.createStudent("Ola", "cs", 21);
    Course ALG;
    Course* ptc2 = &ALG;
    ALG.createCourse("Algebra", 2);
    ALG.addStudent(pt1);
    ALG.addStudent(pt5);
    ALG.addStudent(pt2);
    uj.addCourse(ptc2);

    uj.showUniversityDetails();
}
