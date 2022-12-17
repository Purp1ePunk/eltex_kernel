#include "stdio.h"
#include <dlfcn.h>


int main() {
  float num;
  int action_num;
  float (*func)(float x);
  void *lib_pointer;
  
  lib_pointer = dlopen("./libtest.so", RTLD_LAZY); 
  
  if (!lib_pointer) {
  	fprintf(stderr, "dlopen() error: %s\n", dlerror());
	return 1;
	}
		
  printf("Enter a number: \n");
  scanf("%f", &num);
  printf("What should be done with number?\n");
  printf("Press 0 to find square root\n");
  printf("Press 1 to square number\n");
  scanf("%d", &action_num);

 
  if (action_num == 0) { 
    func = dlsym(lib_pointer, "sq_root");
  }

  else if (action_num == 1) {
    func = dlsym(lib_pointer, "second_power");
  }
  
  else {printf("Incorrect answer... Self-destructing... \n");}

  num = (*func)(num);
  printf("%f \n", num);

  return 0;
}
