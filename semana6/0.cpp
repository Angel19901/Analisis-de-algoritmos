#include<bits/stdc++.h>

using namespace std;

/*
  SearchNumber()
 	loop invariant: eleva un el numero 2 hasta que se mas grande que el número a buscar 
		initialization: Empieza preguntando si el numero es mayor a cero
		Maintenance:	Continua pregunando si tu numero es mayor a potencias del dos
		Termination:	Termina cuando el numero es mas pequeño que la una 
				potencia del 2
			
	Pseudocodigo: 
		SearchNumber()
		Theta(1)	preguntar si su numero es mas grande que cero
		Theta(1)	Respuesta = input()
		Theta(1)	l = 0
		Theta(1)	r = 0
		Theta(1)	i = 1
		Theta(i)	while(Repuesta  == 'y')
		Theta(i)		preguntar si sunero es mas grande que r;
		Theta(i)		Respuesta = input();
		Theta(i)		if Respuesta == 'n'
		Theta(1)			parar el for
		Theta(i)		l = r
		Theta(i)		r = 2 * r
		Theta(i)		i = i + 1
	
		Theta(log(r-l))	binSearch(l, r)

	Tiempo de ejecución: 
				elevar el 2^i >= n
				i = lg(n)
				mas complejidad de binSearch Theta( log(l - r) )

				Theta(lg(n) + lg( l - r)) Pertenece Theta(log(n))
				Complejidad: Theta(lg(n));
 */

void binSearch(unsigned long long l,unsigned long long r)
{

	char Desicion;
	unsigned long long mid;

	while(l < r)	
	{
        	
		mid=(l+r)/2;

		printf("Este es tu numero %llu? [y/n]:",mid);
		Desicion = getchar();
		getchar();

		if(Desicion == 'y')
			break;

	        if(Desicion == 'n')
		{
	
			printf("tu numero es mayor que %llu [y/n]: ",mid);
			Desicion = getchar();
			getchar();

			if(Desicion == 'y')
			{

				l = mid + 1;

			}
			else
			{

				r = mid - 1;

			}

		}

    	}

	printf("Tu numero es %d\n", mid);

}

void SearchNumber()
{

	unsigned long long l;
	unsigned long long r;

	l = 0;
	r = 2;
	
	char Desicion;

	printf("Tu numero es mas grande que 0 [y/n]: ");
	Desicion = getchar();
	getchar();

	unsigned long long i;

	i = 1;
	while(Desicion == 'y')
	{

		printf("Tu numero es mas grande que %llu [y/n]: ", r) ;
		Desicion = getchar();
		getchar();

		if(Desicion == 'n')
			break;
		l = r;
		r *= 2;
		i ++;

	}

	binSearch(l,r);

}

int main()
{

	SearchNumber();

	return 0;

}
