#include "Matriz.h"

Matriz::Matriz(){

}
Matriz::Matriz(char nom ,int orden,int deter,int** matr){
nombre=nom;
this->orden=orden;
determin=deter;
matriz=matr;

}
int** Matriz::crear(int ord){
	matriz = new int*[ord];
	for (int i = 0;i<ord;i++){
		matriz[i]= new int[ord];
	}
    int random=0;
    for (int i = 0; i < ord; i++){
        for (int j = 0; j < ord; j++){
            cout << "ingrese el valor de la amtriz en la posicion: "<<"i: "<<i << " j: "<<j<< endl;        
            cin >>random;
            matriz[i][j]=random;
        }
    }
    return matriz;
}
int Matriz::determinante(){
    if(orden==2){
        determin =(matriz[0][0]*matriz[1][1])+(matriz[1][0]*matriz[0][1]);
    }else{
        determin =((matriz[0][0]*matriz[1][1]*matriz[2][2])+(matriz[0][1]*matriz[1][2]*matriz[2][0])+(matriz[1][0]*matriz[2][1]*matriz[0][2]))-((matriz[2][0]*matriz[1][1]*matriz[0][2])+(matriz[1][0]*matriz[0][1]*matriz[2][2])+(matriz[2][1]*matriz[1][2])*matriz[0][0]);
    }
return determin;
}
int** Matriz::Traspuesta(){
    int** matri=NULL;
    matri = new int*[orden];
	for (int i = 0;i<orden;i++){
		matri[i]= new int[orden];
	}
    for (int i = 0; i < orden; i++){
        for (int j = 0; j < orden; j++){
            matri[i][j]=matri[j][i];
        }
        
    }
    return matri;
}
int** Matriz::getMatriz(){
    return matriz;
}
int Matriz::getOrden(){
    return orden;
}
Matriz* Matriz ::suma( Matriz* B,char nom){
    int** matri=NULL;
    int** matrib=B->getMatriz();
    matri = new int*[orden];
	for (int i = 0;i<orden;i++){
		matri[i]= new int[orden];
	}
    for (int i = 0; i < orden; i++){
        for (int j = 0; j < orden; j++){
            matri[i][j]=matriz[i][j]+(matrib[i][j]);
        }   
    }
    Matriz* mat = new Matriz(nom,orden,0,matri);
    return  mat;
}
void Matriz::incremento(){
    int deter=determinante();
    int orden= getOrden();
    int valor= deter-orden;
    if(valor>-1){
        
    }else{
        valor=valor*-1;
    }
    for (int i = 0; i < orden; i++){
        for (int j = 0; j < orden; j++){
            matriz[i][j]=matriz[i][j]+valor;
        }
        
    }
    
}
void Matriz::decremento(){
    int deter=determinante();
    int orden= getOrden();
    int valor= deter-orden;
    if(valor>-1){
        
    }else{
        valor=valor*-1;
    }
    for (int i = 0; i < orden; i++){
        for (int j = 0; j < orden; j++){
            matriz[i][j]=matriz[i][j]-valor;
        }
        
    }
}
Matriz* Matriz::MultiEscalar(int numer,char nom){
    int** matri=NULL;
    matri = new int*[orden];
	for (int i = 0;i<orden;i++){
		matri[i]= new int[orden];
	}
    for (int i = 0; i < orden; i++){
        for (int j = 0; j < orden; j++){
            matri[i][j]=matriz[i][j]*numer;
        }
        
    }
    Matriz* mat = new Matriz(nom,orden,0,matri);
    return mat;
}
Matriz* Matriz ::ProEntre(Matriz* B,char nom){
    int** matri=NULL;
    matri = new int*[orden];
	for (int i = 0;i<orden;i++){
		matri[i]= new int[orden];
	}
    if (orden ==2){
    
        // casilla [0][0]
        matri[0][0]=(matriz[0][0]*B->getMatriz()[0][0])+(matriz[0][1]*B->getMatriz()[1][0]);
        //cadilla [0][1]    
        matri[0][1]=(matriz[0][0]*B->getMatriz()[0][1])+(matriz[0][1]*B->getMatriz()[1][1]);
        //casilla [1][0]
        matri[1][0]=(matriz[1][0]*B->getMatriz()[0][0])+(matriz[1][1]*B->getMatriz()[1][0]);
        //casilla [1][1]
        matri[1][1]=(matriz[1][0]*B->getMatriz()[0][1])+(matriz[1][1]*B->getMatriz()[1][1]);
    }else{
        for(int i=0;i<3;i++){ 
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    matri[i][j]=0;
                    matri[i][j]=matri[i][j]+(matriz[i][k]*B->getMatriz()[k][j]);
                }
            }
        }
    }
    Matriz* mat = new Matriz(nom,orden,0,matri);
    return mat;
    
}
Matriz* Matriz::sumaVecto(Matriz* B,int num,char nom){
    int** matri=NULL;
    matri = new int*[orden];
	for (int i = 0;i<orden;i++){
		matri[i]= new int[orden];
	}
    if (orden==2){
        matri[0][0]=num*(matriz[0][0]-B->getMatriz()[0][0]);
        matri[1][1]=num*(matriz[1][1]-B->getMatriz()[1][1]);
        matri[0][1]=matriz[0][1]+B->getMatriz()[0][1];
        matri[1][0]=matriz[1][0]+B->getMatriz()[1][0];
    }else{//orden 3
        matri[0][0]=num*(matriz[0][0]-B->getMatriz()[0][0]);
        matri[1][1]=num*(matriz[1][1]-B->getMatriz()[1][1]);
        matri[2][2]=num*(matriz[2][2]-B->getMatriz()[2][2]);
        matri[0][1]=matriz[0][1]+B->getMatriz()[0][1];
        matri[1][0]=matriz[1][0]+B->getMatriz()[1][0];
        matri[0][2]=matriz[0][2]+B->getMatriz()[0][2];
        matri[2][0]=matriz[2][0]+B->getMatriz()[2][0];
        matri[1][2]=matriz[1][2]+B->getMatriz()[1][2];
        matri[2][1]=matriz[2][1]+B->getMatriz()[2][1];
    }
    Matriz* mat = new Matriz(nom,orden,0,matri);
    return mat;
}
Matriz* Matriz::multivecto(int num,char nom){
    int deter=0;
    int** trans=NULL;
    trans = new int*[orden];
	for (int i = 0;i<orden;i++){
		trans[i]= new int[orden];
	}
    trans=Traspuesta();
    deter=determinante();
    int valor=deter/num;
    for (int i = 0; i < orden; i++){
        for (int j = 0; j < orden; j++){
            trans[i][j]=trans[i][j]*valor;
        }
    }
    Matriz* mat = new Matriz(nom,orden,0,trans);
    return mat;
}
Matriz ::~Matriz(){
    for(int i = 0; i < orden; i++)
    free(matriz[i]);

free(matriz);
}
void Matriz::toString(){
    cout <<"nombre: " << nombre << " orden: "<< orden;
    

}
char Matriz::getnombre(){
    return nombre;
}