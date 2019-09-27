/*
*Universidad del Valle de Guatemala
*Mario Sarmientos 17055
*José Ovando 18071
*proyecto 2 
*Programacion de microprocesadores
*/

#include<iostream>
#include<stdlib.h> 
#include<string.h> 
#include<fstream> 
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <math.h>

#define THREAD_NUM 4 

using namespace std;


//estructura para multiples parametros
struct parameters{
	int* bloc; 
	int key;
};



//lectura del archivo
string lectura(){
	ifstream archivo;
	string texto;
	string totalText;
	
	archivo.open("HIM 05.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"No se encuentra el archivo";
		
		exit(1);
		
	}
	
	while(!archivo.eof()){
		getline(archivo,texto);
		//cout<<texto<<endl;
		
		totalText.append(texto);
			
	}
	
	archivo.close();
	return totalText;
}
// FIN LECTURA


//vector para convertir a array
int* CharArray(string texto){
  int arsize = texto.size();
  int ascii[arsize];
  int i = 0;
  int base;
  for(char c : texto){
  		base = int(c);
  		ascii[i] = base;
  		//OutStr[i] = base;
  		i++;
    }
    return  ascii; 
  }


/*vector<int> asciiarray(vector<char> char_array){
	int array_size = char_array.size();
	vector<int> ascii; 
	for(int i = 0; i<=array_size;i++){
		ascii.push_back(int(char_array[i]));
	}
	
	return ascii;
}*/

//funcion de encriptamiento 

void *encripcion(void *threadpar){
	struct  parameters *data; 
	data = (struct parameters *)threadpar;
	int key = data->key;
	int* textt = data->bloc;
	int threadID = pthread_self();
	
	
}

void checkAr(int* pass){
	for(int i =0; i<100;i++){
		cout<<pass[i]<<",";	
	}
}

void crypto(int* ascArray, int size, int key, char* encripted){
	int roundKey = key/120;
	int sqrtKey =  sqrt(roundKey);
	int tempArr[size]; 
	for(int i = 0; i <=size; i++){
		tempArr[i] = (ascArray[i] + sqrtKey);
		//cout<<tempArr[i];
	}
	
	for(int j = 0; j<=size; j++){
		encripted[j] = char(tempArr[j]);
	}


	
}

void decrypt(char* encripted, int size,int key, char* decrypted){
	int roundKey = key/120; 
	int sqrtKey = sqrt(roundKey);
	int tempArr[size];
	
	for(int i = 0; i<=size;i++){
		tempArr[i] = int(encripted[i]); 
	}
	
	for(int j = 0; j<=size; j++){
		tempArr[j] = ((tempArr[j]) - sqrtKey);
	}
	
	
	for(int z = 0; z<=size; z++){
		decrypted[z] = char(tempArr[z]);
	}
	
}

  //--------------------MAIN---
int main()
{	
	string texto;
	texto = lectura();
	int sizeOf = texto.size(); 
	int listof[sizeOf];
	int key = 1298;
	char encripted[sizeOf];
	char decrypted[sizeOf];
	//cout<<checkAr(CharArray(texto));
	//cout<<CharArray(texto)[0]<<endl;  
	//checkAr(CharArray(texto));
  	
  	
  	crypto(CharArray(texto),sizeOf,key,encripted);
  ofstream myfilx;
  myfilx.open ("encripted.txt");
  myfilx <<encripted;
  myfilx.close();
  	//cout<<encripted;
  	
	decrypt(encripted,sizeOf,key,decrypted); 
	cout<<decrypted;
	
	  //escritura
  ofstream myfile;
  myfile.open ("decrypted.txt");
  myfile <<decrypted;
  myfile.close();
  	system("pause");
  	return 0;
	
}
