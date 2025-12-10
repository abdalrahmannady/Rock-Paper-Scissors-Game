#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int ReadNumber(string msg , int From , int To) {
	int Number;
	do {
		cout << msg << " ";
		cin >> Number;
	} while (Number < From || Number > To);
	return Number;
}
int RandomNumber(int From, int To) {
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
struct stGamePoints {
	int Player_Points = 0;
	int Computer_Points = 0;
	int Draw_Points = 0;
};
enum enGameChoices {
	Stone = 1, Paper = 2, Scissors = 3
};
enum enRoundWinner {
	Player_Winner = 1, Computer_Winner = 2, Draw = 3
};
string MeaningOfGameChoicesEnum(enGameChoices TheChoosenOne) {
	if (TheChoosenOne == enGameChoices::Stone) {
		return "Stone";
	}
	else if (TheChoosenOne == enGameChoices::Paper) {
		return "Paper";
	}
	else {
		return "Scissors";
	}
}
int UserChoice() {
	int NumberOfChoise;
	cout << "Your choice: [1] : Stone, [2] : Paper, [3] : Scissors ? ";
	cin >> NumberOfChoise;
	return NumberOfChoise;
}
int ComputerChoice() {
	int Computer_Choice;
	Computer_Choice = RandomNumber(1, 3);
	return Computer_Choice;
}
enRoundWinner GameConditions(enGameChoices Player , enGameChoices Computer) {
	if (Player == Computer) {
		return enRoundWinner::Draw;
	}
	else if (Player == enGameChoices::Paper && Computer==enGameChoices::Stone) {
		return enRoundWinner::Player_Winner;
	}
	else if (Player == enGameChoices::Scissors && Computer == enGameChoices::Paper) {
		return enRoundWinner::Player_Winner;
	}
	else if (Player == enGameChoices::Stone && Computer == enGameChoices::Scissors) {
		return enRoundWinner::Player_Winner;
	}
	else {
		return enRoundWinner::Computer_Winner;
	}
}
void PrintingChoices(enGameChoices Player, enGameChoices Computer , enRoundWinner Winner) {
	cout << "Player 1 choice :  " << MeaningOfGameChoicesEnum(Player) << endl;
	cout << "Computer choice :  " << MeaningOfGameChoicesEnum(Computer) << endl;
	if (Winner == enRoundWinner::Player_Winner) {
		system("color 02");
		cout << "Round Winner    : " << "[Player]";
	}
	else if (Winner == enRoundWinner::Computer_Winner) {
		system("color 04");
		cout << "\a";
		cout << "Round Winner    : " << "[Computer]";
	}
	else {
		system("color 06");
		cout << "Round Winner    : " << "[No Winner]";
	}

}
stGamePoints Counting(int NumberOfRounds) {
	stGamePoints Counter;
	for (int i = 1; i <= NumberOfRounds; i++) {
		int Player = UserChoice();
		int Computer = ComputerChoice();
		enRoundWinner Winner = GameConditions((enGameChoices)Player, (enGameChoices)Computer);
		cout << "_____________Round [" << i << "]_____________\n";
		PrintingChoices((enGameChoices)Player, (enGameChoices)Computer, Winner);
		cout << "\n-----------------------------------\n";
		if (Winner == enRoundWinner::Player_Winner) {
			Counter.Player_Points++;
		}
		else if (Winner == enRoundWinner::Computer_Winner) {
			Counter.Computer_Points++;
		}
		else {
			Counter.Draw_Points++;
		}
	}
	return Counter;

}
void FinalResultBoard(int NumberOfRounds, stGamePoints Counter) {

	cout << "\n--------------------------------------------------\n";
	cout << "                 +++ Game Over +++\n";
	cout << "--------------------------------------------------\n";
	cout << "              ______[Game Result]______\n\n";
	cout << "    Game Rounds     : " << NumberOfRounds << endl;
	cout << "    Player 1 Wins   : " << Counter.Player_Points << endl;
	cout << "    Computer Wins   : " << Counter.Computer_Points << endl;
	cout << "    Draw Times      : " << Counter.Draw_Points << endl;
	if (Counter.Player_Points > Counter.Computer_Points) {
		system("color 2F");
		cout << "    Final Winner    : " << "Player 1";
	}
	else if (Counter.Player_Points < Counter.Computer_Points) {
		system("color 4F");
		cout << "\a";
		cout << "    Final Winner    : " << "Computer";

	}
	else {
		system("color 7F");
		cout << "    Final Winner    : " << "None";
	}
}
int main() {
	srand((unsigned)time(NULL));
	char CheckIfUserWannaGoAgain = 'Y';
	while (CheckIfUserWannaGoAgain == 'Y' || CheckIfUserWannaGoAgain == 'y') {
		stGamePoints GamePoints;
		int NumberFromUser = ReadNumber("How many rounds from 1 to 10" , 1 , 10);
		GamePoints = Counting(NumberFromUser);
		FinalResultBoard(NumberFromUser, GamePoints);
		cout << "\n    Do you want to play agian? Y/N ";
		cin >> CheckIfUserWannaGoAgain;
		system("color 07");

	}
	return 0;
}