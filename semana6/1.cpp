// Libreria que incluye todas las librerias
#include<bits/stdc++.h>

using namespace std;

/*
  findSum()
 	loop invariant: asigna el valor a busacr en el arreglo B si lo encuentra lo imprime junto el valor del 
			arreglo A y la suma que debe dar para cada elemento en A
		initialization: Asigna el lelemnto a buscar, lo busca y los imprime en caso de encontrarlo
		Maintenance:	hace lo mismo de inicializacion para elemnto en A
		Termination:	Termina despues de pasar por cada elemento en A
				
			
	Pseudocodigo: 
		
	Theta(1)	LEER(x)
	Theta(1)	LEER(a)
	Theta(1)	A <- [a]
	Theta(a)	for(i = 0 to a)
	Theta(a)		LEER(A[ i ])

	Theta(1)	LEER(b)
	Theta(1)	B <- [b]
	Theta(b)	for(i = 0 to  b)
	Theta(b)		LEER(B[ i ])

	Theta(alg(a))	sort(A.begin(),A.end());
	Theta(blg(b))	sort(B.begin(),B.end());

	Theta(a)	for(i = 0 to a)
	Theta(a)		toSearch <- x - A[ i ];
	Theta(alg(b))		Finded <- binary_search(B.begin(),B.end(),toSearch);
	Theta(a)		if( Finded )
	Theta(a)			printf("Este es el elemento en A %d y elemento en B %d, cuya suma es igual %d\n",A[ i ], toSearch, x);
	

	Tiempo de ejecución:  El ordenamiento es nlg(n) la busqueda binaria es nlg(n)
				
				Complejidad: Theta(max(a,b)lg(max(a,b)));
 */

					/*
					   libreria: #include <vector>
					   	vector estructura de datos mejora las funciones un array inyendo metodos 
						para agregar elementos de manera dinamica, para saber doned inicia, donde termina
						etc ...
					 */

void findSum()
{

	int x, a, b;
	printf("Dame el valor al que debe ser igual a la suma: ");
	scanf("%d",&x);

	printf("Dame el tamanio del arreglo A: ");
	scanf("%d",&a);
	vector<int> A(a,0);
	printf("llena el arreglo A \n");
	for(int i = 0; i < a; i++)
	{

		printf("Posicion A[ %d ]: ", i + 1);
		scanf("%d",&A[ i ]);

	}

	printf("Dame el tamanio del arreglo B: ");
	scanf("%d",&b);
	vector<int> B(b,0);
	printf("llena el arreglo B\n");
	for(int i = 0; i < b; i++)
	{

		printf("Posicion B[ %d ]: ", i + 1);
		scanf("%d",&B[ i ]);

	}

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	for(int i = 0; i < a; i++)
	{

		int toSearch = x - A[ i ];
		//binary_search incluida en la libreria #include <algorithm>
		bool Finded = binary_search(B.begin(),B.end(),toSearch);
		if( Finded )
			printf("Este es el elemento en A %d y elemento en B %d, cuya suma es igual %d\n",A[ i ], toSearch, x);

	}
	
}

int main()
{

	findSum();

	return 0;

}
