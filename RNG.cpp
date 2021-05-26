#include <iostream>
#include <random>
#include <Windows.h>

int main()
{
	/*
		This array is of type int because GetKeyState()
		takes in an integer
	*/
	int keys[] = {
		
		/*
			Letters
		*/
		'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L',
		'M', 'N', 'O', 'P', 'Q', 'R',
		'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z',
		
		/*
			Numbers
		*/

		'1', '2', '3', '4', '5', '6',
		'7', '8', '9', '0',
		
		/*
			Special characters
		*/

		'-', '_', '=', '+', '!', '"',
		'£', '$', '%', '@', '^', '&',
		'*', '(', ')', '[', ']', '{',
		'}', ';', ':', '/', '?', '.',
		',', '.', '<', '>', '|', '\\',
		'\''
	};
	/*
		% num makes the rand() function generate a number 
		between 0 and num-1
	*/
	int num1;

	std::cout << "ENTERING LOOP\nPress any key to generate a number\n\n------------------------------------------------------------------------------------------\n\n";
	
	/*
		While the user is not pressing escape
	*/
	while (!(GetKeyState(VK_ESCAPE) & 0x8000)) {
		/*
			Loop through all the elements of the 
				int keys
			array
		*/
		for (int i = 0; i < sizeof(keys) / sizeof(char); i++) {
			/*
				If the user presses the current button
			*/
			if (GetKeyState(i) & 0x8000) {
				/*
					Generate random number
				*/
				num1 = rand() % 100;
				std::cout << num1 << "\n";
				/*
					Sleep a fifth of a second so that we don't spam numbers
				*/
				Sleep(200);
			}
		}
	}

	std::cout << "CLOSING\n";
	/*
		No error so return exit code 0
	*/
	return 0;
}