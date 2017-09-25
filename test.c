#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

typedef struct threadArg{
	int ts;
	char s;
}tArg;

void *funcA(void *p){
	tArg * x = (tArg *)p;
	while(1){
		printf("%s%c%s_______>%d\n","zhe shi========",x->s,"=====dfjk===",x->ts);
		//if(p)free(p);
		sleep(1);
	}
}

int main(){
	int i = 0;
	for(; i < 10 ; i++){
		pthread_t t_1;
		tArg *p = (tArg *)malloc(sizeof(tArg));
		p->s = 'x';
		p->ts = i ;
		if(pthread_create(&t_1,NULL,funcA,(void*)p)){
			printf("funcA_t create failed!\n"); 
		}
	}
	while(1){
		sleep(5);
	}
	return 0;	
}
