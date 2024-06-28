#include <iostream>
#include <map>
using namespace std ;
map <int , bool> idExistStudent ;
class Student{
	private :
		int studentID ;
		string studentName , DOB , contactInfo ;
		bool isValid(int id){
			return idExistStudent[id] == false && id > 0 ;
		}
	public :
		Student (string name , string dob , string con , int id){
			studentName = name , DOB = dob , 
			contactInfo = con ;
			while(!isValid(id)){
				cout << "Please Enter another ID for student " << name << endl ;
				cin >> id ;
			}
			studentID = id ;
			idExistStudent[id] = true ;
		}
		Student(){
		}
		int getStudentID(){
			return studentID ;
		}
		string getStudentName(){
			return studentName ;
		}
		string getDateOfBirth(){
			return DOB ;
		}
		string getContactInformation(){
			return contactInfo ;
		}
		void getDetails(){
			cout << "ID : " << studentID << endl ;
			cout << "Name : " << studentName << endl ;
			cout << "Date of birth : " << DOB << endl ;
			cout << "Contact information : " << contactInfo << endl ;
		}
		void setStudentName(string s){
			studentName = s ;
		}
		void setDateOfBirth(string s){
			DOB = s ;
		}
		void setContactInformation(string s){
			contactInfo = s ;
		}
};
