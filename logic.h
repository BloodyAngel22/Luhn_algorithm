#include <ncurses.h>
#include <array>

using namespace std;

class Luhn{
	private:

	public:
		array<int, 16> arr;
		int sum = 0;
		void fillArray();
		
		void printArr();
		void digitBypass();
		int odd(int number);
		bool checkSum();
};
