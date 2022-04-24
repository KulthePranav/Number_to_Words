//Name- Kulthe Pranav Mahesh
#include<stdio.h>
#include<string.h>
char* A[10] = { "Zero","One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine"};
char* B[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Forteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
char* C[10] = {" "," ","Twenty","Thirty","Forty","Fifty", "Sixty","Seventy","Eighty","Ninety" };
char* D[22] = {" ","Hundred", "Thousand","Million","Billion","Trillion","Quadrillion","Quintillion","Sextillion","Septillion","Octillion","Nonillion","Decillion","Undecillion","Duodecillion","Tredecillion","Quattuordecillion","Quindecillion","Sexdecillion","Septendecillion","Octodecillion","Novemdecillion" };

void no_to_words(int* triples)
{
	int i;
	if(triples[0]==0 && triples[1]==0 && triples[2]==0){}
	else if(triples[0]==0 && triples[1]==0 && triples[2]!=0)
	{
		printf("%s ",A[triples[2]]);
	}
	else if(triples[0]==0 && triples[1]!=0 && triples[2]==0)
	{
		if(triples[1]==1)
		{
			printf("%s ",B[triples[2]]);	
		}
		printf("%s ",C[triples[1]]);
	}
	else if(triples[0]==0 && triples[1]!=0 && triples[2]!=0)
	{
		if(triples[1]==1)
		{
			printf("%s ",B[triples[2]]);	
		}
		else
		{
			printf("%s ",C[triples[1]]);
			printf("%s ",A[triples[2]]);
		}
	}
	else if(triples[0]!=0 && triples[1]==0 && triples[2]==0)
	{
		printf("%s ",A[triples[0]]);
		printf("%s ",D[1]);
	}
	else if(triples[0]!=0 && triples[1]==0 && triples[2]!=0)
	{
		printf("%s ",A[triples[0]]);
		printf("%s ",D[1]);
		printf("%s ",A[triples[2]]);
	}
	else if(triples[0]!=0 && triples[1]!=0 && triples[2]==0)
	{
		printf("%s ",A[triples[0]]);
		printf("%s ",D[1]);
		if(triples[1]==1)
		{
			printf("%s ",B[triples[2]]);
		}
		printf("%s ",C[triples[1]]);
	}
	else
	{
		printf("%s ",A[triples[0]]);
		printf("%s ",D[1]);
		if(triples[1]==1)
		{
			printf("%s ",B[triples[1]]);
		}
		else
		{
			printf("%s ",C[triples[1]]);
			printf("%s ",A[triples[2]]);
		}
	}
}
void form_triplet(char* str,int n)
{
    int i,j,m;
    int triples[3];
    if(n%3==1)
    {
    	int count=(n+2)/3;
    	triples[0]=0;
        triples[1]=0;
        triples[2]=str[0]-48;
        no_to_words(triples);
        if(count>=2)
        {
        	printf("%s ",D[count]);
        	count--;
        }
        
        for(i=1;i<n;i=i+3)
        {
            int k=0;
            for(j=i;j<=i+2;j++)
            {
                triples[k]=str[j]-48;
                k++;
            }
        	no_to_words(triples);
        	if(count>=2)
        	{
        		printf("%s ",D[count]);
        		count--;
        	}
        }
    }
    else if(n%3==2)
    {
    	int count=(n+1)/3;
    	triples[0]=0;
        triples[1]=str[0]-48;
        triples[2]=str[1]-48;
        no_to_words(triples);
        if(count>=2)
        {
        	printf("%s ",D[count]);
        	count--;
        }
        for(i=2;i<n;i=i+3)
        {
            int k=0;
            for(j=i;j<=i+2;j++)
            {
                triples[k]=str[j]-48;
                k++; 
            }
        	no_to_words(triples);
        	if(count>=2)
        	{
        		printf("%s ",D[count]);
        		count--;
        	}
        }
    }
    else
    {   
    	int count=n/3;
    	for(i=0;i<n;i=i+3)
    	{
        	int k=0;
        	for(j=i;j<=i+2;j++)
        	{
            	triples[k]=str[j]-48;
            	k++;
        	}
        	no_to_words(triples);
        	if(count>=2)
        	{
        		printf("%s ",D[count]);
        		count--;
        	}
        }
    }
}
int main()
{
	char str[65];
	gets(str);
	int n=strlen(str);
	if(n<=60)
	{
		form_triplet(str,n);
	}
	else
	{
		printf("Length more than 60 is not supported\n");
		return 0;
	}
	return 0;
}
