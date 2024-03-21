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
				printf("il faut %d billet(s) de Rs%d\n",billet_a_rendre[i],billets[i]);
	}
	for(int i=0;i<7;i++)
	{
		if (piece_a_rendre[i]>0)
				printf("il faut %d piece(s) de Rs%.2f\n",piece_a_rendre[i],pieces[i]);
	}
}

int main()
{
	int billets[7]={2000,1000,500,200,100,50,25};
	double pieces[7]={20,10,5,1,0.5,0.2,0.05};
	int billet_a_rendre[7]={0,0,0,0,0,0,0};
	int piece_a_rendre[7]={0,0,0,0,0,0,0};

	double montant_paye;
	srand((unsigned int)time(NULL));
	double a_payer=round(alea(0,10000)*100)/100;

	printf("Vous devez payer: Rs%.2f\n",a_payer);

	printf("Veuillez payer: ");
	scanf("%lf",&montant_paye);
	while(montant_paye<a_payer){
		printf("Attention, montant insuffisant. Veuillez payer: ");
		scanf("%lf",&montant_paye);
	}
	printf("vous avez donne Rs.%.2f\n",montant_paye);
	double a_rendre=calcule_monnaie(montant_paye,a_payer);
	printf("Je dois vous rendre Rs%.2f\n",a_rendre);

	while(a_rendre>25)
	{
		for(int i=0;i<7;i++)
		{
			if(a_rendre-billets[i]>0)
			{
				a_rendre-=billets[i];
				billet_a_rendre[i]+=1;
				break;
			}
		}

	}
	while(a_rendre>0.05)
	{
		for(int i=0;i<7;i++)
		{
			if(a_rendre-pieces[i]>0)
			{
				a_rendre-=pieces[i];
				piece_a_rendre[i]+=1;
				break;
			}
		}

	}
	displayReturnedMoney(billet_a_rendre,billets,piece_a_rendre,pieces);
/*

	for(int i=0;i<7;i++)
	{
		printf("%d",billet_a_rendre[i]);
	}
	printf("\n");

	for(int i=0;i<7;i++)
	{
		printf("%d",piece_a_rendre[i]);
	}
	printf("\n");*/
}