#include "Array.hpp"

#include <iostream>

#define MAX_VAL 750

// Test chaques éléments ayant être du codé en amont.
// Check également la gestion de cas d'erreur.
int main(int, char**)
{
    // Création d'un array sans taille spécifique
    std::cout << "-------- TEST ZERO: Create an non sized array -------" << std::endl << std::endl;
    Array<std::string> stringArray;
    std::cout << "Size of stringArray: " << stringArray.size() << std::endl << std::endl;
    
    std::cout << "-------- TEST ONE: Create a initial sized array of 750 -------" << std::endl << std::endl;
    Array<int> numbers(MAX_VAL);
    std::cout << "Size of intArray: " << numbers.size() << std::endl << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	{
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    // Il vérifie si les tableaux mirror et numbers contiennent les mêmes valeurs.
    // Si ce n'est pas le cas, il affiche un message d'erreur et retourne 1.
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    std::cout << "-------- TEST TWO: Error: out of bounds with neg -------" << std::endl << std::endl;
    // Test les exeptions pour le hors limite:
    // Est-ce qu'une indexation négative a été backup par
    // Le code ?
	try
    {
        numbers[-2] = 0;
    }
    
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl;
    std::cout << "-------- TEST THREE: Error: out of bounds with +1 size -------" << std::endl << std::endl;
    // Tente d'acceder à l'index MAX + 1: out of bounds.
	try
    {
        numbers[MAX_VAL] = 0;
    }
    
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
