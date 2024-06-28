#include <iostream>
using namespace std ;
class Enroll{
	private :
		int studentID , courseID ;
	public :
		Enroll(int studentID , int courseID){
			this->studentID = studentID ;
			this->courseID = courseID ;
		}
		int getStudentID(){
			return studentID ;
		}
		int getCourseID(){
			return courseID ;
		}
};
