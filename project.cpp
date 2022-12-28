
//PLAY AND ENJOY......

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include<iomanip> //this library is needed for setw
using namespace std;

void GuessGame();
void PlayGuessGame(int amount_bet, int* inhand_cash);
void RockPaperScissor();
int PlayRPS(char you, char computer);
void about();
void changecol();



int main(){
cout<<"\n========================================================================================================================================================================\n";
	cout << setw(100);
    cout<<"--- Welcome To Our Project ---"<<endl;
cout<<"\n========================================================================================================================================================================\n";
cout<< setw(105);
cout<<"--- Just Choose And Play,Best Of Luck ---"<<endl;
				cout << "\n\nLoading.";
				for (int i = 0; i <= 158; i++)
				{
					Sleep(40);
					cout << ".";
				}
                cout<<"\n";
    system("COLOR 2F");
    int choice;
    while(1){
        cout << "\n\n----- MAIN MENU -----";
			cout << "\n1. Guess Game";
			cout << "\n2. Rock Paper Scissor";
			cout << "\n3. Change Program Colour";
			cout << "\n4. About";
			cout << "\n5. Exit Program";

			cout << "\nEnter your choice (1-5) : ";
			cin >> choice;
            switch (choice)
			{
			case 1:
				GuessGame();
				break;
			case 2:
				RockPaperScissor();
				break;
			case 3:
			changecol();
				break;
			case 4:
				about();
				break;
			case 5:
				Sleep(500);
				cout << "\n\nExiting..";
				for (int i = 0; i <= 4; i++)
				{
					Sleep(500);
					cout << ".";
				}
				exit(0);
				break;
			default:
				cout << "\n....Invalid Choice....";
			}
		}
	
    return 0;
}



void changecol(){
	cout<<"\n\nPress The Numbers(1-5) And Change Colour";
	cout<<"\n1.Yellow \n2.Pink \n3.Aqua \n4.Green \n5.White";
	cout<<"\nChoose Colour: ";
	int col;
    cin>>col;
    if(col==1){
        system("COLOR 6F"); //yellow
    }
    else if(col==2){
        system("COLOR 4F");// red
    }
    else if(col==3){
        system("COLOR 3F"); //aqua
    }
    else if(col==4){
        system("COLOR 2F"); //green
    }
    else if(col==5){
        system("COLOR F0"); //white
    }
    else{
        cout<<"Try Again.";
    }
}



void GuessGame(){
    	int amount_bet, inhand_cash;
                // Sleep(500);
				cout<< "\n\nGame is Starting....";
				for (int i = 0; i <= 4; i++)
				{
					Sleep(500);
					cout<<".";
				}
    cout<<"\n";
    cout<<"\n----The inhand cash you have right now = 10 ,Play Wisely---- : \n";
    inhand_cash=10;

	while (inhand_cash > 0) {
		char ask1;
		cout<<"\nEnter the amount bet you want to play for : ";
		// cout<<"\n";
		cin>>amount_bet;
		if (inhand_cash == 0 || amount_bet > inhand_cash)
			break;
		PlayGuessGame(amount_bet, &inhand_cash);
		cout<<"\nDo You Want to Play Again,Press Y: ";
		cin>>ask1;
		if(!(ask1=='Y'|| ask1=='y')){
			return;
		}
	}

	if (inhand_cash == 0 || amount_bet > inhand_cash) {
		cout<<"\nSorry you don't have enough cash to play more, ";
		cout<<"Do come next time\n";
		cout<<"Thank You for playing  \n";
	}
}


void PlayGuessGame(int amount_bet, int* inhand_cash)
{
	char Hole[3] = { 'N', 'R', 'N' };
	cout<<"\nWait !! Rat is shuffling its position...\n";
	srand((time(NULL)));
	int i, x, y, temp;

	/*Swapping the Rat's (R's) position five times using
	the random number for random index*/

	for (i = 0; i < 5; i++) {
		x = rand() % 3;
		y = rand() % 3;
		temp = Hole[x];
		Hole[x] = Hole[y];
		Hole[y] = temp;
	}

	int PlayerGuess;

	cout<<"\nYou may now guess the hole(1,2,3) in which Rat is present: ";

	cin>>PlayerGuess;

	if (Hole[PlayerGuess - 1] == 'R') {
		(*inhand_cash) += 2 * amount_bet;
		cout<<"You win ! The holes are as follows: ";
		cout<<" "<<" "<<Hole[0]<<" "<<Hole[1]<<" "<<Hole[2];
		cout<<"\nYour inhand_cash is now = "<<*inhand_cash<<" \n";
	}

	else {
		(*inhand_cash) -= amount_bet;
		cout<<"You Lose ! The holes are as follows: ";
		cout<<" "<<Hole[0]<<" "<<Hole[1]<<" "<<Hole[2];
		cout<<"\nYour inhand_cash is now = "<< *inhand_cash <<" \n";
	}
}




void RockPaperScissor(){

  cout<< "\n\nGame is Starting...";
				for (int i = 0; i <= 5; i++)
				{
					Sleep(500);
					cout<<".";
				}

    char ask='y';
    while(ask=='y'||ask=='Y'){
	// Stores the random number
	int n;

	char you, computer, result;

	// Chooses the random number
	// every time
	srand(time(NULL));

	// Make the random number less
	// than 100, divided it by 100
	n = rand() % 100;

	if (n < 33)

		computer = 'r';

	else if (n > 33 && n < 66)

		computer = 'p';

	else
		computer = 'z';


        cout<<"\n\nEnter r for ROCK, p for PAPER and z for SCISSOR: ";
        cin>>you;
	// play the game
	result = PlayRPS(you, computer);

	if (result == -1) {
		cout<<"\nGame Draw!\n";
	}
	else if(result == 404){
		cout<<"You Entered Some Wrong Value. Try Again";
	}
	else if (result == 1) {
		cout<<"\nWow! You have won the game!\n";
	}
	else {
		cout<<"\nOh! You have lost the game!\n";
	}
		cout<<"You choose : "<<you<<" and Computer choose : "<<computer;

        cout<<"\nDo You Want To Play Again(Press Y/N)....? " ;
        cin >> ask;
    }
}


int PlayRPS(char you, char computer)
{
	// If both the user and computer
	// has chose the same thing
	if (you == computer){
		return -1;
	}

	// If user's choice is stone and
	// computer's choice is paper
	if (you == 'r' && computer == 'p'){
		return 0;
	}
	// If user's choice is paper and
	// computer's choice is stone
	else if (you == 'p' && computer == 'r') {return 1;}

	// If user's choice is stone and
	// computer's choice is scissor
	if (you == 'r' && computer == 'z'){
		return 1;
	}
	// If user's choice is scissor and
	// computer's choice is stone
	else if (you == 'z' && computer == 'r'){
		return 0;
	}
	// If user's choice is paper and
	// computer's choice is scissor
	if (you == 'p' && computer == 'z'){
		return 0;
	}
	// If user's choice is scissor and
	// computer's choice is paper
	else if (you == 'z' && computer == 'p'){
		return 1;
	}
	else{
		cout<<"Something Wrong.\n";
		cout<<"You Entered Some Wrong Value. Try Again.";
		return 404;
	}
}




void about()
{
	fstream about_out("about_project.txt", ios::in);
	char about_str[1000];
	cout << "\n\n==========================================================================================\n\n";
	about_out.seekg(0, ios::beg);
	while (about_out.getline(about_str, 1000))
	{
		cout << about_str << endl;
	}
	cout << "\n==========================================================================================\n";
	about_out.close();
}
