#include "stdio.h"

extern float second_power(float x);
extern float sq_root(float x);

int main() {
  float num;
  int action_num;

  printf("Enter a number: \n");
  scanf("%f", &num);
  printf("What should be done with number?\n");
  printf("Press 0 to find square root\n");
  printf("Press 1 to square number\n");
  scanf("%d", &action_num);

  if (action_num == 0) {
    num = sq_root(num);
    printf("%f \n", num);
  }

  else if (action_num == 1) {
    num = second_power(num);
    printf("%f \n", num);
  }

  else {printf("Incorrect answer... Self-destructing... \n");}

  return 0;
}
