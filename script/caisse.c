#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double alea(int min, int max){
	return (double)rand()/(RAND_MAX)*(max-min)+min;
}

double calcule_monnaie(double paid_amount,double montant_du){
	return paid_amount-montant_du;

}

void displayReturnedMoney(int* note_to_return,int* notes, int* coin_to_return,double* coins){
	for(int i=0;i<7;i++)
	{
		if (note_to_return[i]>0)
				printf("we need %d note(s) of Rs%d\n",note_to_return[i],notes[i]);
	}
	for(int i=0;i<7;i++)
	{
		if (coin_to_return[i]>0)
				printf("we need %d coin(s) of Rs%.2f\n",coin_to_return[i],coins[i]);
	}
}
void displayStock(int* stock_notes, int*notes, int* stock_coins, double* coins )
{
	printf("-------------Stock-----------\n");
	for(int i=0;i<7;i++)
		printf("Rs%d : %d\n",notes[i],stock_notes[i]);
	for(int i=0;i<7;i++)
		printf("Rs%.2f : %d\n",coins[i],stock_coins[i]);
	printf("-----------------------------\n");
}
int checkStock(int* stock)
{
	for(int i=0;i<7;i++){
		if(stock[i]>0)
		{
			return 0;
		}
	}
	printf("no stock\n");
	return 1;
}


void refillStock(int* stock_notes,int* stock_coins){
	for(int i=0;i<7;i++)
	{
		stock_coins[i]=10;
		stock_notes[i]=10;
	}
}
int main()
{
	int notes[7]={2000,1000,500,200,100,50,25};
	double coins[7]={20,10,5,1,0.5,0.2,0.05};
	int note_to_return[7]={0,0,0,0,0,0,0};
	int coin_to_return[7]={0,0,0,0,0,0,0};
	int stock_notes[7]={2,10,10,20,20,30,40};
	int stock_coins[7]={10,20,20,40,10,10,10};
	double paid_amount;
	srand((unsigned int)time(NULL));
	int next=1;
	while(next)
	{
		double amount_to_pay=round(alea(0,10000)*100)/100;

		printf("You have to pay: Rs%.2f\n",amount_to_pay);

		printf("Please insert money: ");
		scanf("%lf",&paid_amount);
		while(paid_amount<amount_to_pay){
			printf("Insufficient fund, please insert money: ");
			scanf("%lf",&paid_amount);
		}
		printf("You have inserted Rs.%.2f\n",paid_amount);
		double amount_to_return=calcule_monnaie(paid_amount,amount_to_pay);
		printf("I will return back Rs%.2f\n",amount_to_return);
		int no_note=0;
		int no_coin=0;
		while(amount_to_return>25 && !no_note)
		{
			for(int i=0;i<7;i++)
			{
				if(amount_to_return-notes[i]>0)
				{
					if(stock_notes[i]>0){
						amount_to_return-=notes[i];
						stock_notes[i]-=1;
						note_to_return[i]+=1;
						break;	
					}
				}
			}
			no_note=checkStock(stock_notes);
		}
		while(amount_to_return>0.05 && !no_coin)
		{
			for(int i=0;i<7;i++)
			{
				if(amount_to_return-coins[i]>0)
				{
					if(stock_coins[i]>0){
						amount_to_return-=coins[i];
						stock_coins[i]-=1;
						coin_to_return[i]+=1;
						break;
					}
				}
			}
			no_coin=checkStock(stock_coins);
		}
		if(no_coin && no_note)
		{
			int option;
			printf("there is no more money\n");
			printf("1- refill\n");
			printf("2- quit\n");
			scanf("%d",&option);
			if(option==1)
				refillStock(stock_notes,stock_coins);
			else
				next=0;

		}
		displayReturnedMoney(note_to_return,notes,coin_to_return,coins);
		displayStock(stock_notes,notes,stock_coins,coins);
	}
}