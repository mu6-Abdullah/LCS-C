#include<stdio.h>
#include<string.h>
 
int num_arr[1000][1000],row,col; // establish global variables that can be accessed by both num_arr and character_arr
char x[1000],y[1000],character_arr[1000][1000]; // establish an array solely for each sequence
 
void print(int row,int col)
{
                if(row==0 || col==0) // if the recursive algorithm reaches the beginning edges of the matrix, end the algorithm
                                return;
                if(character_arr[row][col]=='c') // if in the character array, this position was marked
                {
                                print(row-1,col-1); // move diagonally upwards to the left
                                printf("%c",x[row-1]); // grab and print the digit that is equivalent in both the col and row
                }
                else if(character_arr[row][col]=='u') // move up a row and recursively call the function
                                print(row-1,col); // move up and recursively call the function
                else
                                print(row,col-1); // move left a col and recursively call the function
}
 
void lcs(int s1len,int s2len)
{
                
                for(row=0;row<=s1len;row++) // intialize the 0 column with all zeroes
                                num_arr[row][0]=0;
                for(row=0;row<=s2len;row++) // intialize the 0 row with all zeroes
                                num_arr[0][col]=0;
                                
                //c, u and l denotes cross, upward and downward directions respectively
                for(row=1;row<=s1len;row++) //parse through the rows
                                for(col=1;col<=s2len;col++) // parse through the columns
                                {
                                                if(x[row-1]==y[col-1]) // if the 
                                                {
                                                                num_arr[row][col]=num_arr[row-1][col-1]+1;
                                                                character_arr[row][col]='c'; // this vertex is aligns two pieces that together will make part of the subsequence
                                                }
                                                else if(num_arr[row-1][col]>=num_arr[row][col-1]) // if the piece above is greater than the piece to the left
                                                {
                                                                num_arr[row][col]=num_arr[row-1][col];
                                                                character_arr[row][col]='u'; // in the character array place a U in this position to signify upwards movement
                                                }
                                                else // if the piece to the left is greater than the piece above
                                                {
                                                                num_arr[row][col]=num_arr[row][col-1];
                                                                character_arr[row][col]='l';//in the character array place an L in this position to signify leftwards movement
                                                }
                                }
}
 
int main()
{
		int valid = -1, counter1, counter2,s1len,s2len;
		printf("To compute an LCS,\n"); // Beginning output
		while (valid == -1) { // (Boolean While Statement)
			printf("\nEnter first sequence: ");
                	scanf("%s",x); // append the string characters to an array called x
			s1len = strlen(x); // calculate the string length, from the array
			for (counter1 = 0; counter1 <s1len; counter1++){ // parse through each element in the array
				if ('0' > x[counter1] || '9' < x[counter1]){ // if any is not between 0 and 9.....
					printf("Error, non-digit character detected!" ); // Output error
					s1len = 0; // Reset the length of the string to 0					
					break; // and break out of the for loop
				}	
			}
			if (s1len == 0) // if the length is 0, likely because it broke out of the last segment, skip the next block
				continue;

			printf("\nEnter the second sequence: "); // Ask for second user input
			scanf("%s",y); // append the string characters to an array called y
			s2len = strlen(y);// get the length
			for (counter2 = 0; counter2<s2len; counter2++) {
				if ('0' > y[counter2] || '9' < y[counter2]){
					printf("Error, non-digit character detected!");
					s2len = 0;
					break;
				}
			}
			if (s1len == 0|| s2len == 0){ // Final check to see there are enough values to compute LCS
				printf("Please make sure int values are enetered into the sequence");
				continue;
			}
			else
				valid=0; // IF yes break out of the validation while loop
		}
                
                printf("\n");
                lcs(s1len,s2len); // output the LCS
                print(s1len,s2len);
		printf("\n");
		return 0;
}
