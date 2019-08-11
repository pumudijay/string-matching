//pattern and text are hard coded

#include <stdio.h>
#include <string.h>

int* prefixKMP(char* pattern, int P, int* lps){
	
	lps[0]=0;
	int k=0;//length of longest perfect prefix
	int q=1;//travel through lps
	
	while(q<P){
		
		if(pattern[q]==pattern[k]){
			k++;
			lps[q]=k;
			q++;
		
		}
		else{
			if(k!=0){
				k=lps[k-1];
			}
			else{
				lps[q]=0;
				q++;
				
			}
		}
	}
	
	//print lps
	int i;
	printf("lps\t");
	for(i=0;i<P;i++){
		printf("%d " ,lps[i]);
	}
	return lps;
}
int KMP(char* pattern, char* text){
	
	int P=strlen(pattern);
	int T=strlen(text);
	
	int lps[P];
	
	prefixKMP(pattern,P,lps);
	
	int i=0; //travel through text
	int j=0; //travel through pattern
	
	while(i<T){
		if(pattern[j]==text[i]){
			i++;
			j++;
			
		}
		
		if(j==P){
			printf("\nFound pattern at index %d", i-j );
			j=lps[j-1];
			//printf("%d= lps[%d-1]\n",j,j);
		}
		
		else if(i<T && pattern[j]!=text[i]){
			if(j!=0){
				j=lps[j-1];
				//printf("%d= lps[%d-1]\n",j,j);
			}
			else{
				i++;
			}
		}
	}
}

int main(){
	
	char pattern[]="ABCAB";
	char text[]="ABDABCAB";
	
	KMP(pattern,text);
	return 1;
}
