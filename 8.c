#include <stdio.h>
#include <cstring> // otherwise when using printf for strlen, g++ ERROR: ‘strlen’ was not declared in this scope
//#include "print_array.h"
int abs(int n){
	if (n<0) return -n;
	return n;
}
// take ascii number for a number character, and convert it its real numerical value
int asciinum(char hi){
	return hi-48;
}

char *selectchars(const char *string,int start,const int howlong){
	char array[howlong+1]={0}; array[howlong]='\0';
	for(int i=0; i<howlong;++i){
		array[i]=string[start+i];
	}
	return array;
}

void debug(char *n){
	printf("\nDEBUG %s!\n",n);
}

void debug(int n){
	printf("\nDEBUG %d!\n",n);
}


char *convert_string_to_adjacent(const char *string){
	char array[1001]=""; /*array[1001]=\0;*/ int j=0; //the array containing all adjacent strings can't be longer than string's length....
	int startlen=0; //startlen is the number of adjacent numbers currently found within the string
	printf("string is actually: %s",string);
	for(int i=0;string[++i];++i){
		if(abs(string[i]-string[i+1])==1) {printf("\none with startlen: %d\n",startlen);++startlen;} else {if(startlen>=13) {printf("\n13 found!\n");strcat(array,selectchars(string,i-startlen,startlen));strcat(array,"!");} startlen=0;}
			//whenever finding a >=13 adjacent numbers string, i will concatenate it to array, separating each string with a '!' character (i'm too lazy for multi-dimensional character strings...)
	}
printf("\nThe newly sorted array is:\n%s\n",array);
printf("NOW RETURNING");
return array;
}





int main(void){
char text[1001]="7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
printf("string is %d long\n",strlen(text));

char adjacent_text[1001]="";
strcpy(adjacent_text,convert_string_to_adjacent(text)); /*adjacent_text[1000]=\0;*/ //l'ultimo carattere in una stringa e' appropriato che sia \0, in modo tale da non dover passarne sempre la grandezza.
//adjacent_text=convert_string_to_adjacent(text);
//printf("The adjacent_text is:\n%s\n",adjacent_text);

char string1[103]=""; strcat(string1,selectchars(text,7,13));
printf("\nselected string is:%s\n",string1);
	return 0;
}
