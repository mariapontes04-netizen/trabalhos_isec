#include <stdio.h>
int f(int x){
 if(x<=1)
 return x;
 else if(x%2 == 0){
 printf("%d\t", x);
 return f(x/2);
 }
 else
 return x + f(x / 3);
}
int main() {
 printf("%d\n", f(13));
 return 0;
}
