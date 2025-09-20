#include<stdio.h>
 int fact(int num){
    
    if(num == 0)
    return 1;
    else
    return num * fact(num-1);

 }


int main(){
    int num;
    printf("Enter the number for which you wanna generate the factorial\n");
    scanf("%d",&num);

  if(num<0)
  printf("The factorial on negative doesn't exist");
  else
  printf("Factorial of %d is %d",num,fact(num));
  
    return 0;
}
