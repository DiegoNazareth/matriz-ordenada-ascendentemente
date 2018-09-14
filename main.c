#include <iostream>
#include <cstdlib>

int **crearmat(int,int );
void llenarmat(int**,int,int);
void ordenar(int**, int,int);
void imprimir(int**, int,int);

using namespace std;

int main(){
	int ren,col;
	int **mat;
	ren=3;
	col=3;
	mat=crearmat(ren,col);
	llenarmat(mat,ren,col);
	ordenar(mat,ren,col);
	imprimir (mat,ren,col);	
	return 0;
}

int **crearmat(int ren,int col ){
	int **aux;
	aux=new int *[ren];
	int i;
	for(i=0;i<ren;i++){
		aux[i]=new int[col];
	}
	
	return aux;	
}

void llenarmat(int** mat,int ren,int col){
	int i,j;
	for(i=0;i<ren;i++){
		for(j=0;j<col;j++){
			cout<<endl<<"Valor para la posicion "<<"["<<i+1<<"]"<<"["<<j+1<<"] :";
			cin>>*(*(mat+i)+j);
		}
	}
}

void ordenar(int**mat, int ren,int col){
	
	int *vec;
	vec=new int[ren*col];
	int k=0;
	int i,j;
	for( i=0;i<ren;i++){	
		for( j=0;j<col;j++){
			vec[k]=mat[i][j];
			k++;	
		}
	}
	//ordenando el vector
	int aux;
	for(i=0;i<ren*col;i++){
		for(j=0;j<ren*col-1;j++){
			if(vec[j]>vec[j+1]){
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}
		}
	}
	k=0;
	for(i=0;i<ren;i++){
		for(j=0;j<col;j++){
			mat[i][j]=vec[k];
			k++;
		}
	}
	
	
	
	
}
void imprimir(int**mat, int ren,int col){
	for(int i=0;i<ren;i++){
		cout<<endl;
		for(int j=0;j<col;j++){
			cout<<mat[i][j]<<" ";
		}
	}
}
