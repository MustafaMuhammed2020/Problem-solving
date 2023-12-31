/***********************************************/
/* Author  : Mustafa mohammed Abdou            */
/* Date    : 12 jan 2023                       */
/* Version : V01                               */
/* Describtion : max number of zeros           */
/***********************************************/
#include <stdio.h>

int main()
{
	/* DEFINE A VARIABLE FOR THE NUMBER */
	unsigned long int Num = 0 , counter = 0 , Zeros_Counter = 0 , Max = 0;
	char Digits[32]  ;  /* HOLDS THE BINARY REPRESENTATION            */
	                    /* 32 BECAUSE THE DECIMEL IS LONG INT 32-BITS */
	
	/* SCAN THE NUMBER FROM USER */
    printf("Enter the number\n");
	scanf("%d",&Num);
	
	/* STORE THE BINARY VALUE OF THE NUMBER */
	while(Num > 0)
	{
		Digits[counter++] = Num % 2;
		Num /= 2 ;
	}
	
	/* LOOP ON THE NUMBER DIGITS */
	for(int i = 0 ; i < counter-1 ; i++)
	{
		if(Digits[i] == 1) /* WHEN DIGIT == 1 */
		{
			int z = i + 1 ;
			while(Digits[z] != 1) /* DO UNTILL LOOP FINDS ANOTHER ONE */
			{
				Zeros_Counter++ ; /* INCREASE ZEROS COUNTER */
				z++ ;             /* JUMP TO THE NEXT DIGIT */
			}	

		}
		
		/* STORE THE MAXIMUM VALUE */
		if(Zeros_Counter > Max)
		{
			Max = Zeros_Counter ;
		}
		Zeros_Counter = 0 ; /* REINITIALIZE THE ZEROS COUNTER */
	}
	
	/* DISPLAY THE MAX NUMBER OF ZEROS INCLUDED BETWEEN TWO ONES */
	printf("Max Number Of Zeros = %d\n",Max);
	
	return 0 ;
}

/************************************************************************************
MOST optimized solution 
unsigned char MaxZeros(unsigned int Num)
{
    unsigned char Digit = 0 , ZerosCounter = 0 , Digit2 = 0 , Maxzeros = 0 ;
    
    while( Num > 0 )
    {
        Digit = Num % 2 ;
        
        if( Digit == 1 )
        {
            do
            {
               Num /= 2 ; 
               
               Digit2 = Num % 2 ;
               
               if( (Digit2 == 0) && (Num > 0) )
               {
                   ZerosCounter++ ;
               }
               
            }while( (Num > 0) && ( Digit2 != 1 ));
            
            Num *= 2 ;
        }
        
        if( ZerosCounter > Maxzeros )
        {
            Maxzeros = ZerosCounter ;
        }
        
        ZerosCounter = 0 ;

        Num /= 2 ;
    }
    
    return Maxzeros ;
}

int main()
{
	unsigned int Num1 = 0 , Pwr = 0 , Sum = 0 , Iterator = 0 , Max = 0 , Min = 0 , Digit = 0 ;
	
	unsigned char Character ;
	
	Character = MaxZeros(32);
	
	printf("%d\n",Character);
	
	return 0 ;
}
***************************************************************************************************/