#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> vec;
   
   vec.push_back(2);
   vec.push_back(9);
   vec.push_back(15);
   
   cout << "-----------------" << endl;
   for(const auto &num : vec){
      /// num = 5;
      cout << num << endl;
   }
   
   cout << "-----------------" << endl;
   for(int i=0; i<vec.size(); i++){
      cout << vec[i] << endl;
   }
   
   
	
	return 0;
}

