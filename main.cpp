#include <iostream>
#include "Database Class.h"
#include "Main functions.h"
using namespace std ;
int main(){
	Database db ;
	int choice ;
	do{
		options() ;
		cin >> choice ;
		switch (choice){
			case 0 : return 0 ;
			case 1 :
				db.addStudent() ; break ;
			case 2 :
				db.addCourse() ; break ;
			case 3 :
				db.searchStudent() ; break ;
			case 4 :
				db.searchCourse() ; break ;
			case 5 :
				db.enrollStudent() ; break ;
			case 6 :
				db.showStudentEnrolledCourses() ; break ;
			case 7 :
				db.addGrade() ; break ;
			case 8 :
				db.getStudentGrades() ; break ;
			case 9 :
				db.updateGrade() ; break ;
			case 10 :
				db.removeStudent() ; break ;
			case 11 :
				db.removeCourse() ; break ;
			case 12 :
				db.showCourseEnrollments() ; break ;
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
		endMessage() ;
	} while(cin >> choice , choice) ;
}
