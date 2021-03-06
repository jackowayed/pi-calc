#include <iostream>
#include <math.h>
//#include <gmpxx.h>
#include <stdio.h>

double gregoryLeibniz(int times);

int main(){
  char str[100];
  int clo = clock();
  sprintf(str,"%62.60f\n", gregoryLeibniz(100000000));
  std::cout << str;
  std::cout << (clock()-clo)<<"\n";
  return 0;
}
double gregoryLeibniz(int times){
  double pi, oldpi, realpi;
  pi=0;
  oldpi=0;
  realpi=atan(1)*4;
  for (int a =0; a<times; a++){
    pi+=(pow(-1,a))/(2*a+1);
    if (!(a%(times/100))) {
      std::cout<<pi*4<<"\n";
      std::cout<<pi*4-realpi<<"\n";
    }
    if (pi==oldpi){
      std::cout << a <<"\n";
      break;
    }
    oldpi=pi;
  }
  return pi*4;
}
