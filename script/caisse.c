#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double alea(int min, int max){
	return (double)rand()/(RAND_MAX)*(max-min)+min;
}

double calcule_monnaie(double montant_paye,double montant_du){
	return montant_paye-montant_du;

}

void displayReturnedMoney(int* billet_a_rendre,int* billets, int* piece_a_rendre,double* pieces){
	for(int i=0;i<7;i++)
	{
		if (billet_a_rendre[i]>0)
				printf("we need %d note(s) of Rs%d\n",billet_a_rendre[i],billets[i]);
	}
	for(int i=0;i<7;i++)
	{
		if (piece_a_rendre[i]>0)
				printf("we need %d coin(s) of Rs%.2f\n",piece_a_rendre[i],pieces[i]);
	}
}
void displayStock(int* stock_billets, int*billets, int* stock_pieces, double* pieces )
{
	printf("-------------Stock-----------\n");
	for(int i=0;i<7;i++)
		printf("Rs%d : %d\n",billets[i],stock_billets[i]);
	for(int i=0;i<7;i++)
		printf("Rs%.2f : %d\n",pieces[i],stock_pieces[i]);
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


void refillStock(int* stock_billets,int* stock_pieces){
	for(int i=0;i<7;i++)
	{
		stock_pieces[i]=10;
		stock_billets[i]=10;
	}
}
int main()
{
	int billets[7]={2000,1000,500,200,100,50,25};
	double pieces[7]={20,10,5,1,0.5,0.2,0.05};
	int billet_a_rendre[7]={0,0,0,0,0,0,0};
	int piece_a_rendre[7]={0,0,0,0,0,0,0};
	int stock_billets[7]={2,10,10,20,20,30,40};
	int stock_pieces[7]={10,20,20,40,10,10,10};
	double montant_paye;
	srand((unsigned int)time(NULL));
	int next=1;
	while(next)
	{
		double a_payer=round(alea(0,10000)*100)/100;

		printf("You have to pay: Rs%.2f\n",a_payer);

		printf("Please insert money: ");
		scanf("%lf",&montant_paye);
		while(montant_paye<a_payer){
			printf("Insufficient fund, please insert money: ");
			scanf("%lf",&montant_paye);
		}
		printf("You have inserted Rs.%.2f\n",montant_paye);
		double a_rendre=calcule_monnaie(montant_paye,a_payer);
		printf("I will return back Rs%.2f\n",a_rendre);
		int no_billet=0;
		int no_piece=0;
		while(a_rendre>25 && !no_billet)
		{
			for(int i=0;i<7;i++)
			{
				if(a_rendre-billets[i]>0)
				{
					if(stock_billets[i]>0){
						a_rendre-=billets[i];
						stock_billets[i]-=1;
						billet_a_rendre[i]+=1;
						break;	
					}
				}
			}
			no_billet=checkStock(stock_billets);
		}
		while(a_rendre>0.05 && !no_piece)
		{
			for(int i=0;i<7;i++)
			{
				if(a_rendre-pieces[i]>0)
				{
					if(stock_pieces[i]>0){
						a_rendre-=pieces[i];
						stock_pieces[i]-=1;
						piece_a_rendre[i]+=1;
						break;
					}
				}
			}
			no_piece=checkStock(stock_pieces);
		}
		if(no_piece && no_billet)
		{
			int option;
			printf("there is no more money\n");
			printf("1- refill\n");
			printf("2- quit\n");
			scanf("%d",&option);
			if(option==1)
				refillStock(stock_billets,stock_pieces);
			else
				exit(0);

		}
		displayReturnedMoney(billet_a_rendre,billets,piece_a_rendre,pieces);
		displayStock(stock_billets,billets,stock_pieces,pieces);
	}
}