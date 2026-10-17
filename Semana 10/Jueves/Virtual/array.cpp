#include <iostream>
#include <array>
using namespace std;

int main() {
   int vecT[5];
   array<int, 5> vec = {1,2,3,4,5};
   array<int, 5> vec2;
   
      
   vec2 = vec; /// <---- 
   
   cout << vec.at(2) << endl;
   
   vec.fill(5);
   
   cout << "-----------------" << endl;
   for(int i=0; i<vec.size(); i++){
       cout << vec[i] << endl;
   }
	
	return 0;
}

