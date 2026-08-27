///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;

class clsCadena{
private:
    int tam;
    char *pCadena;
public:
    clsCadena(const char *inicio);
    void Mostrar();
    ~clsCadena();
    const char *getpCadena(){return pCadena;}
    int getTam(){return tam;}
    void setpCadena(const char *p);
    bool operator==(const clsCadena &aux);///sobrecarga de operador== le asigna al operador una nueva funcionalidad

};

clsCadena::clsCadena(const char *inicio){
///vamos a pedir memoria para construir el vector dinámico
    tam=strlen(inicio)+1;
    pCadena=new char[tam];
    if(pCadena==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        exit(1);
    }
    strcpy(pCadena,inicio);///copia lo que hay en inicio en pCadena
    pCadena[tam-1]='\0';
}

void clsCadena::Mostrar(){
    cout<<pCadena<<endl;
}

void clsCadena::setpCadena(const char *p){
    delete []pCadena;
    tam=strlen(p)+1;
    pCadena=new char[tam];
    if(pCadena==nullptr){
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        exit(1);
    }
    strcpy(pCadena,p);///copia lo que hay en inicio en pCadena
    pCadena[tam-1]='\0';
}

clsCadena::~clsCadena(){
///vamos a devolver la memoria que pedimos en el constructor
    delete []pCadena;
}

bool clsCadena::operator==(const clsCadena &aux){
    if(strcmp(pCadena,aux.pCadena)==0)return true;
    return false;
}
///int strcmp(const char *cad1, const char *cad2)
///devuelve 0 si son iguales
///devuelve 1 si la primera está más lejos del inicio del diccionario que la segunda
///devuelve -1 si la primera está más cerca del inicio del diccionario que la segunda

int main(){
    clsCadena palabra("hola"),otra("Daniel Kloster Schmidt") ;

    palabra.Mostrar();
    cout<<endl;
    otra.Mostrar();

    otra.setpCadena("QUE PASARA?");
    ///cin>>otra;
    ///palabra=otra+" "+"otro texto"; se pueden hacer sobrecargando los operadores

    otra.Mostrar();
    ///if(palabra.operator==(otra))
    if(palabra==otra){
        cout<<"CADENAS IGUALES";
    }
    else{
        cout<<"CADENAS DISTINTAS";
    }
    cout<<endl;
	system("pause");
	return 0;
}
