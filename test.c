#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>

typedef struct threadArg{
	int tid;
	char s;
	int tx;
}tArg;

void *funcA(void *p){
	tArg * x = (tArg *)p;
	
	int i = 0;
	for(;i < 5 ; i++){
		
		printf("线程%d第%d次执行！其中tx为:%d。s字符为：%s%c%s。\n",x->tid,i,x->tx,"=======",x->s,"======");
		//if(p)free(p);
		x->tx = 123400 + x->tid;
		sleep(1);
	}
	return (void *)x;
}

int main(){
	int i = 0;
	
	for(; i < 10 ; i++){
		pthread_t t_1; 
		tArg *p = (tArg *)malloc(sizeof(tArg));
		p->s = 'x';
		p->tid = i ;
		if(pthread_create(&t_1,NULL,funcA,(void*)p)){
			printf("funcA_t create failed!\n"); 
		}
		//tArg *sdf = NULL;
		//pthread_join(t_1,(void **)&sdf);
		//printf("wo huo zhe chu lai la!=============> %d\n",sdf->tx);
	}
	pthread_exit(NULL);
	//while(1){
	//	sleep(5);
	//}
	//return 0;	
}
