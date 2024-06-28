#include <iostream>
using namespace std ;
class Grade {
	private :
		int grade , studentID , courseID ;
		bool isValid(int x){
			return (x >= 0 && x <= 100) ;
		}
	public :
		Grade (int grade , int studentID , int courseID){
			this->studentID = studentID , this->courseID = courseID ;
			while (!isValid(grade)){
				cout << "Please enter a valid grade between 0 and 100 : " ;
				cin >> grade ;
			}
			this->grade = grade ;
		}
		int getStudentID(){
			return studentID ;
		}
		int getCourseID(){
			return courseID ;
		}
		int getGrade(){
			return grade ;
		}
		void setGrade(int g){
			while (!isValid(g)){
				cout << "Please enter grade between 0 and 100 : " ;
				cin >> g ;
			}
			grade = g ;
		}
};
