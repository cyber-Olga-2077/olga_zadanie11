#include <iostream>
/*ZADANIE 11*/
/*Temat: Tablice*/

//Funkcja do przykładu 11.2
int linear_search(int* haystack, int lenght, int needle) //stóg siana do przeszukania, długość tablicy(stogu) i poszukiwana igła. Tak. Tych nazw się profesjonalnie używa
{
	for (int i = 0; i < lenght; i++)	//dla każdego elementu tablicy
	{
		if (haystack[i] == needle)		//jeśli wartość elementu jest taka jak poszukiwana
		{
			return i;					//zwróć jego index
		}
	}

	return -1;							//jeśli nie pojawił się taki element zwróć -1
}

int main()
{
	bool example = true;
	if (example)
	{
		int current_example = 0;
		/*PRZYKŁAD 11.0*/
		/*Podstawowe operacje tablicowe*/
		if(current_example == 0)
		{
			int arr1[50];						//deklaracja tablicy pięćdziesięcioelementowej, wszystkie 50 elementów ma nieznane wartości

			int arr2[50]{};						//deklaracja tablicy pięćdziesięcioelementowej, wszystkie 50 elementów ma wartość 0

			int arr3[]{7, 5, 9, 432, 3};		//deklaracja tablicy pięcioelementowej której elementy to 7, 7, 9, 432, 3

			int arr4[7]{6, 2, 4};				//deklaracja tablicy siedmioelementowej której elementy to 6, 2, 4, 0, 0, 0, 0

			std::cout <<  arr4[2] << '\n';		//wypisanie elementu tablicy;

			int number = arr4[1];				//przypisanie wartości elementu tablicy do zmiennej;

			std::cout << "Wartosci tablicy 2:" << '\n';
			for (int i = 0; i < 50; i++)		//dla i równego od 0 do 50 
			{
				std::cout << arr2[i] << '\n';	//wypisanie elementu i, czyli w tym przypadku wszystkich elementów
			}

			std::cout << '\n';
			std::cout << "Wartosci tablicy 4:" << '\n';
			for (int i = 0; i < 7; i++)			//dla i równego od 0 do 6 
			{
				std::cout << arr4[i] << '\n';	//wypisanie elementu i, czyli w tym przypadku wszystkich elementów
			}

			arr4[5] = 12;						//przypisanie wartości do piątego elementu tablicy
			arr4[6] = 17655;					//przypisanie wartości do szóstego elementu tablicy
			arr4[2] *= arr4[0];					//Przypisanie drugiemu elementowi tablicy wyniku mnożenie elementu drugiego przez element zerowy

			std::cout << '\n';
			std::cout << "Wartosci tablicy 4 po zmianach:" << '\n';
			for (int i = 0; i < 7; i++)			//dla i równego od 0 do 6 
			{
				std::cout << arr4[i] << '\n';	//wypisanie elementu i, czyli w tym przypadku wszystkich elementów
			}
		}
		/*KONIEC PRZYKŁAD 11.0*/
		else if(current_example == 1)
		/*PRZYKŁAD 11.1*/
		/*Dynamiczna deklaracja tablicy*/
		{
			int input = 0;

			std::cout << "Wprowadz liczbe dodatnia:\n";
			std::cin >> input;

			if (input > 0)
			{
				int* arr = new int[input] {};		//dynamiczna deklaracja tablicy przy pomocy wskaźnika i wyzerowanie jej

				arr[input - 1] = 124;				//przypisanie wartości do ostatniego elementu tablicy

				for (int i = 0; i < input; i++)		//dla każdego elementu tablicy
				{
					std::cout << arr[i] << '\n';	//wypisanie wartości elementu tablicy
				}

				delete[] arr;						//dealokacja tablicy
			}

			//Wszystkie operacje poza deklaracją wykonywane na tablicy utworzonej dynamicznie są takie same jak na tablicy utworzonej statycznie(takiej jak w przykładzie 11.0)
			//Nie wymagają one dereferencji wskaźnika.
		}
		/*KONIEC PRZYKŁAD 11.1*/
		else if (current_example == 2)
		/*PRZYKŁAD 11.2*/
		/*Wyszukiwanie liniowe*/
		{
			//wyszukiwanie liniowe zwraca indeks pierwszego wystąpięnia danej wartości w tablicy

			int input = 0;

			std::cout << "Wprowadz liczbe dodatnia:\n";
			std::cin >> input;

			if (input > 0)
			{
				int* arr = new int[input] {};

				for (int i = 0; i < input; i++)
				{
					int input2 = 0;

					std::cout << "wprowadz wartosc elementu tablicy o indeksie " << i << '\n';
					std::cin >> input2;

					arr[i] = input2;	//przypisanie wprowadzonej wartosci do itego elementu tablicy.
				}

				int needle = 0;
				std::cout << "Wprowadz poszukiwana wartosc:\n";
				std::cin >> needle;

				int result = linear_search(arr, input, needle);

				if (result == -1)
				{
					std::cout << "Wartosc nie wystepuje w tablicy:\n";
				}
				else
				{
					std::cout << "Wartosc po raz pierwszy wystepuje na indeksie " << result << '\n';

				}

			}
		}
		/*KONIEC PRZYKŁAD 11.2*/
	}
	else
	/*ZADANIE 11*/
	//1.   Utwórz funkcję linear_search_all() typu bool;
	//1.1. Funkcja przyjmuje 5 argumentów: 
	//	   - wskaźnik na int (tablica wejściowa - stóg siana), 
	//	   - int (długość tablicy wejściowej),
	//	   - int (poszukiwany element - igła),
	//	   - wskaźnik na int (wskaźnik na tablicę wyjściową),
	//	   - referencję na int (długość tablicy wyjściowej),
	//1.2. Funkcja najpierw przeiteruje się przez całą tablicę wejściową i za każdym razem gdy trafi na poszukiwany element zrobi inkrementację (powiększenie o 1) zmiennej przechowującej długość tablicy wyjściowej
	//1.3. Jeśli w tym momencie długość uzyskana w 1.2 wynosi 0, to funkcja kończy działanie i zwraca false.
	//1.4. Następnie funkcja utworzy na wskaźniku na tablicę wyjściową tablicę o długości uzyskanej w punkcie 1.2 z użyciem: new int[nazwa_zmiennej];
	//1.5. Następnie stworzy iterator i przypisze do niego 0
	//1.6. Następnie ponownie przeiteruje się przez całą tablicę wejściową i za każdym razem gdy trafi na poszukiwany element przypisze jego indeks z tablicy wejściowej do elementu tablicy wejściowej określonego iteratorem z poprzedniego podpunktu i zrobi inkrementację tego iteratora
	//	   Na przykład: 
	//     Na początku:			   iterator = 0; i (w pętli for) = 0; wejscie[i czyli 0] != poszukiwany element.
	//	   Następne wykonanie for: iterator = 0; i = 1; wejscie[i czyli 1] == poszukiwany element; Więc wyjscie[iterator czyli 0] = i czyli 1; iterator++;
	//	   Następne wykonanie for: iterator = 1; i = 2; wejscie[i czyli 2] != poszukiwany element.
	//	   Następne wykonanie for: iterator = 1; i = 3; wejscie[i czyli 3] == poszukiwany element; Więc wyjscie[iterator czyli 1] = i czyli 3; iterator++;
	//	   Jeśli byłby to koniec pętli, to tablica wyjście miałaby dwa elementy: 1, 3
	//1.7. Funkcja kończy pracę i zwraca true. Na wskaźniku (argumencie 4) znajduje się teraz tablica zawierająca indeksy znalezionych elementow, a w zmiennej na którą wskazuje referencja (argument 5) jest teraz długość tej tablicy
	//2.   Stwórz zmienną typu int i poproś użytkownika o wprowadzenie jej wartości. Zmienna ta będzie długością tablic.
	//3.   Utwórz tablicę elementów typu int  o długości podanej przez użytkownika w punkcie 2;
	//4.   Utwórz tablicę elementów typu bool o długości podanej przez użytkownika w punkcie 2;
	//5.   Tyle razy ile wynosi długość tych tablic poproś użytkownika o kolejno wprowadzenie wieku i płci (jako 0 albo 1 (0 to mężczyzna, 1 to kobieta)) i wpisz te wartości do itych elementów odpowiednich tablic (wiek normalnie, a płeć jako false jeśli użytkownik podał 0, a true jeśli użytkownik podał 1)
	//6.   Następnie zapytaj użytkownika o podanie danego wieku i wpisz go do zmiennej;
	//7.   Utwórz wskaźnik na int i przypisz mu wartość NULL - wskaźnik ten będzie wskazywał na tablicę wyjściową z linear_search_all();
	//8.   Utwórz int i przypisz mu 0 - int ten będzie przechowywał długość tablicy wyjściowej z linear_search_all();
	//9.   Utwórz zmienną typu bool która będzie przechowywała czy linear_search_all() znalazło wyniki;
	//10.  Przypisz return z linear_search_all() do bool z punktu 9. Wywołując linear_search_all() podaj jej jako argumenty: tablicę intów z punktu 3, długość z punktu 2, poszukiwany wiek z punktu 6, wskaźnik na tablicę wyjściową z puntu 8, i długość tablicy wyjściowej z punktu 9
	//11.  Jeśli wyszukiwanie się nie powiodło (zwróciło false) to wyświetl odpowiedni komunikat i zakończ pracę programu.
	//12.  Jeśli wyszkiwanie się powiodło, przeiteruj się przez tablicę wyjściową, używając wartości każdego z jej elemntów, jako indeksu tablicy płci i wyświetlając "mezczyzna", jeśli dana wartość w tablicy płci wynosi false, lub "kobieta", jeśli wynosi true;
	//	   Na przykład jeśli:
	//	   tablica_wieku to {32, 16, 87, 41, 32}
	//	   tablica_płci  to {false, false, true, false, true}
	//	   poszukiwany_element to 32
	//     to:
	//     tablica_wyjściowa to {0, 4}
	//	   długość_tablicy_wyjściowej to 2
	//     więc program wypisze:
	//	   mezczyzna
	//     kobieta
	{

	}
	/*KONIEC ZADANIE 11*/
}