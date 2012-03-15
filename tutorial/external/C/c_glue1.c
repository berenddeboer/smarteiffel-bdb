/* Hand-written C code to be used with example1.e */

#include <stdio.h>

void integer2c(int i){
  printf("%d\n",i);
}

void character2c(char c){
  printf("'%c'\n",c);
}

void boolean2c(int b){
  printf("%d\n",b);
}

void real2c(float r){
  printf("%f\n",r);
}

void double2c(double d){
  printf("%f\n",d);
}

void string_storage2c(char *s){
  printf("%s",s);
}

void any2c(void *a){
  if (a == NULL) {
    printf("NULL\n");
  }
  else {
    printf("not NULL\n");
  }
}

int c_int2eiffel(void){
  return -6;
}

char c_char2eiffel(void){
  return '\n';
}


void set_integer_attribute(int*attribute){
  *attribute=2;
}

int hello(void) {
  printf("Hello");
  return 1;
}
