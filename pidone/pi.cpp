#include <iostream>
#include <math.h>
#include <gmpxx.h>
#include <stdio.h>

mpf_class gregoryLeibniz(int times);
mpf_class x;

int main(){
  char str[100];
  int clo = clock();
  sprintf(str,"%62.60f\n", gregoryLeibniz(100000000));
  std::cout << str;
  std::cout << (clock()-clo)<<"\n";
  return 0;
}
mpf_class gregoryLeibniz(int times){
  mpf_class pi (128), realpi (128);
  mpf_set(pi, 0);
  mpf_set(realpi,atan(1)*4);
  for (int a =0; a<times; a++){
    mpf_add(pi,(pow(-1,a))/(2*a+1));
    if (!(a%(times/100))) {
      std::cout<<pi*4<<"\n";
      std::cout<<pi*4-realpi<<"\n";
    }
  }
  return pi*4;
}
