#include <iostream>
#include <string>
#include <vector>

class Student{
private:
	std::string studentName;
	int studentID;
	int gradeLevel;
public:
	Student() : studentName("Unknown"), studentID(0), gradeLevel(0) {};
	Student(const std::string& name, int id, int level) : studentName(name), studentID(id), gradeLevel(level) {};


	void displaystudent() const{
		std::cout<<"The student's name is"<<studentName<<std::endl;
		std::cout<<"The student ID is"<<studentID<<std::endl;
		std::cout<<"The student grade level is"<<gradeLevel<<std::endl;
	}
};

class Teacher{
private:
	std::string teacherName;
	int teacherID;
	std::string teacherSubject;
public:
	
	Teacher() : teacherName("Unknown"), teacherID(0), teacherSubject("Unknown") {}
	Teacher(const std::string& name, int id, const std::string& subject) :
teacherName(name), teacherID(id), teacherSubject(subject) {}
	
	void displayteacher() const{
		std::cout<<"The teacher's name is"<<teacherName<<std::endl;
                std::cout<<"The teacher's ID is"<<teacherID<<std::endl;
                std::cout<<"The teacher's subject is"<<teacherSubject<<std::endl;
  	}
};

class ClassRoom{
private:
	std::string className;
	Teacher classTeacher;
	Student students[5];
	int studentCount;
	int maxStudents;
public:
	ClassRoom() : className("Unknown"), classTeacher(), studentCount(0), maxStudents(5){}
	ClassRoom(const std::string& name, const Teacher& teacher, int max) : className(name), classTeacher(teacher), studentCount(0), maxStudents(max){}

	void addStudent(const Student& student){
		if (studentCount < maxStudents) {
 	      		 students[studentCount] = student;
      		         studentCount++;
    		} else {
       			 std::cout << "Error `class is full" << std::endl;
  		       }			
	}		
	
	void displayClass() const{
		std::cout<<"The class name is"<<className<<std::endl;
		classTeacher.displayteacher();
		for(int i = 0; i<studentCount; i++){
			students[i].displaystudent();
		}
	}

};

int main() {
	Teacher t("Mr. John Doe", 0, "Mathematics");
	Student s("Alice Johnson", 201, 10);
	Student s2("Bob Moore", 202, 10);
	Student s3("Charlie brown", 203, 10);

	ClassRoom room("10th Grade Mathematics", t, 2);
	room.addStudent(s);
	room.addStudent(s2);
	room.addStudent(s3);
	
	room.displayClass();
	return 0;
}
