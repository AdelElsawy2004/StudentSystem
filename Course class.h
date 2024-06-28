#include <iostream>
#include <map>
using namespace std ;
map <int , bool> idExistCourse ;
class Course {
	private :
		int courseID , maxCapacity ;
		string courseName , instructor ;
		bool isValidID(int id){
			return idExistCourse[id] == false && id > 0 ;
		}
		bool isValidMaxCapacity(int n){
			return n > 0 ;
		}
	public :
		Course (int id , string name , string inst , int maxCap){
			courseName = name , instructor = inst ;
			while (!isValidID(id)){
				cout << "Please Enter another id for " << name << " course\n" ;
				cin >> id ;
			}
			while (!isValidMaxCapacity(maxCap)){
				cout << "Please Enter a max capacity greater than 0\n" ;
				cin >> maxCap ;
			}
			maxCapacity = maxCap ;
			courseID = id ;
			idExistCourse[id] = true ;
		}
		Course (){
		}
		int getCourseID(){
			return courseID ;
		}
		string getCourseName(){
			return courseName ;
		}
		string getInstructor(){
			return instructor ;
		}
		int getMaxCapacity(){
			return maxCapacity ;
		}
		void setCourseName(string name){
			courseName = name ;
		}
		void setInstructor(string ins){
			instructor = ins ;
		}
		void setMaxCapacity(int n){
			maxCapacity = n ;
		}
		void getDetails(){
			cout << "ID : " << courseID << endl ;
			cout << "Course name : " << courseName << endl ;
			cout << "Instructor : " << instructor << endl ;
			cout << "Max capacity : " << maxCapacity << endl ;
		}
};
