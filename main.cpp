#include <iostream>
#include "Main functions.h"
using namespace std ;
int main(){
	int choice ;
	do{
		options() ;
		cin >> choice ;
		switchPartOne(choice) ;
		endMessage() ;
	} while(cin >> choice , choice) ;
}
