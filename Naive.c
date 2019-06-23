//user input of text
#include <stdio.h>
#include <string.h>

int main()
{
	char text[100];
	char pattern[100];
	
	printf("Enter the text:");
	scanf("%s",text);
	
	printf("Enter the pattern:");
	scanf("%s",pattern);
	
	int n=strlen(text);
	int m=strlen(pattern);

	int i,j;

	for(i=0;i<n-m;i++){

		j=0;
		while(j<m && (text[i+j]==pattern[j])){
		
			j++;
			if(j==m){
				
				printf("sub-string index:%d",i);
				return i;
			}
		}
	}
	printf("there is no sub-string of text matching");
	return 0;
}
