// Libreria que incluye todas las librerias
#include<bits/stdc++.h>

using namespace std;

/*
  findSum()
 	loop invariant:  
		initialization: 
		Maintenance:	
		Termination:	
				
			
	Pseudocodigo:

	Theta(1)		struct Color
					Data
					Color

	Theta(1)		SortColors()
	Theta(1)			Verde <- 0;
	Theta(1)			Rojo <- 0;
	Theta(1)			Azul <- 0;
				
	Theta(1)			LEER(n)

	Theta(1)			LEER(c)

	Theta(1)			Data <- [n] //tipo de dato: estructura propia
	Theta(n)			for(i = 0 to n)
	Theta(n)				LEER(Data[ i ]->Data)
	Theta(n)				LEER(Data[ i ]->Color)

	Theta(n)				if(Data[ i ]->Color == 1)
	Theta(n)					Rojo = Rojo + 1;
	Theta(n)				else
	Theta(n)					if(Data[ i ]->Color == 2)
	Theta(n)						Verde = Verde + 1;
	Theta(n)					else
	Theta(n)						Azul = Azul + 1;

					//tipo de dato: structura propia
	Theta(1)			rojo <- [Rojo]	
	Theta(1)			verde <- [Verde]	
	Theta(1)			azul <- [Azul]

	Theta(1)			j <- 0;
	Theta(1)			k <- 0;
	Theta(1)			l <- 0;

	Theta(n)			for(int i = 0; i < n; i++)
	Theta(n)				if(Data[ i ]->Color == 1)
	Theta(n)					rojo[ j ] = Data[ i ];
	Theta(n)					j++;
	Theta(n)				else
	Theta(n)					if(Data[ i ].Color == 2)
	Theta(n)						verde[ k ] = Data[ i ];
	Theta(n)						k++;
	Theta(n)					else
	Theta(n)						azul[ l ] = Data[ i ];
	Theta(n)						l++;

	Theta(Rojo + c)			rojo <- countSort(rojo,c);
	Theta(Verde + c)			verde <- countSort(verde,c);
	Theta(Azul + c)			azul <- countSort(azul,c);
				
	Theta(Rojo)			for(i to Rojo)
	Theta(Rojo)				print(" valor %d del conjunto rojo\n",rojo[ i ].Data);

	Theta(Verde)			for(i = 0 to Verde)
	Theta(Verde)				print(" valor %d del conjunto verde\n",verde[ i ].Data);
				
	Theta(Azul)			for(i = 0 to Azul)
	Theta(Azul)				print(" valor %d del conjunto azul\n",azul[ i ].Data);

		

	Tiempo de ejecución:  seleccionamos el maximo entre Theta(max(Verde + c,Rojo + c,Azul + c, n))
		
				
				Complejidad: Theta(max(Verde + c, Rojo + c, Azul + c, n));
 */

struct color {

	int Data;
	int Color;

};

vector<struct color> countSort(vector<struct color> arr,int k)
{

    vector<struct color> B(int(arr.size()));
 
    int C[k + 1], i;

    memset(C, 0, sizeof(C));
 
    for (i = 0; i < int(arr.size()); ++i)
        ++C[arr[i].Data];
 
    for (i = 1; i <= k; ++i)
        C[i] += C[i - 1];
 
 
    for (i = int(arr.size()) - 1; i >= 0; --i)
    {
        B[C[arr[i].Data]-1] = arr[i];
        --C[arr[i].Data];
    }
     
    for (i = 0; i < int(arr.size()); ++i)
        arr[i] = B[i];

    return arr;

}

void SortColors()
{

	int n, c;
	int Verde = 0;
	int Rojo = 0;
	int Azul = 0;
	
	printf("Cual es el tamanio de tu arreglo: ");
	scanf("%d",&n);

	printf("Cual es maximo valor de cada elemento: ");
	scanf("%d",&c);

	vector<struct color> Data(n);

	printf("Llena tus arreglos: \n");
	for(int i = 0; i < n; i++)
	{

		printf("llena el valor del elemento: ");
		scanf("%d",&Data[ i ].Data);
		printf("llena el color [r = 1 /v = 2/a = 3]: ");
		scanf("%d",&Data[ i ].Color);

		if(Data[ i ].Color == 1)
			Rojo ++;
		else
		{

			if(Data[ i ].Color == 2)
				Verde ++;
			else
				Azul ++;

		}

	}

	printf("r%d v%d a%d\n",Rojo,Verde,Azul);

	vector<struct color> rojo(Rojo);	
	vector<struct color> verde(Verde);	
	vector<struct color> azul(Azul);

	int j,k,l;

	j = 0;
	k = 0;
	l = 0;

	for(int i = 0; i < n; i++)
	{

		if(Data[ i ].Color == 1)
		{
			rojo[ j ] = Data[ i ];
			j++;
		}
		else
		{

			if(Data[ i ].Color == 2)
			{
				verde[ k ] = Data[ i ];
				k++;
			}
			else
			{
				azul[ l ] = Data[ i ];
				l++;

			}

		}
	
	}

	rojo = countSort(rojo,c);
	verde = countSort(verde,c);
	azul = countSort(azul,c);
	
	printf("Arreglo ordenado por colores y por valor\n");
	for(int i = 0; i < Rojo; i++)
		printf(" valor %d del conjunto rojo\n",rojo[ i ].Data);

	for(int i = 0; i < Verde; i++)
		printf(" valor %d del conjunto verde\n",verde[ i ].Data);
	
	for(int i = 0; i < Azul; i++)
		printf(" valor %d del conjunto azul\n",azul[ i ].Data);

}

int main()
{

	SortColors();

	return 0;

}
