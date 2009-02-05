/* Copyright (c) 2007-2008 Daniel Jackoway 
 *
 * Released Under the MIT License. See COPYING for details.
 */
#include <math.h>
#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void leibniz();
void circle();
void wallis();
void ramanujan(unsigned long long times);
void ramanujanNW(int times);
void ramd(int times);
void factz();
void circleD(unsigned long long size);
int inCircle(unsigned long long a, unsigned long long b, unsigned long long size);
void ramanjuanRat(unsigned long long times);
void monteCarlo(unsigned long long times);
void chudnovsky(unsigned long long times);
void newton(unsigned long long times);
void doubFactz(unsigned long long x);

mpz_t z,f;
mpf_t times, n;
mpz_t radius;

int main(){
  //mpf_inp_str(
  unsigned long long clo = clock();
  
  //printf("%lu\n",ULONG_MAX);
  //for things using mpf
  /*mpf_init2(times,1024);
  mpf_init2(n,1024);
  mpf_set_ui(times,1);//enter terms/1000
  mpf_mul_ui(times,times,100);*/

  //mpf_set_ui(times,10);//enter terms/1000
  //mpf_mul_ui(times,times,1000);
  //mpf_init2(n,1024);

  //for things using mpz
  mpz_init(radius);
  mpz_set_ui(radius,128);//enter terms/1000
  mpz_mul_ui(radius,radius,1000);
  

  //ramanujan(6400);
  //newton(16000);
  chudnovsky(6400);
  //leibniz();
  //wallis();
  //circle();
  //unsigned long long numterms = 128000;
  //circle(numterms);
  //mpz_init(z); 
  //chudnovsky(1);
  //mpz_init(z);
  //mpz_set_ui(z,1);
  //doubFactz(5);
  //printf("%d\n", mpz_get_ui(z));
  //ramd(5);
  //ramanujan(5);
  //ramanjuanRat(5);
  //mpf_init2(z,1024);
  //mpf_set_ui(z,1);
  //factz(5);
  
  //leibniz(numterms);
  /*mpf_t x;
  mpf_init2(x,1024);
  mpf_set_d(x,M_PI);
  mpf_out_str(stdout, 10, 0, x);
  printf("\n");*/
  //wallis(100000);
  
  //mpf_t x;
  //mpf_init2(x, 1024);
  //mpf_set_ui(x,100000);
  //mpf_add_ui(x, x, 3);
  //mpf_out_str(stdout,10,0,z);
  //printf("\n");
  //circle(4800);
  //circleD(100000);
  //monteCarlo(100000);
  //newton(1000);
  printf("%ld\n",(clock()-clo)/1000);
  //printf("Terms:%d\n", numterms);
  //sprintf("%e\n", M_PI);
  
  
  return 0;
}
void leibniz(){
  //  printf("runtohere\n");
  mpf_t pi, term,numer;
  mpf_init2(pi,1024);
  mpf_init2(term,1024);
  mpf_init2(numer,1024);
  mpf_set_ui(n,0);

  //int a;
  //for (a=0; a<times; a++){
  while(mpf_cmp(n,times)){
    //mpf_set_si(numer,(a%2)?(-1):(1));
    if (mpf_cmp_ui(numer,0)<=0)
      mpf_set_ui(numer,1);
    else
      mpf_set_si(numer,-1);
    //printf("run\n");
    //mpf_set_ui(term,(2*a+1));
    mpf_set(term,n);
    mpf_mul_ui(term,term,2);
    mpf_add_ui(term,term,1);
    mpf_div(term,numer,term);
    mpf_add(pi,pi,term);
    /*if (!(a%(times/100))) {
      mpf_t pi4;
      mpf_init2(pi4, 1024);
      mpf_mul_ui(pi4,pi,4);
      mpf_out_str(stdout, 10, 0, pi4);
      printf("\n");
      }*/
    //if (!(a%(times/100)))
    //printf("%d\n",a/(times/100));
    mpf_add_ui(n,n,1);
    }
  //return pi*4;
  mpf_mul_ui(pi, pi, 4);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
}
void circle(){
  mpz_t in, temp,temp2,size2,x,y;
  //in=in circle
  //temp=x^2
  //temp2=y^2
  //size2=size^2
  mpz_init2(in,1024);
  mpz_init2(temp,1024);
  mpz_init2(temp2,1024);
  mpz_init2(size2,1024);
  mpz_init2(x,1024);
  mpz_init2(y,1024);
  mpz_set(size2,radius);
  mpz_mul(size2,size2,radius);


  
  //unsigned long long x, y;
  //int f=0;//checking that the denom is right
  //x=0;
  //y=0;
  mpz_set_ui(x,0);
  mpz_set_ui(y,0);
  while (1){
    //printf("loop run\n");
    //f++;
    mpz_set(temp,x);
    mpz_mul(temp,temp,x);
    mpz_set(temp2,y);
    mpz_mul(temp2,temp2,y);
    mpz_add(temp,temp,temp2);
    
    if (mpz_cmp(temp,size2)<=0){
      mpz_add_ui(in,in,1);
      //x++;
      mpz_add_ui(x,x,1);
    }
    else{
      mpz_add_ui(y,y,1);
      //f+=(size-x);
      //y++;
      //if (size<y)
      if (mpz_cmp(y,radius)>0)
	break;
      //x=0;
      mpz_set_ui(x,0);
    }
  }
  mpf_t pi,tot;
  mpf_init2(pi,1024);
  mpf_set_z(pi,in);
  mpf_init2(tot,1024);
  mpf_set_z(tot,radius);
  mpf_add_ui(tot,tot,1);
  mpf_mul(tot,tot,tot);
  //mpz_out_str(stdout, 10, in);
  //printf("\n");
  //mpf_out_str(stdout, 10, 0, tot);
  //printf("\n");
  mpf_div(pi,pi,tot);
  mpf_mul_ui(pi,pi,4);
  //printf("Size:%d\n",size);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
  //printf("%d,%d\n",f,(size+1)*(size+1));

}
void wallis(){
  mpf_t pi, numer, term,temp;
  //mpf_div_ui(times,times,2);
  mpf_init2(pi,1024);
  mpf_init2(numer,1024);
  mpf_init2(term, 1024);
  mpf_init2(temp,1024);
  mpf_set_ui(pi,1);
  mpf_set_ui(n,1);
  //int a;
  //for (a=1; a<=times/2; a++){
  while(mpf_cmp(times,n)){
    //printf("run\n");
    mpf_set_ui(numer,2);
    mpf_mul(numer,numer,n);
    mpf_mul(numer,numer,numer);
    mpf_set(term,n);
    mpf_mul_ui(term,term,2);
    mpf_sub_ui(term,term,1);
    //mpf_set(pi,

    //mpf_mul_ui(term,term,2*a+1);
    mpf_set_ui(temp,2);
    mpf_mul(temp,temp,n);
    mpf_add_ui(temp,temp,1);
    mpf_mul(term,term,temp);
    mpf_div(term,numer,term);
    mpf_mul(pi,pi,term);
    //if (!(a%(times/200)))
    //printf("%d\n",a*2/(times/100));
    mpf_add_ui(n,n,1);
    }
  mpf_mul_ui(pi, pi, 2);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
}
void ramanujanNW(int times){
  mpf_t pi, term, mult,tmp,rpi;
  mpf_init(pi);
  mpf_init(term);
  mpf_init(mult);
  mpf_init(tmp);
  //mpf_init2(rpi,16384);
  mpf_set_prec(pi,16384);
  mpf_set_prec(term,16384);
  mpf_set_prec(mult,16384);
  mpf_set_prec(tmp,16384);
  mpf_set_ui(mult,1);
  
  double n;
  mpf_set_ui(pi,1103);
  for (n=1; n<times; n++){
    mpf_set_d(tmp,((4*n)*(4*n-1)*(4*n-2)*(4*n-3)));
    mpf_div_ui(tmp,tmp,(n*n*396*396));
    mpf_div_ui(tmp,tmp,(n*n*396*396));
    //mpf_set_d(tmp,((4*n)*(4*n-1)*(4*n-2)*(4*n-3))/(n*n*n*n*396*396*396*396));
    mpf_mul(mult,mult,tmp);
    mpf_mul_ui(term,mult,(1103+26390*n));
    mpf_add(pi,pi,term);
    //if (!((int)n%(times/100)))
    //printf("%d\n",(int)n);
    //    mpf_out_str(stdout, 10, 0, mult);
    //printf("\n");
    //mpf_set_d(tmp,(2*sqrt(2))/9801);
    //mpf_mul(rpi,rpi,tmp);
    //mpf_ui_div(rpi,1,tmp);
    //n++;
  }//while (mpf_cmp_d(rpi,M_PI)>0);
  mpf_sqrt_ui(tmp,2);
  mpf_mul_ui(tmp,tmp,2);
  mpf_div_ui(tmp,tmp,9801);
  //mpf_set_d(tmp,(2*sqrt(2))/9801);
  mpf_mul(pi,pi,tmp);
  mpf_ui_div(pi,1,pi);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
  mpf_set_d(tmp,M_PI);
  mpf_sub(tmp,pi,tmp);
  printf("delta=\n");
  mpf_out_str(stdout, 10, 0, tmp);
  printf("\n");
}
/*void ramanujan(){
  mpf_t pi,term,tmp,tmp2;
  mpf_init2(pi,1024);
  mpf_init2(term,1024);
  //mpf_init(mult);
  mpf_init2(tmp,1024);
  mpf_init2(tmp2,1024);
  mpz_init(z);
  mpz_set_ui(z,1);
  mpz_init(f);
  //mpf_init2(rpi,16384);
  //mpf_set_prec(pi,1024);
  //mpf_set_prec(term,1024);
  //mpf_set_prec(mult,16384);
  //mpf_set_prec(tmp,1024);
  //mpf_set_ui(mult,1);
  //double n;
  mpf_set_ui(pi,0);
  //mpf_out_str(stdout, 10, 0, tmp);
  //printf("\n");
  //for (n=0; n<times; n++){
  while(mpf_cmp(times,n)){
    mpf_set_ui(term,1103);
    mpf_set_ui(tmp,26390);
    mpf_mul(tmp,tmp,n);
    mpf_add(term,term,tmp);
    mpz_set_ui(z,1);
    mpz_set_f(f,n);
    mpz_mul_ui(f,f,4);
    factz();
    mpf_set_z(tmp,z);
    mpf_mul(term,term,tmp);
    mpf_set_ui(tmp,396);
    mpf_set(tmp2,n);
    mpf_mul_ui(tmp2,tmp2,4);
    mpf_pow(tmp,tmp,tmp2);
    mpf_div(term,term,tmp);
    mpz_set_ui(z,1);
    mpz_set_f(z,n);
    factz();
    mpf_set_z(tmp,z);
    mpf_pow_ui(tmp,tmp,4);
    mpf_div(term,term,tmp);
    mpf_add(pi,pi,term);
    mpf_add_ui(n,n,1);
    //mpf_out_str(stdout, 10, 0, term);
    //printf("\n");
  }//while (mpf_cmp_d(rpi,M_PI)>0);
  mpf_sqrt_ui(tmp,2);
  mpf_mul_ui(tmp,tmp,2);
  mpf_div_ui(tmp,tmp,9801);
  //mpf_set_d(tmp,(2*sqrt(2))/9801);
  mpf_mul(pi,pi,tmp);
  mpf_ui_div(pi,1,pi);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
  //mpf_set_d(tmp,M_PI);
  mpf_sub(tmp,pi,tmp);
  //printf("delta=\n");
  //mpf_out_str(stdout, 10, 0, tmp);
  printf("\n");

  mpz_set_ui(z,1);
}
void factz(){
  if (mpz_cmp_ui(f,1)&&mpz_cmp_ui(f,0))
    return;
  mpz_mul(z,z,f);
  mpz_sub_ui(f,f,1);
  factz();
  }
*/


void ramanujan(unsigned long long times){
  long long prec = 256*1024;
  mpf_t pi,term,tmp;
  mpf_init(pi);
  mpf_init(term);
  //mpf_init(mult);
  mpf_init(tmp);
  mpz_init(z);
  mpz_set_ui(z,1);
  //mpf_init2(rpi,16384);
  mpf_set_prec(pi,prec);
  mpf_set_prec(term,prec);
  //mpf_set_prec(mult,16384);
  mpf_set_prec(tmp,prec);
  //mpf_set_ui(mult,1);
  long long n;
  mpf_set_ui(pi,0);
  //mpf_out_str(stdout, 10, 0, tmp);
  //printf("\n");
  for (n=0; n<times; n++){
    mpf_set_ui(term,1103);
    mpf_set_ui(tmp,26390);
    mpf_mul_ui(tmp,tmp,n);
    mpf_add(term,term,tmp);
    mpz_set_ui(z,1);
    factz(4*n);
    mpf_set_z(tmp,z);
    mpf_mul(term,term,tmp);
    mpf_set_ui(tmp,396);
    mpf_pow_ui(tmp,tmp,4*n);
    mpf_div(term,term,tmp);
    mpz_set_ui(z,1);
    factz(n);
    mpf_set_z(tmp,z);
    mpf_pow_ui(tmp,tmp,4);
    mpf_div(term,term,tmp);
    mpf_add(pi,pi,term);
    //mpf_out_str(stdout, 10, 0, term);
    //printf("\n");
  }//while (mpf_cmp_d(rpi,M_PI)>0);
  mpf_sqrt_ui(tmp,2);
  mpf_mul_ui(tmp,tmp,2);
  mpf_div_ui(tmp,tmp,9801);
  //mpf_set_d(tmp,(2*sqrt(2))/9801);
  mpf_mul(pi,pi,tmp);
  mpf_ui_div(pi,1,pi);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
  //mpf_set_d(tmp,M_PI);
  //mpf_sub(tmp,pi,tmp);
  //printf("delta=\n");
  //mpf_out_str(stdout, 10, 0, tmp);
  //printf("\n");


  mpz_set_ui(z,1);
}

void factz(unsigned long long x){
  if (x==1||!x)
    return;
  mpz_mul_ui(z,z,x);
  factz(x-1);
}
 
void ramd(int times){
  double n,pi,term,mult,tmp;
  pi=1103;
  term=0;
  mult=1;
  tmp=0;
  for (n=1; n<times; n++){
    tmp=((4*n)*(4*n-1)*(4*n-2)*(4*n-3))/(n*n*n*n*396*396*396*396);
    mult*=tmp;
    term=mult*(1103+26390*n);
    pi+=term;
    //printf("term:%16.12g\n",term);
    //printf("mult:%16.12g\n",mult);
    }
  
  pi*=(2*sqrt(2))/9801;
  pi=1/pi;
  printf("%16g\n",pi);
}
int inCircle(unsigned long long a, unsigned long long b, unsigned long long size){
  unsigned long long c = a*a+b*b;
  return (c<=size*size);
}
void circleD(unsigned long long size){
  unsigned long long in = 0;
  unsigned long long tot = (size+1)*(size+1);
  unsigned long long x=0;
  unsigned long long y=0;
  while (1){
    if (inCircle(x,y,size)&&(x<=size)){
      in++;
      x++;
    }
    else{
      y++;
      if (y==size)
         break;
         x=0;
     }
             
   }    
   double pi = (((double)in/(double)tot)*4);
   printf("%e\n",pi);
}
void ramanjuanRat(unsigned long long times){
  mpq_t pi,term,tmp,tmp2,rpi;
  mpq_init(pi);
  mpq_init(term);
  //mpf_init(mult);
  mpq_init(tmp);
  mpz_init(z);
  mpq_init(tmp2);
  mpz_set_ui(z,1);
  //mpf_init2(rpi,16384);
  //mpf_set_prec(mult,16384);
  //mpf_set_ui(mult,1);
  double n;
  mpq_set_ui(pi,0,1);
  //mpf_out_str(stdout, 10, 0, tmp);
  //printf("\n");
  for (n=0; n<times; n++){
    mpq_set_ui(term,1103,1);
    mpq_set_ui(tmp,26390,1);
    mpq_set_ui(tmp2,n,1);
    mpq_mul(tmp,tmp,tmp2);
    mpq_canonicalize(tmp);
    //mpq_set_ui(n);
    mpq_add(term,term,tmp);
    mpq_canonicalize(term);
    factz(4*n);
    mpq_set_z(tmp,z);
    mpz_set_ui(z,1);
    mpq_mul(term,term,tmp);
    mpq_canonicalize(term);
    mpq_set_ui(tmp,396,1);
    mpq_set(tmp2,tmp);
    //mpq_pow_ui(tmp,tmp,4*n);
    int a;
    for (a=0; a<4*n; a++){
      mpq_mul(tmp,tmp,tmp2);
      //mpq_canonicalize(tmp);
    }
    mpq_div(term,term,tmp);
    mpq_canonicalize(term);
    factz(n);
    mpq_set_z(tmp,z);
    mpz_set_ui(z,1);
    //mpq_pow_ui(tmp,tmp,4);
    for (a=0; a<4; a++){
      mpq_div(term,term,tmp);
      mpq_canonicalize(term);
    }
    mpq_add(pi,pi,term);
    //mpq_out_str(stdout, 10, 0, term);
    printf("\n");
  }//while (mpf_cmp_d(rpi,M_PI)>0);
  mpf_t sq2,temp;
  mpz_t sqrt2,tentobig;
  mpf_init2(sq2,1024);
  mpf_init2(temp,1024);
  mpf_sqrt_ui(sq2,2);
  mpf_set_ui(temp,10);
  mpf_pow_ui(temp, temp, 10000);
  mpf_mul(sq2,sq2,temp);
  mpz_init(sqrt2);
  mpz_init(tentobig);
  mpz_set_f(sqrt2,sq2);
  mpz_set_f(tentobig,temp);
  mpq_set_z(tmp,sqrt2);
  mpq_set_z(tmp2,tentobig);
  mpq_div(tmp,tmp,tmp2);
  mpq_canonicalize(tmp);
  mpq_set_ui(tmp2,2,1);
  mpq_mul(tmp,tmp,tmp2);
  mpq_canonicalize(tmp);
  mpq_set_ui(tmp2,9801,1);
  mpq_div(tmp,tmp,tmp2);
  mpq_canonicalize(tmp);
  //mpf_set_d(tmp,(2*sqrt(2))/9801);
  mpq_mul(pi,pi,tmp);
  mpq_canonicalize(pi);
  mpq_inv(pi,pi);
  mpq_out_str(stdout, 10, 0, pi);
  printf("\n");
  mpq_set_d(tmp,M_PI);
  mpq_sub(tmp,pi,tmp);
  printf("delta=\n");
  mpq_out_str(stdout, 10, 0, tmp);
  printf("\n");


  mpz_set_ui(z,1);
}
void monteCarlo(unsigned long long times){
  /*
  //mpz_t in, out,size2,
  //random(
  long double in, tot;
  long x, y;
  const size=1000;
  const size2=size*size;
  printf("%d\n",size);
  in=0;
  tot=0;
  int a;
  for (a=0; a<times; a++){
    x=(rand()%(size+1));
    y=(rand()%(size+1));
    printf("%d, ",x);
    printf("%d\n",y);
    tot++;
    if ((x*x)+(y*y)<=size2);
	in++;
  }
    double pi;
    pi = in/tot;
    pi*=4;
    printf("%e\n",pi);*/
  long long x,y;
  int in=0;
  //srand(time(NULL));
  int a;
  for (a=0;a<times; a++){
    //x=pow((rand()%1000)/1000,2);
    //y=pow((rand()%1000)/1000,2);
    x=rand()%1000;
    y=rand()%1000;
    if ((x*x)+(y*y)<=1000*1000)
      in++;
  }
  printf("%e\n",((double)(in)*4)/times);
}
void chudnovsky(unsigned long long times){
  long long prec = 524288;
  mpf_t tmp,pi,term;
  mpz_init(z);
  mpf_init2(tmp,prec);
  //mpf_init2(tmp2,1024);
  mpf_init2(pi,prec);
  mpf_init2(term,prec);
  mpf_set_ui(pi,0);
  long long a;
  for (a=0; a<times; a++){
    mpf_set_ui(term,13591409);
    mpf_set_ui(tmp,545140134);
    mpf_mul_ui(tmp,tmp,a);
    mpf_add(term,term,tmp);
    mpz_set_ui(z,1);
    factz(6*a);
    mpf_set_z(tmp,z);
    mpf_mul(term,term,tmp);
    //if (a%2)
      //mpf_neg(term,term);
    mpz_set_ui(z,1);
    factz(3*a);
    mpf_set_z(tmp,z);
    mpf_div(term,term,tmp);
    mpz_set_ui(z,1);
    factz(a);
    mpf_set_z(tmp,z);
    mpf_pow_ui(tmp,tmp,3);
    mpf_div(term,term,tmp);
    mpf_set_si(tmp,-640320);
    mpf_pow_ui(tmp,tmp,3*a);
    mpf_div(term,term,tmp);
    mpf_add(pi,pi,term);
    //mpf_out_str(stdout,10,0,term);
    //printf("\n");
  }
  mpf_sqrt_ui(tmp,10005);
  mpf_mul_ui(tmp,tmp,426880);
  mpf_div(pi,tmp,pi);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
}
void doubFactz(unsigned long long x){
  if (x==1||!x)
    return;
  mpz_mul_ui(z,z,x);
  doubFactz(x-2);
}
void newton(unsigned long long times){
  mpf_t pi, term, tmp;
  mpf_init2(pi,16384);
  mpf_init2(term,16384);
  mpf_init2(tmp,16384);
  mpz_init(z);
  mpf_set_ui(pi,0);
  long long a;
  for (a=0; a<times; a++){
    //printf("started\n");
    mpz_set_ui(z,1);
    factz(a);
    mpf_set_z(term,z);
    mpz_set_ui(z,1);
    doubFactz(2*a+1);
    mpf_set_z(tmp,z);
    mpf_div(term,term,tmp);
    mpf_add(pi,pi,term);
    //printf("ended\n");
    //mpf_out_str(stdout,10,0,term);
    //printf("\n");
  }
  mpf_mul_ui(pi,pi,2);
  mpf_out_str(stdout, 10, 0, pi);
  printf("\n");
}

