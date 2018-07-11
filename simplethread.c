#include <stdio.h>
#include <pthread.h>
#include <string.h>


struct data{
	int id;
	char name[64];
};
void* tafx(void *arg){
	struct data *mydata = arg;
	int myid =  mydata->id;
	char myname[64];
	strcpy (myname, mydata->name);
	printf("I am child, my id is: %d, and my name: %s\n",myid,myname);
	return NULL;
}
void tbfx(void *arg){
	struct data *mydata = arg;
	int myid = mydata->id;
	char myname[64];
	strcpy (myname,mydata->name);
	printf("I am child, my id is: %d, and my name: %s\n",myid,myname);
	return NULL;
}
int main(){
	
	pthread_t ta, tb;//pthread_t is an object //declaration
	struct data tadata, tbdata;
	tadata.id = 12;
	tbdata.id = 69;
	strcpy(tadata.name,"ADAM");
	strcpy(tbdata.name,"BOB");

	if(pthread_create(&ta,NULL,&tafx,&tadata)!=0){//it is imported from <pthread.h>
		printf("Error creating thread ta\n");
	}
	if(pthread_create(&tb,NULL,&tbfx,&tbdata)!=0){
		printf("Error creating thread tb\n");
	}

	pthread_join(ta, NULL);
	pthread_join(tb, NULL);
	return 0;
}
