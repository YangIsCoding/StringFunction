#include <stdio.h>

#include <ctype.h>
char *myscanf(char *text,char *aWord){
	char *ptr = text;
	char *qtr = aWord;
	while(*ptr!='\0' && isspace(*ptr)){
		ptr++;
	}
	while(*ptr!='\0' && !isspace(*ptr)){
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(qtr - aWord == 0){
		return NULL; 	
	}
	return ptr;
}
int main(){
	char input[1000];
	char word[100];
	char *ptr;
	while(fgets(input,1000,stdin)){
		ptr = input;
		while(ptr = myscanf(ptr,word)){
			printf("%s\n",word);	
		}
	}
}
