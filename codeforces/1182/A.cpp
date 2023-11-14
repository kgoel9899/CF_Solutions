#include <stdio.h>
int main(void){
	int n; scanf("%d", &n);
	if(n%2==0) printf("%d", 1<<(n/2));
	else printf("0");
	return 0;
}