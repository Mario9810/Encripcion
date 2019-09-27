
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h> 

using namespace std; 
void testfunc(char* outStr){
  char str[10];
  for(int i=0; i < 10; ++i){
    outStr[i] = str[i];
  }
}

int main(){
  char myStr[10];
  testfunc(myStr);
  cout<<myStr;
  // myStr is now filled
}
