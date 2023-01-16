#include <stdio.h>
#include <string.h> 

int main() {
	char word[1000001];
	scanf("%[^\n]s", word);
	char* ptr = strtok(word, " ");
	int n = 0;
	while (ptr != NULL)               
	{   
		ptr = strtok(NULL, " ");
		n++;
	}
	printf("%d", n);
	return 0;
}