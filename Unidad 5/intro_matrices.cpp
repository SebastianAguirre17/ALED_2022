#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <cstring>

using namespace std;

#define TOPEM 12
#define TOPED 31

void iniMat(int M[][TOPED], int tf, int tc){
	cout<<"ini mat"<<endl;	
	for(int f=0; f<tf; f++){
		for(int c=0; c<tc; c++){
			M[f][c]=10;
		}
	}
}

int main(){

	int vec[TOPED];
	int mat[TOPEM][TOPED];

	iniMat(mat, TOPEM, TOPED);
	
	mat[2][28]+=115;
	cout<<mat[2][28];
	
}

