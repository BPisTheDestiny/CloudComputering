<<<<<<< HEAD
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include "sudoku.h"

char puzzle[num_of_puzzle][128];
char solution[num_of_puzzle][N+1];
int board[num_of_puzzle][N];
int spaces[num_of_puzzle][N];

int total=0;//数独总数量
int total_solved = 0;//解决数独的数目
bool (*solve)(int, int, int*, int*) = solve_sudoku_basic;//求解数独的方式
int thread_count=2;//，线程的数目，默认双线程
pthread_t* thread_handles;
long int thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int64_t now() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

void init_data() { //离线

	char *file_name=(char*)malloc(256*sizeof(char));
	FILE *fp;
	while(fgets(file_name, 256, stdin)) {

		if(file_name[0]=='\n') {
			printf("input end.start solve.please wait\n");
			break;
		}

		if(file_name[strlen(file_name)-1]=='\n')  file_name[strlen(file_name)-1]='\0';

		fp = fopen(file_name, "r");

		if(fp==NULL) {
			printf("%s does not exist.please try again\n",file_name);
			continue;
		}
		while(fgets(puzzle[total],1024,fp)) {
			// printf("%s",puzzle[total]);
			if(strlen(puzzle[total])>=N) {
				++total;
			}
		}
	}
	//printf("total:%d\n",total);
}
void* Pth_solve(void* rank) {
	long int my_rank = (long int) rank;
	int local_total= total/thread_count;
	int my_first_i = my_rank*local_total;
	int my_last_i = (my_rank==thread_count-1)?total:(my_rank+1)*local_total;

	//pthread_mutex_lock(&mutex);
	for(int i=my_first_i; i<my_last_i; ++i) {

		int nspaces = input(puzzle[i],board[i],spaces[i]);
		//printf("solution:%s\n",solution[i]);
		if(solve(0 ,nspaces, board[i],spaces[i])) {

			if (!solved(board[i]));
			//assert(0);
		} else {
			printf("i:%d;No: %s", i,puzzle[i]);
		}
		++total_solved;
		for(int j=0; j<N; ++j) {
			solution[i][j]=board[i][j]+'0';
		}
		solution[i][N]='\0';
		//printf("%s\n",solution[i]);
	}
	//pthread_mutex_unlock(&mutex);
	return NULL;
}
void cout_solution() {
	FILE *fp = fopen("outfile","w");
	for(int i=0; i<total; ++i) {
		fprintf(fp,"%s\n",solution[i]);
	}
	printf("all the solution has been output to 'outfile'\n");
}
int main(int argc, char* argv[]) {

	if(argv[1]!=NULL) thread_count = strtol(argv[1],NULL,10);//可将线程数作为参数输入

	init_neighbors();
	init_data();

	int64_t start = now();//开始计时
	thread_handles = (pthread_t *)malloc(thread_count*sizeof(pthread_t));

	for(thread=0; thread<thread_count; ++thread) {
		pthread_create(&thread_handles[thread],NULL,Pth_solve,(void*)thread);
	}

	for(thread=0; thread<thread_count; ++thread) {
		pthread_join(thread_handles[thread],NULL);
	}
	
	int64_t end = now();
	double sec = (end-start)/1000000.0;
	printf("%f sec %f ms each %d\n", sec, 1000*sec/total, total_solved);
	free(thread_handles);
	cout_solution();
}

=======
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include "sudoku.h"

char puzzle[num_of_puzzle][128];
char solution[num_of_puzzle][N+1];
int board[num_of_puzzle][N];
int spaces[num_of_puzzle][N];

int total=0;//数独总数量
int total_solved = 0;//解决数独的数目
bool (*solve)(int, int, int*, int*) = solve_sudoku_basic;//求解数独的方式
int thread_count=2;//，线程的数目，默认双线程
pthread_t* thread_handles;
long int thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int64_t now() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000 + tv.tv_usec;
}

void init_data() { //离线

	char *file_name=(char*)malloc(256*sizeof(char));
	FILE *fp;
	while(fgets(file_name, 256, stdin)) {

		if(file_name[0]=='\n') {
			printf("input end.start solve.please wait\n");
			break;
		}

		if(file_name[strlen(file_name)-1]=='\n')  file_name[strlen(file_name)-1]='\0';

		fp = fopen(file_name, "r");

		if(fp==NULL) {
			printf("%s does not exist.please try again\n",file_name);
			continue;
		}
		while(fgets(puzzle[total],1024,fp)) {
			// printf("%s",puzzle[total]);
			if(strlen(puzzle[total])>=N) {
				++total;
			}
		}
	}
	//printf("total:%d\n",total);
}
void* Pth_solve(void* rank) {
	long int my_rank = (long int) rank;
	int local_total= total/thread_count;
	int my_first_i = my_rank*local_total;
	int my_last_i = (my_rank==thread_count-1)?total:(my_rank+1)*local_total;

	//pthread_mutex_lock(&mutex);
	for(int i=my_first_i; i<my_last_i; ++i) {

		int nspaces = input(puzzle[i],board[i],spaces[i]);
		//printf("solution:%s\n",solution[i]);
		if(solve(0 ,nspaces, board[i],spaces[i])) {

			if (!solved(board[i]));
			//assert(0);
		} else {
			printf("i:%d;No: %s", i,puzzle[i]);
		}
		++total_solved;
		for(int j=0; j<N; ++j) {
			solution[i][j]=board[i][j]+'0';
		}
		solution[i][N]='\0';
		//printf("%s\n",solution[i]);
	}
	//pthread_mutex_unlock(&mutex);
	return NULL;
}
void cout_solution() {
	FILE *fp = fopen("outfile","w");
	for(int i=0; i<total; ++i) {
		fprintf(fp,"%s\n",solution[i]);
	}
	printf("all the solution has been output to 'outfile'\n");
}
int main(int argc, char* argv[]) {

	if(argv[1]!=NULL) thread_count = strtol(argv[1],NULL,10);//可将线程数作为参数输入

	init_neighbors();
	init_data();

	int64_t start = now();//开始计时
	thread_handles = (pthread_t *)malloc(thread_count*sizeof(pthread_t));

	for(thread=0; thread<thread_count; ++thread) {
		pthread_create(&thread_handles[thread],NULL,Pth_solve,(void*)thread);
	}

	for(thread=0; thread<thread_count; ++thread) {
		pthread_join(thread_handles[thread],NULL);
	}
	
	int64_t end = now();
	double sec = (end-start)/1000000.0;
	printf("%f sec %f ms each %d\n", sec, 1000*sec/total, total_solved);
	free(thread_handles);
	cout_solution();
}

>>>>>>> a538074f5f69f1e6a9c67e99ef34ed462b8107b8
