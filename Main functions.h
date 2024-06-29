#include <iostream>
#include "Database Class.h"
using namespace std ;
Database db ;
void switchPartTwo(int choice) ;
void switchPartThree(int choice) ;
void switchPartFour(int choice) ;
void options(){
	cout << "\t\t\t\t\t\t\t  Welcome to our Student System\n\n\n" ;
		cout << "If you want to ADD STUDENT press 1\n\n" ;
		cout << "If you want to ADD COURSE press 2\n\n" ;
		cout << "If you want to SHOW STUDENT INFORMATION press 3\n\n" ;
		cout << "If you want to SHOW COURSE INFORMATION press 4\n\n" ;
		cout << "If you want to ENROLL STUDENT IN ANY COURSE press 5\n\n" ;
		cout << "If you want to SHOW STUDENT ENROLLED COURSES press 6\n\n" ;
		cout << "If you want to SET GRADE FOR A STUDENT press 7\n\n" ;
		cout << "If you want to SHOW STUDENT ENROLLED COURSES AND GRADES press 8\n\n" ;
		cout << "If you want to UPDATE GRADE FOR A STUDENT press 9\n\n" ;
		cout << "If you want to REMOVE STUDENT press 10\n\n" ;
		cout << "If you want to REMOVE COURSE press 11\n\n" ;
		cout << "If you want to SHOW COURSE ENROLLED STUDENTS press 12\n\n" ;
		cout << "If you want to SHOW A REPORT FOR ALL STUDENTS press 13\n\n" ;
		cout << "If you want to SHOW A REPORT FOR ALL COURSES press 14\n\n" ;
		cout << "If you want to MODIFY STUDENT INFORMATION press 15\n\n" ;
		cout << "If you want to MODIFY COURSE INFORMATION press 16\n\n" ;
		cout << "If you want to exit press 0\n\n" ;
}
void endMessage(){
	cout << "\n\nThanks for using our system\n" ;
	cout << "If you want to exit press 0\n" ;
	cout << "If you want to return to the start menu press any number\n" ;
}
void switchPartOne(int choice){
	switch (choice){
		case 0 : return ;
		case 1 :
			db.addStudent() ; break ;
		case 2 :
			db.addCourse() ; break ;
		case 3 :
			db.searchStudent() ; break ;
		case 4 :
			db.searchCourse() ; break ;
		default :
			switchPartTwo(choice) ;
	}
}
void switchPartTwo(int choice){
	switch (choice){
		case 5 :
			db.enrollStudent() ; break ;
		case 6 :
			db.showStudentEnrolledCourses() ; break ;
		case 7 :
			db.addGrade() ; break ;
		case 8 :
			db.getStudentGrades() ; break ;
		default :
			switchPartThree(choice) ;
	}
}
void switchPartThree(int choice){
	switch (choice){
		case 9 :
			db.updateGrade() ; break ;
		case 10 :
			db.removeStudent() ; break ;
		case 11 :
			db.removeCourse() ; break ;
		case 12 :
			db.showCourseEnrollments() ; break ;
		default :
			switchPartFour(choice) ;
	}
}
void switchPartFour(int choice){
	switch (choice){
		case 13 :
			db.reportOfAllStudents() ; break ;
		case 14 :
			db.reportOfAllCourses() ; break ;
		case 15 :
			db.modifyStudent() ; break ;
		case 16 :
			db.modifyCourse() ; break ;
		default :
			cout << "Invalid choice\n" ;
	}
}
