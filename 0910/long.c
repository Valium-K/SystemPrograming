#include <stdio.h>
#define MAXLINE 100
char line[MAXLINE];
char longest[MAXLINE];

void copy(char from[], char to[]) {
	int i =0;

	while((to[i] = from[i]) != '\0') ++i;
}

int main() {
	int len;
	int max = 0;

	while(fgets(line) != NULL) {
		len = strlen(line);
		if (len > max) {
			max = len;
			copy(line, longest);
		}
	}
	if(max > 0) printf("%s", longest);

	return 0;
}