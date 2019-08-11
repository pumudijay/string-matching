#include <stdio.h>
#include <string.h>
#define MAXCHAR 256


int maximum(int data1, int data2){
	
	if(data1>data2)
		return data1;
	return data2;
}

void badCharacterHeuristic(char* pattern, int badCharacter[MAXCHAR]){
	
	int n=strlen(pattern);	
	
	int i;						//initialize to -1
	for(i=0;i<MAXCHAR; i++){
		badCharacter[i]=-1;
	}
	for(i=0;i<n;i++){
		badCharacter[(int) pattern[i]]=i;	 //set position of character in array
	}
}

void searchPattern(char* mainString, char* pattern, int* array, int* index){
	
	int patLen=strlen(pattern);
	int strLen=strlen(mainString);
	
	int badCharacter[MAXCHAR];	//array for bad character position
	
	badCharacterHeuristic(pattern, badCharacter); 	//fill bad character array
	
	int shift = 0;
	
	while(shift <= (strLen-patLen)){
		
		int j =patLen-1;	//matching from right of pattern
		
		while(j>=0 && pattern[j] == mainString[shift+j]){
			j--;	//reduce j when pattern and main string character is matching
		}
		
		if(j<0){
			(*index)++;
			array[(*index)] = shift;
			
			if((shift + patLen) < strLen){
				shift+= patLen-badCharacter[mainString[shift+patLen]];

			}
			else{
				shift+=1;
			}
		}
		else{
			shift += maximum(1,j-badCharacter[mainString[shift+j]]);
		}
	}
}

int main(){
	
	char mainString[] = "ABAAABCDBBABCDDEBCABC";
	char pattern[] = "ABC";
	
	int m=strlen(mainString);
	int array[m];
	int index=-1;
	searchPattern(mainString, pattern, array, &index);
	
	int i;
	for (i=0;i<index;i++){
		printf("pattern found at location: %d \n" ,array[i]);
	}
}
