#include "Matriz.h"
#include <vector>
using namespace std;
using std::cout;
char revisanombre();
vector<Matriz*> matrices;
int main(){
    
    int programa=1;
    cout<< "bienvenido al programa"<<  endl;
    while (programa==1){
        cout << "Que desea hacer?? \n 1) crear matriz \n 2) listar matrices \n 3) eliminar matriz \n 4) operar entre matrices \n5) salir"<< endl;
        cout << "ingrese su opcion: "<< endl;
        int opcion=0;
        cin>> opcion;
        switch (opcion){
        case 1:{
            cout << "ingrese el orden de la matriz \n1) orden 2 \n2) orden 3"<< endl;
            int orde=0;
            cin >> orde;
            int orden=0;
            if (orde==1){
                orden=2;
            }else if(orde==2){
                orden=3;
            }
            

            if (orde<1 || orde >2){
                cout << "ingreso un valor invalido: "<< endl;
                
            }else{
                char nom=' ';
                nom=revisanombre();
                        int**matr = new int*[orden];
	                    for (int i = 0;i<orden;i++){
		                    matr [i]= new int[orden];
	                    }
                        Matriz m;
                        matr=m.crear(orden);
                        matrices.push_back(new Matriz(nom,orden,0,matr));
            }
            
        }break;
        case 2:{
            if (matrices.size()==0){
                cout << "no se han agregado matrices"<< endl;
            }else{
                for (int i = 0; i < matrices.size(); i++){
                   matrices[i]->toString();
                }   
            }
            cout << ""<< endl;
            
            
                
        }break;
        case 3:{
            if (matrices.size()==0){
                cout << "no se han agregado matrices"<< endl;
            }else{
                for (int i = 0; i < matrices.size(); i++){
                    cout<< "puesto: "<< i ;
                    matrices[i]->toString();
                } 
                int posicion=0;
                cout << ""<< endl;
                cout << "ingrese la posicion de la matriz quedesea eliminar: "<< endl;
                cin>>posicion; 
                matrices.erase(matrices.begin()+posicion); 
                cout << "se elimino de forma correcta"<< endl;
            }

                

                
        }break;  
        case 4:{
            if (matrices.size()>1){
                cout << "ingrese la linea de comando que desee: "<< endl;
                cout << " de la forma A{comando}B , se agarraran los caracteres mas cercanos"<< endl;
                cout << "ingrese la linea de comando que desee: "<< endl;
                string comando="";
                cin >> comando;
                int pos=0;
                int tipo=0; // 1 suma 2 incremento 3 decre 4escalar 5 multi matriz 6 suma vect 7 multi vecto
                for (int i = 0; i < comando.size(); i++){
                    if (comando[i]=='|'){
                        pos=i;
                        tipo=1;
                        break;
                    }if ((comando[i]=='+')&&comando[i+1]=='+'){
                        pos=i;
                        tipo=2;
                        break;
                    }if ((comando[i]=='-')&&comando[i+1]=='-'){
                        pos=i;
                        tipo=3;
                        break;
                    }if(comando[i]=='>'){
                        pos=i;
                        tipo=4;
                        break;
                    }if (comando[i]=='&'){
                        pos=i;
                        tipo=5;
                        break;
                    }if(comando[i]=='+'){
                        pos=i;
                        tipo=6;
                        break;
                    }if(comando[i]=='*'){
                        pos=i;
                        tipo=7;
                        break;
                    }   
                }//fin for
                if (tipo==1){
                    char a=' ',b=' ';
                    a=comando[pos-1];
                    b=comando[pos+1];
                    int mat1=0,matb=0;
                    bool Ca =false, Cb=false;
                    for (int i = 0; i < matrices.size(); i++){
                        if (a==matrices[i]->getnombre()){
                            Ca=true;
                            mat1=i;
                        }if (b==matrices[i]->getnombre()){
                            Cb=true;
                            matb=i;
                        }
                    }
                    if ((Ca==true)&&Cb==true){
                        char nuevo=' ';
                        cout << "ingrese el nombre de la nueva matriz: "<< endl;
                        nuevo=revisanombre();
                        
                        matrices.push_back(matrices[mat1]->suma(matrices[matb],nuevo));

                    }else{
                        cout <<"no se encontro una de las matrices"<< endl;
                    }
                 //fin primer if                       
                }else if(tipo==2){//incremento
                    matrices[pos]->incremento();

                }else if(tipo==3){//decrement
                    matrices[pos]->decremento();
                }else if(tipo==4){//escalar
                    int escalar=0;
                    escalar=comando[pos-1];
                    char letra=' ';
                    letra=comando[pos+1];
                    int posmatri=0;
                    for (int i = 0; i < matrices.size(); i++){
                        if (letra==matrices[i]->getnombre()){
                            posmatri=i;
                        }
                    }
                    char nuevo=' ';
                    nuevo=revisanombre();
                    matrices.push_back(matrices[posmatri]->MultiEscalar(escalar,nuevo));
                }else if(tipo==5){//multi matrices
                    char a=' ',b=' ';
                    a=comando[pos-1];
                    b=comando[pos+1];
                    int mat1=0,matb=0;
                    bool Ca =false, Cb=false;
                    for (int i = 0; i < matrices.size(); i++){
                        if (a==matrices[i]->getnombre()){
                            Ca=true;
                            mat1=i;
                        }if (b==matrices[i]->getnombre()){
                            Cb=true;
                            matb=i;
                        }
                    }if ((Ca==true)&&Cb==true){
                        char nuevo=' ';
                        cout << "ingrese el nombre de la nueva matriz: "<< endl;
                        nuevo=revisanombre();
                        matrices.push_back(matrices[mat1]->ProEntre(matrices[matb],nuevo));

                    }else{
                        cout <<"no se encontro una de las matrices"<< endl;
                    }

                }else if(tipo==6){//suma vect
                    char a=' ',b=' ';
                    a=comando[pos-1];
                    b=comando[pos+1];
                    int mat1=0,matb=0;
                    bool Ca =false, Cb=false;
                    for (int i = 0; i < matrices.size(); i++){
                        if (a==matrices[i]->getnombre()){
                            Ca=true;
                            mat1=i;
                        }if (b==matrices[i]->getnombre()){
                            Cb=true;
                            matb=i;
                        }
                    }
                    if ((Ca==true)&&Cb==true){
                        char nuevo=' ';
                        cout << "ingrese el nombre de la nueva matriz: "<< endl;
                        nuevo=revisanombre();
                        int numero=0;
                        cout<< "ingrese el numero para la suma vectorial: ";
                        cin>> numero;
                        matrices.push_back(matrices[mat1]->sumaVecto(matrices[matb],numero,nuevo));

                    }else{
                        cout <<"no se encontro una de las matrices"<< endl;
                    }
                }else if(tipo==7){//multi vect
                    int escalar=0;
                    escalar=comando[pos-1];
                    char letra=' ';
                    letra=comando[pos+1];
                    int posmatri=0;
                    for (int i = 0; i < matrices.size(); i++){
                        if (letra==matrices[i]->getnombre()){
                            posmatri=i;
                        }
                    }
                    char nuevo=' ';
                    nuevo=revisanombre();
                    int numero=0;
                        cout<< "ingrese el numero para la multiplicacion vectorial: ";
                        cin>> numero;
                    matrices.push_back(matrices[posmatri]->multivecto(numero,nuevo));
                } 
            }else{ 
                cout << "no hay matrices suficientes para poder hacer operaciones"<< endl;
            }
        }break; 
        default:{
            cout << "ingreso un valor invalido"<< endl;
        }break;
        }//fin switch
        cout << "desea reingresar? 1) si 2)no: "<< endl;
        cin >> programa;
    }
    cout << "gracias por usar el programa"<< endl;
    return 0;
}


char revisanombre(){
    cout << "ingrese el caracter con el que desea identificar la matriz\n solo se tomara en cuenta el primer caracter que se ingrese\nde ser un numero regresara al menu: "<< endl;
    cout << "ingrese el caracter: "<< endl;
    string cadena="";
    cin>> cadena;
    char nom=' ';
    if (cadena[0]=='1'||cadena[0]=='2'||cadena[0]=='3'||cadena[0]=='4'||cadena[0]=='5'||cadena[0]=='6'||cadena[0]=='7'||cadena[0]=='8'||cadena[0]=='9'||cadena[0]=='0'){
                
    }else{
        bool nombre=false;             
        nom= cadena[0];
        for (int i = 0; i < matrices.size(); i++){
            if(nombre==matrices[i]->getnombre()){
                nombre=true;
            }
        }
        if (nombre==true){
            cout<< "el nombre esta repetido"<< endl;
                return revisanombre();
        }else{
            cout << "nombre bien ingresado";
            return nom;
        }
    }
    return nom;
}