#include "iter.hpp"

// Function to test the code.
void increment(int &nbr)
{
	std::cout << ++nbr << std::endl;
}

// Function 2 to test the code.
void display(std::string &msg)
{
	std::cout << msg << std::endl;
}

int main( void )
{
	int	tab[3] = {0, 1, 2};
	std::string tabStr[4] = {"Hello", "World", "Goodbye", "!"};

	std::cout << "----- test 1 -----" << std::endl;

	::iter(tab, 3, increment);

	std::cout << "----- test 2 -----" << std::endl;

	::iter(tabStr, 4, display);

	return 0;
}
