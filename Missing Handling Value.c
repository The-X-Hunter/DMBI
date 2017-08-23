#include<stdio.h>
#include<string.h>
int i,j,colIndex,rowIndex,sum=0,flag=0,count=0;
char data[4][4];	//data array
void display(){	//start of function, Function to print data array after replacing missing values
	printf("\nData matrics : \n");
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++){ //start of outer for loop
		for(j=0;j<sizeof(data[i]);j++)	//start of inner for loop
			printf("%c\t",data[i][j]);	//end of inner for loop
		printf("\n");
	}	//end of outer for loop
}	//end of function
void globalVariable(){	//start of function, Function for replacing missing value with one global character taken from user
	char ch;
	printf("\nEnter any character to replace with : ");	//Asking user to enter the global character which he/she want to replace with missing values
	scanf("%c",&ch);
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of outer for loop
		for(j=0;j<sizeof(data[i]);j++)	//start of inner for loop
			if(data[i][j]=='-')	//start of if, Finding missing values and replacing them with that global character
				data[i][j]=ch;	//end of if, inner for loop and outer for loop
	display();	//Displaying modified data array
}	//end of function
void meanColumn(){	//start of function, Function for replacing missing value with average(mean) of same column values
	flag=sum=count=0;
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++){ //start of outer for loop
		for(j=0;j<sizeof(data[i]);j++)	//start of inner for loop
			if(data[i][j]=='-'){	//strat of if, Finding first missing values and storing its column index in colIndex variable
				colIndex=j;
				flag=1;
				break;
			}	//end of if and inner for loop
		if(flag==1) //start of if
			break;	//end of if
	}	//end of outer for loop
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of for loop
		if(data[i][colIndex]!='-'){	//start of if
			sum+=data[i][colIndex]-'0';	//Taking sum of all non missing values of same column as missing value have and doing substraction with '0' to get integer value as sum is integer type variable
			count++;	//Counting number of sums we have done for getting average of sum
		}	//end of if, for loop
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of for loop
		if(data[i][colIndex]=='-')	//start of if
			data[i][colIndex]='0'+(sum/count);	//end of if and for loop, Finding average of sum and adding with '0' to convert it into ansi range
	if(flag==1)	//start of if
		meanColumn();	//end of if, The function will recursively call till all missing values are replaced
	else	//start of else
		display();	//end of else, At the end the modified data array will be printed over screen
}
void meanClass(){	//strat of function, Function for replacing missing value with average(mean) of same column and same class values
	flag=sum=count=0;
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++){	//start of outer for loop
		for(j=0;j<sizeof(data[i]);j++)	//strat of inner for loop
			if(data[i][j]=='-'){	//start of if, Finding first missing values and storing its column index in colIndex variable as well as row index in rowIndex variable
				rowIndex=i;
				colIndex=j;
				flag=1;
				break;
			}	//end of if and inner for loop
		if(flag==1)	//start of if
			break;	//end of if
	}	//end of outer for loop
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of for loop
		if((data[i][colIndex]!='-') && (data[i][sizeof(data[i])-1]==data[rowIndex][sizeof(data[i])-1])){	//start of if, Second condition will compare last column value of every row with missing value's last column value which differenciate the whole data array in some classes
			sum+=data[i][colIndex]-'0';	//Taking sum of all non missing values of same column as missing value have as well as same class as missing value have and doing substraction with '0' to get integer value as sum is integer type variable
			count++;	//Counting number of sums we have done for getting average of sum
		}	// end of if and for loop
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//strat of for loop
		if((data[i][colIndex]=='-') && (data[i][sizeof(data[i])-1]==data[rowIndex][sizeof(data[i])-1]))	//start of if, Second condition will compare last column value of every row with missing value's last column value which differenciate the whole data array in some classes
			data[i][colIndex]='0'+(sum/count);	//end of if and for loop, Finding average of sum and adding with '0' to convert it into ansi range
	if(flag==1)	//start of if
		meanClass();	//end of if, The function will recursively call till all missing values are replaced
	else //start of else
		display();	//end of else, At the end the modified data array will be printed over screen
}	//end of function
void repeated(){	//start of function, Function for replacing missing value with the value repeated most in same column
	int preCount=0;
	char max;
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++){	//start of outer for loop
		for(j=0;j<sizeof(data[i]);j++)	//start of inner for loop
			if(data[i][j]=='-'){	//start of if, Finding first missing values and storing its column index in colIndex variable
				colIndex=j;
				flag=1;
				break;
			}	//end of if and inner for loop
		if(flag==1)	//start of if
			break;	//end of if
	}	//end of outer loop
	if(flag==1){	//start of if
		flag=rowIndex=0;
		max=data[rowIndex][colIndex];	//Storing first value of same column missing value have
repeat : count=0;	//label is there
		for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of for loop
			if((data[i][colIndex]!='-') && (data[i][colIndex]==data[rowIndex][colIndex]))	//start of if, Second condition will compare perticular value of that column with all values of same column and if matched then count will be incremented
				count++; //end of if and for loop
		if(count>preCount){	//start of if, Now it will check recent count with the previos count(preCount)
			preCount=count;	//If recent count is greater than previos count then assign recent count value to previos count for comparing with count of next value of same column
			max=data[rowIndex][colIndex];	//Making current compared value maximum
			rowIndex++;	//Incrementing row index to check count for next value of same column
			goto repeat;	//Going to repeat label to repeat the same process till whole column processed
		} else {	//end of if and start of else, If count is not greater than previous count then putting previous maximum value at the position of all same column missing values
			for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of for loop
				if(data[i][colIndex]=='-')	//start of if
					data[i][colIndex]=max;	//end of if and for loop
		}	//end of else
		repeated();	//The function will recursively call till all missing values are replaced
	} else	//end of if and start of else
		display();	//end of else, At the end the modified data array will be printed over screen
}	//end of function
void main(){	//start of main
	int choice;
	printf("\nEnter data in array :\n");	//Taking values from user and storing into array
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of outer for loop, sizeof(data)/sizeof(data[i])=9/3=3
		for(j=0;j<sizeof(data[i]);j++){	//start of inner for loop, sizeof(data[i])=3
			printf("Enter data [%d][%d] : ",i,j);
			scanf("%c",&data[i][j]);
			getchar();	//Neglacting blank character during scanning
		}	//end of inner for loop and outer for loop
	for(i=0;i<(sizeof(data)/sizeof(data[i]));i++)	//start of outer for loop
		for(j=0;j<sizeof(data[i]);j++)	//start of inner for loop
			if((data[i][j]=='-') && flag==0){	//start of if, Checking for missing value represented by '-'
				flag=1;
				break;
			}	//end of if, inner for loop and outer for loop
	if(flag==1){	//start of if, After finding missing value, asking user to choose any one of four methods to resolve the missing values
		printf("\nSome values are missing from data matrics\n\nChoose any one method from below to fill up missing data :\n1. Replace with any global variable (single character)\n2. Replace with mean value of same column data\n3. Replace with mean value of same column and same group data\n4. Replace with repeated value of same column\n\nEnter choice : ");
		scanf("%d",&choice);
		getchar();	//Neglacting blank character during scanning
		switch(choice){	//start of switch
			case 1:	globalVariable();	//Function for replacing missing value with one global character taken from user
					break;
			case 2:	meanColumn();	//Function for replacing missing value with average(mean) of same column values
					break;
			case 3:	meanClass();	//Function for replacing missing value with average(mean) of same column and same class values
					break;
			case 4:	repeated();	//Function for replacing missing value with the value repeated most in same column
					break;
			default:	break;
		}	//end of switch
	}	//end of if
}	//end of main