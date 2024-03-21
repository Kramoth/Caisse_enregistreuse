#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double alea(int min, int max){
	return (double)rand()/(RAND_MAX)*(max-min)+min;
}
int main()
{
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
}