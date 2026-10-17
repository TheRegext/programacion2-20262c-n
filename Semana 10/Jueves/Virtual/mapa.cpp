#include <iostream>
#include <map>
using namespace std;

/***
   map <key, value>

   key: value

*/



int main() {
   map<string, int> mapa;
   
   mapa["1234"] = 44;
   mapa["AAA1"] = 14;
   mapa["4444"] = 48;
   
   
   cout << mapa["1234"] << endl;
   
   for(const pair<string, int> &par : mapa){
      cout << par.first << " " << par.second << endl;
   }
   
	
	return 0;
}

