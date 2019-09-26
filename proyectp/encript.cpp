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


#define THREAD_NUM 4 

using namespace std;

string lectura();
char* CharArray(string texto);
vector<int> asciiarray(vector<char> char_array);
//estructura para multiples parametros
struct parameters{
	vector<char> bloc; 
	int key;
};

//--------------------MAIN---
int main()
{	
	string texto;
	texto = lectura();
	char listof;
	CharArray(texto);
	cout<<CharArray(texto)<<endl;
	//cout<<asciiarray(characters)<<endl;
  	system("pause");
  	
  
  	
  	
  	return 0;
	
}

//lectura del archivo
string lectura(){
	ifstream archivo;
	string texto;
	string totalText;
	
	archivo.open("FUENTE2.txt",ios::in);
	
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
char[] CharArray(string text){
 string s = text; 
  
    int n = s.length(); 
  
    // declaring character array 
    char char_array[n + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(char_array, s.c_str());
	return char_array;
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
	vector<char> textt = data->bloc;
	int threadID = pthread_self();
	
	
}
/*  //escritura
  ofstream myfile;
  myfile.open ("example.txt");
  myfile <<totalText;
  myfile.close();*/
