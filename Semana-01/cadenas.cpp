///Fecha:
///Autor:
///Comentario:

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char palabra[20], aux[20];
    cin>>palabra;
    cout<<palabra<<endl;
   ///strcpy(aux,palabra);
    palabra[4]='\0';
    cout<<palabra<<endl;
    return 0;
    cin>>aux;
    cout<<aux<<endl;
    int valorDevuelto=strcmp(aux, palabra);
    cout<<"VALOR DEVUELTO POR strcmp() "<<valorDevuelto<<endl;

	system("pause");
	return 0;

}
/*0->iguales
1->la primera es "más grande" que la segunda
-1->laprimera es "menor" que la segunda
*/
