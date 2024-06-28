#include <iostream>
#include <vector>
#include <map>
#include "Student class.h"
#include "Course class.h"
#include "Grade class.h"
#include "Enroll class.h"
using namespace std ;
map <int , int> maxCapacity , currentCapacity ;
class Database{
	private :
		vector <Student> students ;
		vector <Course> courses ;
		vector <Grade> grades ;
		vector <Enroll> enrollments ;
	public :
		void addStudent(){
			int id ;
			string name , DOB , contact_information ;
			cout << "Please enter the student :\nName : " ;
			cin.ignore() ;
			getline(cin , name) ;
			cout << "ID : " ;
			cin >> id ;
			cin.ignore() ;
			cout << "Date of birth : " ;
			getline(cin , DOB) ;
			cout << "Contact information : " ;
			getline(cin , contact_information) ;
			students.push_back(Student(name , DOB , contact_information , id)) ;
		}
		void addCourse(){
			string name , instructor ;
			int id , maxCap ;
			cout << "Please Enter the course :\nName : " ;
			cin.ignore() ;
			getline(cin , name) ;
			cout << "ID : " ;
			cin >> id ;
			cin.ignore() ;
			cout << "Instructor name : " ;
			getline(cin , instructor) ;
			cout << "Max capacity : " ;
			cin >> maxCap ;
			courses.push_back(Course(id , name , instructor , maxCap)) ;
			maxCapacity[id] = maxCap ;
			currentCapacity[id] = 0 ;
		}
		void enrollStudent(){
			int student_id , course_id ;
			cout << "Please enter the student ID and course ID respectively : " ;
			cin >> student_id >> course_id ;
			if (searchStudentIndex(student_id) == -1)
				cout << "There is no student with id " << student_id << endl ;
			else if (searchCourseIndex(course_id) == -1)
				cout << "There is no course with id " << course_id << endl ;
			else if (isStudentEnrollCourse(student_id , course_id))
				cout << "This student has already enrolled this course\n" ;
			else if (maxCapacity[course_id] == currentCapacity[course_id])
				cout << "Can't enroll this course because its capacity has reached the limit\n" ;
			else{
				enrollments.push_back(Enroll(student_id , course_id)) ;
				++currentCapacity[course_id] ;
				cout << "The enrollment has been done successfully\n" ;
			}
		}
		void showStudentEnrolledCourses(){
			int id ;
			cout << "Please enter the student ID : " ;
			cin >> id ;
			int studentIndex = searchStudentIndex(id) ;
			if (studentIndex != -1){
				cout << "Name : " << students[studentIndex].getStudentName() << endl ;
				cout << "Courses :\n" ;
				for (int i = 0 ; i < enrollments.size() ; ++i)
					if (enrollments[i].getStudentID() == id)
						cout << courses[searchCourseIndex(enrollments[i].getCourseID())].getCourseName() << endl ;
			}
			else
				cout << "There is no student with ID " << id << endl ;
		}
		void addGrade(){
			int course_id , student_id , grade ;
			cout << "Student ID : " ;
			cin >> student_id ;
			cout << "Course ID : " ;
			cin >> course_id ;
			cout << "Grade : " ;
			cin >> grade ;
			if (isStudentEnrollCourse(student_id , course_id)){
				grades.push_back(Grade(grade , student_id , course_id)) ;
				cout << "The grade has been added successfully\n" ;
			}
			else
				cout << "This student doesn't enroll this course\n" ;
		}
		void searchStudent(){
			int id ;
			cout << "Please enter the student's ID : " ;
			cin >> id ;
			for (int i = 0 ; i < students.size() ; ++i){
				if(id == students[i].getStudentID()){
					students[i].getDetails() ;
					return ;
				}
			}
			cout << "There is no student with ID " << id << endl ;
		}
		void searchCourse(){
			int id ;
			cout << "Please enter the course ID : " ;
			cin >> id ;
			for (int i = 0 ; i < courses.size() ; ++i){
				if(id == courses[i].getCourseID()){
					courses[i].getDetails() ;
					return ;
				}
			}
			cout << "There is no coure with ID " << id << endl ;
		}
		void updateGrade(){
			int studentID , courseID , grade ;
			cout << "Student ID : " ;
			cin >> studentID ;
			cout << "Course ID : " ;
			cin >> courseID ;
			cout << "Grade : " ;
			cin >> grade ;
			int gradeIndex = searchGradeIndex(studentID , courseID) ;
			if (gradeIndex == -1)
				cout << "This grade has not been submitted before.\nPlease submit it and try again\n" ;
			else{
				grades[gradeIndex].setGrade(grade) ;
				cout << "The grade has been updated successfully\n" ;
			}
		}
		void getStudentGrades(){
			int id ;
			cout << "Please enter the student ID : " ;
			cin >> id ;
			int studentIndex = searchStudentIndex(id) ;
			if (studentIndex != -1){
				cout << "Name : " << students[studentIndex].getStudentName() << endl ;
				cout << "Courses :\n" ;
				for (int i = 0 ; i < grades.size() ; ++i)
					if (id == grades[i].getStudentID())
						cout << courses[searchCourseIndex(grades[i].getCourseID())].getCourseName() << " : " << grades[i].getGrade() << endl ;
			}
			else
				cout << "There is no student with ID " << id ;
		}
		void removeStudent(){
			int id ;
			cout << "Enter the student ID : " ;
			cin >> id ;
			int studentIndex = searchStudentIndex(id) ;
			if (studentIndex != -1){
				idExistStudent.erase(id) ;
				students.erase(students.begin() + studentIndex) ;
				removeEnrollment(id) ;
				cout << "The student has been removed successfully!\n" ;
			}
			else
				cout << "There is no student with ID " << id << endl ;
		}
		void removeCourse(){
			int id ;
			cout << "Enter the course ID : " ;
			cin >> id ;
			int courseIndex = searchCourseIndex(id) ;
			if (courseIndex != -1){
				idExistCourse.erase(id) ;
				courses.erase(courses.begin() + courseIndex) ;
				for (int i = 0 ; i < enrollments.size() ; ++i){
					if (enrollments[i].getCourseID() == id){
						enrollments.erase(enrollments.begin() + i) ;
						--i ;
					}
				}
				for (int i = 0 ; i < grades.size() ; ++i){
					if (grades[i].getCourseID() == id){
						grades.erase(grades.begin() + i) ;
						--i ;
					}
				}
				cout << "The course has been removed successfully!\n" ;
			}
			else
				cout << "There is no course with ID " << id << endl ;
		}
		void showCourseEnrollments(){
			int id ;
			cout << "Enter the course ID : " ;
			cin >> id ;
			int courseIndex = searchCourseIndex(id) ;
			if (courseIndex != -1){
				cout << "Course : " << courses[courseIndex].getCourseName() << endl ;
				cout << "Students :\n" ;
				int counter = 1 ;
				for (int i = 0 ; i < enrollments.size() ; ++i){
					if (enrollments[i].getCourseID() == id)
						cout << counter++ << " - " << students[searchStudentIndex(enrollments[i].getStudentID())].getStudentName() << endl ;
				}
			}
			else
				cout << "There is no enrollment in this course\n" ;
		}
		void reportOfAllStudents(){
			for (int i = 0 ; i < students.size() ; ++i){
				cout << "ID : " << students[i].getStudentID() << endl ;
				cout << "Name : " << students[i].getStudentName() << endl ;
				cout << "Date of birth : " << students[i].getDateOfBirth() << endl ;
				cout << "Contact information : " << students[i].getContactInformation() << endl ;
				cout << "\n\n" ;
			}
		}
		void reportOfAllCourses(){
			for (int i = 0 ; i < courses.size() ; ++i){
				cout << "ID : " << courses[i].getCourseID() << endl ;
				cout << "Name : " << courses[i].getCourseName() << endl ;
				cout << "Instructor : " << courses[i].getInstructor() << endl ;
				cout << "Max capacity : " << courses[i].getMaxCapacity() << endl ;
				cout << "\n\n" ;
			}
		}
		void modifyStudent(){
			int id ;
			cout << "Please enter the student ID : " ;
			cin >> id ;
			int studentIndex = searchStudentIndex(id) ;
			if (studentIndex == -1){
				cout << "There is no student with id " << id << endl ;
				return ;
			}
			modifyStudentOptions() ;
			int choice = getChoice() ;
			cin.ignore() ;
			string newValue ;
			switch (choice){
				case 1 :
					cout << "Enter the new name : " ; break ;
				case 2 :
					cout << "Enter the new date of birth : " ; break ;
				case 3 :
					cout << "Enter the new contact information : " ; break ;
				default :
					cout << "Invalid choice\n" ; return ;
			}
				getline(cin , newValue) ;
			if (choice == 1)
				students[studentIndex].setStudentName(newValue) ;
			else if (choice == 2)
				students[studentIndex].setDateOfBirth(newValue) ;
			else if (choice == 3)
				students[studentIndex].setContactInformation(newValue) ;
			cout << "The operation has been done successfully\n" ;
		}
		void modifyCourse(){
			int id ;
			cout << "Please Enter the course ID : " ;
			cin >> id ;
			int courseIndex = searchCourseIndex(id) ;
			if (courseIndex == -1){
				cout << "There is no course with id " << id << endl ;
				return ;
			}
			modifyCourseOptions() ;
			int choice = getChoice() ;
			switch (choice){
				case 1 :
					cout << "Enter the new course name : " ; break ;
				case 2 :
					cout << "Enter the new instructor name : " ; break ;
				case 3 :
					cout << "Enter the new max Capacity : " ; break ;
				default :
					cout << "Invalid choice\n" ; return ;
			}
			if (choice == 1 || choice == 2){
				string newValue ;
				cin.ignore() ;
				getline(cin , newValue) ;
				if (choice == 1)
					courses[courseIndex].setCourseName(newValue) ;
				else
					courses[courseIndex].setInstructor(newValue) ;
			}
			else{
				
				int n ;
				cin >> n ;
				if (n < currentCapacity[id]){
					cout << "Cannot do this operation because number of student enroll in this course exceed the new max capacity\n" ;
					return ;
				}
				courses[courseIndex].setMaxCapacity(n) ;
				maxCapacity[id] = n ;
			}
			cout << "The operation has been done successfully\n" ;
		}
		
		
		
		
		int searchCourseIndex(int id){
			for (int i = 0 ; i < courses.size() ; ++i)
				if (courses[i].getCourseID() == id)
					return i ;
			return -1 ;
		}
		int searchStudentIndex(int id){
			for (int i = 0 ; i < students.size() ; ++i)
				if (students[i].getStudentID() == id)
					return i ;
			return -1 ;
		}
		int searchGradeIndex(int studentID , int courseID){
			for (int i = 0 ; i < grades.size() ; ++i){
				if (grades[i].getStudentID() == studentID && grades[i].getCourseID() == courseID)
					return i ;
			}
			return -1 ;
		}
		bool isStudentEnrollCourse(int studentID , int courseID){
			for (int i = 0 ; i < enrollments.size() ; ++i)
				if (enrollments[i].getStudentID() == studentID
				&& enrollments[i].getCourseID() == courseID)
					return true ;
			return false ;
		}
		void removeGrade(int studentID , int courseID = -1){
			if (courseID == -1)
				for (int i = 0 ; i < grades.size() ; ++i)
					if (grades[i].getStudentID() == studentID){
						grades.erase(grades.begin() + i) ;
						--i ;
					}
			else
				for (int i = 0 ; i < grades.size() ; ++i)
					if (grades[i].getStudentID() == studentID && grades[i].getCourseID() == courseID){
						grades.erase(grades.begin() + i) ;
						break ;
					}
		}
		void removeEnrollment(int studentID , int courseID = -1){
			if (courseID == -1)
				for (int i = 0 ; i < enrollments.size() ; ++i)
					if (enrollments[i].getStudentID() == studentID){
						--currentCapacity[enrollments[i].getCourseID()] ;
						enrollments.erase(enrollments.begin() + i) ;
						--i ;
					}
			else
				for (int i = 0 ; i < enrollments.size() ; ++i)
					if (enrollments[i].getStudentID() == studentID && enrollments[i].getCourseID() == courseID){
						--currentCapacity[courseID] ;
						enrollments.erase(enrollments.begin() + i) ;
						break ;
					}
			removeGrade(studentID , courseID) ;
		}
		void modifyStudentOptions(){
			cout << "For modifying name press 1\n" ;
			cout << "For modifying date of birth press 2\n" ;
			cout << "For modifying contact information press 3\n" ;
		}
		void modifyCourseOptions(){
			cout << "For modifying course name press 1\n" ;
			cout << "For modifying instructor name press 2\n" ;
			cout << "For modifying max capacity press 3\n" ;
		}
		int getChoice(){
			int choice ;
			cin >> choice ;
			return choice ;
		}
};
