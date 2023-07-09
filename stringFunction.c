#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int mystrlen(char *p){
	char *ptr = p;
	int cnt = 0;
	while(*ptr++){
		cnt++;
	}
	return cnt;
}

char* mystrcpy(char *p,char *q){
	char *ptr = p;
	char *qtr = q;
	int i;
	int len = mystrlen(qtr);
	for(i=0;i<len;i++){
		ptr[i] = qtr[i];
	}
	ptr[i]='\0';
	return ptr;
}

int mystrcmp(char *p,char *q){
	char *ptr = p;
	char *qtr = q;
	while(*ptr){
		if(*ptr != *qtr){
			return *ptr - *qtr;
		}
		ptr++; qtr++;
	}
	return *ptr - *qtr;
}

int mycasestrcmp(char *p,char *q){
	char *ptr = p;
	char *qtr = q;
	while(*qtr){
		if(tolower(*ptr) != tolower(*qtr)){
                        return *ptr - *qtr;
                }
                ptr++; qtr++;
	}
	return *ptr - *qtr;
}

char *mystrdup(char *p,char *q){
	char *ptr = p;
	char *qtr = q;
	int len = strlen(q);

	ptr = (char *) malloc(sizeof(char) * (len+1)); //len +1 因為要放'\0'
	if(ptr == NULL){
		fprintf(stderr,"Fatal\n");
		exit(1);
	}
	mystrcpy(ptr,q);
	return ptr;
}

char *mystrstr(char *text, char *pattern){
	int i,len;
	char *ptr=text;
 	char *qtr=pattern;
	char *ptrEnd;

	len = mystrlen(pattern);

	while(*ptr){
		//確認前段//fafafa afaf無法
		for(i=0;i<len;i++){
			if(ptr[i]!=qtr[i]){
				break;
			}
		}
		if(i==len){
			return qtr;
		}
		//確認後段//fafafa fafaf無法
		if(mystrcmp(ptr,pattern)==0){
			return ptr;
		}
		ptr++;
	}
	return NULL;
}

int main(){

	char str1[20];
	char str2[20];

	scanf("%s %s",str1,str2);
	printf("strlen of str1: %d\n",mystrlen(str1));
	printf("strcmp:\n");
	if(mystrcmp(str1,str2)!=0){
		printf("not the same\n\n");
	}
	else{
		printf("same\n\n");
	}

	printf("casestrcmp:\n");
	if(mycasestrcmp(str1,str2)!=0){
                printf("not the same\n\n");
        }
        else{
                printf("same\n\n");
        }
	
	scanf("%s %s",str1,str2);
	printf("strdup:%s %s :%s\n\n",str1,str2,mystrdup(str1,str2));
	scanf("%s %s",str1,str2);
	printf("strcpy:%s %s :%s\n\n",str1,str2,mystrcpy(str1,str2));
	scanf("%s %s",str1,str2);
	if(mystrstr(str1,str2)==NULL){
		printf("strstr:none\n");
	}
	else{
		printf("strstr:%s %s :%s\n",str1,str2,mystrstr(str1,str2));
	}
} 
