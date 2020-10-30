#include <iostream>

#define DISPLAY_X_BOUND 8
#define DISPLAY_Y_BOUND 8
#define NEWLINE std::cout << '\n'

class Playerdata
{
public:
	int amountOfPlayers;
	char *playerSpecificCharacters;
	int *playerPointCount;
	void intializePlayers()
	{
		playerSpecificCharacters = new char[amountOfPlayers];
		playerPointCount = new int[amountOfPlayers];
	}
};

class display
{
public:
	char displayData[DISPLAY_X_BOUND][DISPLAY_Y_BOUND];
	void clearDisplay()
	{
		for (int i = 0; i < DISPLAY_X_BOUND; i++)
		{
			for (int ii = 0; ii < DISPLAY_Y_BOUND; ii++)
			{
				displayData[i][ii] = '.';
			}
		}
	}
	void outputDisplay()
	{
		for (int i = DISPLAY_Y_BOUND - 1; i >= 0; i--)
		{
			for (int ii = 0; ii < DISPLAY_X_BOUND; ii++)
			{
				std::cout << displayData[ii][i] << ' ';
			}
			std::cout << std::endl;
		}
	}
	void setGridLine(int pos, bool direction, char playerSpecificChar)
	{
		// 1 = vertical, 0 is horizontal line
		// fills line with players' char
		if (direction == 0)
		{
			for (int i = 0; i < DISPLAY_Y_BOUND; i++)
			{
				displayData[i][pos] = playerSpecificChar;
			}
		}
		if (direction == 1)
		{
			for (int i = 0; i < DISPLAY_Y_BOUND; i++)
			{
				displayData[pos][i] = playerSpecificChar;
			}
		}
		return;
	}
	bool setGridPoint(char playerSpecificChar, int xPos, int yPos)
	{
		if (displayData[xPos][yPos] == '.')
		{
			// fill in grid
			setGridLine(xPos, 1, playerSpecificChar);
			setGridLine(yPos, 0, playerSpecificChar);

			return true;
		}
		return false;
	}
};

int main()
{
	// random stuff to make shit work
	display mainScreen;
	mainScreen.clearDisplay();
	Playerdata players;

	std::cout << "amount of players: ";
	std::cin >> players.amountOfPlayers;
	players.intializePlayers();

	int xpos, ypos;
	int currentplayer;

	for (int i = 0; i < players.amountOfPlayers; i++)
	{
		std::cout << "player number " << (i + 1) << "'s character: ";
		std::cin >> players.playerSpecificCharacters[i];
	}
	// game happens here
	while (true)
	{
		mainScreen.outputDisplay();
		std::cout << "enter x, y:\n";
		std::cin >> xpos >> ypos;
		// check boolean to see if successful point placement, ask retry until good
		mainScreen.setGridPoint(players.playerSpecificCharacters[currentplayer], xpos - 1, ypos - 1);

		// change current player
		currentplayer += 1;
		currentplayer = currentplayer % players.amountOfPlayers;
	}
}