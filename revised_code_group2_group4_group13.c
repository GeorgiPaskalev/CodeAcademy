/*
Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна, с цена 180 лв на нощ, 
Стандартна -120 лв на нощ. Туристическият данък е 6%. Направете програма, която калкулира очаквана себестойност 
за клиентите в зависимост от брой нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 14 дни.
Продължение1:
▪Ако клиентът заяви повече от 5 нощувки, независимо в какви и колко стаи, получава 15% отстъпка от цената.
Продължение 2:
▪Ако клиентът направи оборот без данък повече от 700 лв за нощувки общо може да избира, дали да получи 15% отстъпка или да получи спа процедура за 100 лв.
▪След като клиентът направи своя избор, трябва да отпечатате цялото предложение на екран.
Продължение 3:
▪Ако клиентът заяви нощувки за повече от 1000 лв. общо, може да избира между:
▪20% отстъпка
▪Спа процедура на стойност 200 лв
▪2 Безплатни вечери за семейството
След като клиентът заяви своя избор, трябва да отпечатате финалната оферта на екран. 
*/

#include <stdio.h>
#include <stdlib.h>
#define SEPARATOR "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" /*Added separator formating, for better presentation*/
const float fPriceStandart = 120.00F; 
const float fPriceLux = 180.00F;
const float fDiscountFifteen = 0.85F; 
const float fDiscountTwenty = 0.80F;
const float fTouristFee = 1.06F;
const int discountNights = 5;
const int discountForValue = 700;
const int discountForValueMax = 1000; /*Added discount constants*/

/*Initialized all numerical variables to initial value of 0*/
int iNumofStandart = 0;
int iNumofLux = 0;
int iNumOfNights = 0;
float fTotalWithoutTF = 0.0F;
char *assignedBonusName;
float assignedDiscount = 1.00F;

int getChoice();
float calculateTotalWithoutTF();
float getTotal();
void printOrder();
int choiceMenu();
void makeOffer();      

int iNumOfNightsStandart = 0;
int iNumOfNightsLux = 0;
int standartNights = 0;
int luxuryNights = 0;
float iTotalStandartWithoutTF = 0.0F;
float iTotalLuxWithoutTF = 0.0F;  
int totalStandart = 0;
int totalLuxury = 0;     

int main(void){
    	printf("\nWelcome to \"The MAN`s Hotel\"(Martin Anton Nikolay)!\n");
    	printf("We offer standart rooms at price of 120 BGN and luxury rooms at price of 180 BGN.\n"); 
    	int responseMenu = choiceMenu();
    	if(responseMenu == 1 || responseMenu == 2 || responseMenu == 3){
        	makeOffer();
    	}
    	if(responseMenu == 4){
        	printf(SEPARATOR);  
        	printf("You just quit your order! Have a nice day!\n");
    	}
    	return 0;
}
/*Moved the menu logic and the offer logic, from main(), to separate functions*/
int choiceMenu(){
    	int choice;
    	while (1){  
        	printf(SEPARATOR);      
        	printf("\nFor standart room press 1,\nfor luxury room press 2,\nto proceed with order press 3,\nto quit order press 4!\n");
        	scanf("%d", &choice);
        	if(choice == 1){
            		printf(SEPARATOR);  
            		printf("\nHow many standart rooms would you like?\n");
            		scanf("%d", &iNumofStandart);
            		if(iNumofStandart == 0){
                		continue;
            		}
            			printf(SEPARATOR);  
            			printf("\nHow many nights would you stay?\n");
            			scanf("%d", &standartNights);
            			totalStandart += iNumofStandart;
            			iNumOfNightsStandart += standartNights;
            			printf("Current price: %.2f\n", calculateTotalWithoutTF());
            			printf(SEPARATOR);  
            			printf("\nIf you want to quit the whole reservation, and make new one press 0,\nif you want to quit only this room, and continue reservation press 1\nif the price is okay for you and want to countinue with this room press 2.\n");
            			scanf("%d", &choice);
                		if(choice == 0){
                    			iNumofStandart = 0;
                    			iNumofLux = 0;
                    			iNumOfNightsStandart = 0;
                    			iNumOfNightsLux = 0;
                    			continue;
                		}
				else if(choice == 1){
                    			totalStandart -= iNumofStandart;
                    			iNumOfNightsStandart -= standartNights;
                    			printf("Current price: %.2f\n", calculateTotalWithoutTF());
                    			continue;
                		}
				else{
                    			continue;
                		}
                		return 1;
        	}else if(choice == 2){
            		printf(SEPARATOR);  
            		printf("\nHow many luxury rooms would you like?(180 lv. per room for one night)\n");
            		scanf("%d", &iNumofLux);
            		if(iNumofLux == 0){
                		continue;
            		}
            			printf(SEPARATOR);  
            			printf("\nHow many nights would you stay?\n");
            			scanf("%d", &luxuryNights);
            			totalLuxury += iNumofLux;
            			iNumOfNightsLux += luxuryNights;
            			printf("Current price: %.2f\n", calculateTotalWithoutTF());
            			printf(SEPARATOR);  
            			printf("\nIf you want to quit the whole reservation, and make new one press 0,\nif you want to quit only this room, and continue reservation press 1\nif the price is okay for you and want to countinue with this room press 2.\n");
            			scanf("%d", &choice);
                		if(choice == 0){
                    			iNumofStandart = 0;
                    			iNumofLux = 0;
                    			iNumOfNightsStandart = 0;
                    			iNumOfNightsLux = 0;
                    			continue;
                		}
                		else if(choice == 1){
                    			totalLuxury -= iNumofLux;
                    			iNumOfNightsLux -= luxuryNights;
                    			printf("Current price: %.2f\n", calculateTotalWithoutTF());
                    			continue;
                		}
                		else{
                    			continue;
                		}
            			return 2;                
        	}else if(choice == 3){
            		return 3;
            		break;            
        	}
		else if(choice == 4){
            		return 4;
            		break;           
       		}
		else{
            		printf(SEPARATOR);  
            		printf("\nInvalid input! Try again!");
        	}
    	}
}

void makeOffer(){
    	iNumOfNights = iNumOfNightsStandart + iNumOfNightsLux; 
    	if(iNumOfNights >= discountNights && fTotalWithoutTF < discountForValue){
        	assignedDiscount = fDiscountFifteen;
        	assignedBonusName = "15% discount";
        	printOrder();
    	}
	else if(fTotalWithoutTF >= discountForValue && fTotalWithoutTF < discountForValueMax){
        	printf(SEPARATOR);  
        	printf("\nBecause your bill is over 700 lv. you get to choose between two discounts. \n");
        	printf("1. 15 %% discounton the bill.(press 1) \n");
       		printf("2. Spa procedures for 100lv.(press 2) \n");
        	int iChoise = getChoice(2);
        	switch (iChoise){
        		case 1:
            			assignedDiscount = fDiscountFifteen;
            			assignedBonusName = "15% discount";
            			printOrder();
            			break;

        		case 2:
            			assignedBonusName = "Spa procedures for 100lv";
            			printOrder();
            			break;
        	}
    	}else if(fTotalWithoutTF >= discountForValueMax){
        	printf(SEPARATOR "\n");  
        	printf("Because your bill is over 1000 lv. you get to choose between three discounts. \n");
        	printf("1. 20 %% discounton the bill.(press 1) \n");
        	printf("2. Spa procedures for 200lv.(press 2) \n");
        	printf("3. Two free diners.(press 3) \n");
        	int iChoise = getChoice(3);
        	switch (iChoise){
        		case 1:
            			assignedDiscount = fDiscountTwenty;
            			assignedBonusName = "20% discount";
            			printOrder();
            			break;

        		case 2:
            			assignedBonusName = "Spa procedures for 200 lv.";
            			printOrder();
            			break;
        		case 3:
            			assignedBonusName = "Two free diners";
            			printOrder();
            			break;
        	}
    	}else{
        	assignedBonusName = "no discounts";
        	printOrder();
    	}
}

int getChoice(int n){
    	int iChoise;
    	do{
        	printf(SEPARATOR "\n");  
        	printf("Please enter number from 1 to %d\n", n);
        	scanf("%d", &iChoise);
    	}
	while (iChoise < 1 || iChoise > 3);
    		return iChoise;
}

float calculateTotalWithoutTF(){
    	iTotalStandartWithoutTF = iNumofStandart * iNumOfNightsStandart * fPriceStandart;
    	iTotalLuxWithoutTF = iNumofLux * iNumOfNightsLux * fPriceLux;
    	fTotalWithoutTF = iTotalStandartWithoutTF + iTotalLuxWithoutTF;
    	return fTotalWithoutTF;
}

float getTotal(){   
    	float priceDisc = fTotalWithoutTF * assignedDiscount;
    	return priceDisc * fTouristFee;
}

void printOrder(){
    	printf(SEPARATOR "\n");  
    	printf("Your offer includes %d Standart rooms with %d nights and %d Luxury Rooms with %d nights, "
           "for the total price of %.2f lv.\n",
           totalStandart, iNumOfNightsStandart, totalLuxury, iNumOfNightsLux, getTotal());
    	printf("Assigned discount: %s \n", assignedBonusName);
    	printf("In the price there is 6 %% Tourist fee included!\n");
    	printf("The offer is valid for 14 days!\n");
    	printf("The number of your offer is %d!\n", rand());
}