#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 12

int main(int argc, char *argv[]) {
   int fd;
   ssize_t nread;
   long int total = 0;
   char buffer[BUFFER_SIZE];
    char word = 0;
	char lineBuffer;
	int line = 0;
	// 열기
   if ((fd = open(argv[1], O_RDONLY)) == -1) {
		printf("%s: 파일 열기 오류\n", argv[1]);
		perror(argv[1]);
   }
   
   //읽기
   while((nread = read(fd, buffer, BUFFER_SIZE))> 0) {
	   //읽은 문자수
	   total += nread;
	   
	   for(int i = 0; i < nread; i++) {
		   printf("%c\n",buffer[i]);
		   // 공백 앞을 문자로 취급
		   if(buffer[i] == (char)32) { word++; lineBuffer = 0;}
			
			// 개행
			if(buffer[i] == '\n') {
				line++; 
				word++;
			}
	    }
    }
	
	printf("문자 수: %ld\n단어 수: %d\n줄 수: %d\n", total, word + 1, line+1);
	
	close(fd);
	exit(0);
   
} 