#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
   list<int> l = {4, 8, 15, 16}; 
   
   /// l.insert(next(l.begin(), 2), 22);
   
   l.erase(next(l.begin(), 2));
   
   for(int k: l){
      cout << k << endl;
   }
	
	return 0;
}

