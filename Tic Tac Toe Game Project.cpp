#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include<limits>

using namespace std;

char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

void show_board();
void get_computer_choice();
void get_x_player_choice();
void get_o_player_choice();
int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();
void welcome();
char IQ();



void menu()
{




    int mode;
    //__________________________________________________TIC TAC TOE GAME__________________________________________________


    //___________________________________________________ Select Game Mode _______________________________________________
    do {
        system("Color CF");
        cout << "\n\t\t\t\t" << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "\t\t\t\t" << setw(3) << "*" << setw(44) << "*" << endl;
        cout << "\t\t\t\t" << setw(5) << "*" << "\t  WELCOME TO TIC TAC TOE GAME" << setw(8) << "*" << endl;
        cout << "\t\t\t\t" << setw(3) << "*" << setw(44) << "*" << endl;
        cout << "\t\t\t\t" << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "\n\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;
        cout << "\t\t\t\t" << setw(11) << "*" << setw(28) << "*" << endl;
        cout << "\t\t\t\t" << setw(13) << "*" << "\tSELECT GAME MODE" << setw(5) << "*" << endl;
        cout << "\t\t\t\t" << setw(11) << "*" << setw(28) << "*" << endl;
        cout << "\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;
        cout << "\n\t\t\t\t\t\t1.Computer VS Player." << endl;
        cout << "\t\t\t\t\t\t2.Player VS Player." << endl;
        cout << "\t\t\t\t\t\t3.Exit the game. " <<endl;
        cout << "\n\t\t\t\t\t\tEnter your Choice ";
        cin >> mode;

        if (cin.fail()) {

            cin.clear(); 										 			//Clearing  the error of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");			// Ignore any remaining characters in the input buffer
            continue;
            cout << "\n\t\t\t\aInvalid choice. Please try again." << endl;


        }
        switch (mode) {
        case 1:
            computer_vs_player();
            break;
        case 2:
            player_vs_player();
            break;
        case 3:
        	exit(0);
        	break;
        default:
            system("cls");
            cout << "Please Select Valid Game mode." << endl;
            break;

        }
    } while (mode != 1 && mode != 2);
}
//_______________________________________________Computer VS Player____________________________________________________

void computer_vs_player()
{
    char player_turn;

    while (true)
    {
        system("cls");
        show_board();

        if (count_board('X') == count_board('O'))
        {
            cout << player_turn << "Player's Turn." << endl;
            get_x_player_choice();
        }
        else
        {
            get_computer_choice();
        }

        char winner = check_winner();

        if (winner == 'X')
        {
            system("cls");
            show_board();
            cout << player_turn << " You Won The Game." << endl;
            cout<<"Press any key to continue game."<<endl;
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            show_board();
            cout << "Computer Won The Game." << endl;
            cout<<"Press any key to continue game."<<endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "Game is Draw." << endl;
            cout<<"Press any key to continue game."<<endl;
            break;
        }
    }
}

//________________________________________________ Computer's Choice _________________________________________________

void get_computer_choice()
{
    srand(time(0));
    int choice;

    do
    {
        choice = rand() % 9;
    } while (board[choice] != ' ');

    board[choice] = 'O';
}

//______________________________________________ X Player's Choice ___________________________________________________

void get_x_player_choice()
{
    while (true)
    {
        cout << "Please Select Valid Position (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if (cin.fail()) {

            cin.clear(); 										 			//Clearing  the error of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");			// Ignore any remaining characters in the input buffer
            continue;
            cout << "\n\t\t\t\aInvalid choice. Please try again." << endl;
        }
        if (choice < 0 || choice > 8)
        {
            cout << "Please Select Your choice From (1 - 9)." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please Select An Empty Position." << endl;
        }
        else
        {
            board[choice] = 'X';
            break;
        }
    }
}

//________________________________________________ O Player's Choice _________________________________________________

void get_o_player_choice()
{
    while (true)
    {
        cout << "Please Select Your choice From (1 - 9): ";
        int choice;
        cin >> choice;
        choice--;
        if (cin.fail()) {

            cin.clear(); 										 			//Clearing  the error of cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");			// Ignore any remaining characters in the input buffer
            continue;
            cout << "\n\t\t\t\aInvalid choice. Please try again." << endl;


        }
        if (choice < 0 || choice > 8)
        {
            cout << "Please Select Your choice From (1 - 9)." << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "Please Select An Empty Position." << endl;
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}

//________________________________________________ Player VS Player __________________________________________________

void player_vs_player() {
    char x_player_turn, o_player_turn;

    while (true) {
        system("cls");
        show_board();
        if (count_board('X') == count_board('O')) {
            cout << x_player_turn << " X Player's Turn." << endl;
            get_x_player_choice();
        }
        else {
            cout << o_player_turn << "O Player's Turn." << endl;
            get_o_player_choice();
        }
        char winner = check_winner();
        if (winner == 'X') {
            system("cls");
            show_board();
            cout << x_player_turn << "X Player Won The Game" << endl;
            cout<<"Press any key to continue game."<<endl;
            break;
        }
        else if (winner == 'O') {
            system("cls");
            show_board();
            cout << o_player_turn<< "O Player Won The Game." << endl;
            cout<<"Press any key to continue game."<<endl;
            break;
        }
        else if (winner == 'D') {
            cout << "Game is Draw." << endl;
			cout<<"Press any key to continue game."<<endl;
            break;

        }
    }
}

int count_board(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
        {
            total += 1;
        }
    }
    return total;
}

//_________________________________________________ Check Winner _____________________________________________________

char check_winner()
{
    // checking winner in horizontal/row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];

    // checking winner in vertical/column
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];

    // checking winner diagonally
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];

    if (count_board('X') + count_board('O') < 9)
        return 'C'; // Continue
    else
        return 'D'; // Draw
}

//_________________________________________________Computer's IQ______________________________________________________

char IQ()
{
    // horizontal/row
    if (board[0] == board[1] && board[2] == ' ')
        return board[2] = 'O';
    if (board[1] == board[2] && board[0] == ' ')
        return board[0] = 'O';
    if (board[0] == board[2] && board[1] == ' ')
        return board[1] = 'O';
    if (board[3] == board[4] && board[5] == ' ')
        return board[5] = 'O';
    if (board[4] == board[5] && board[3] == ' ')
        return board[3] = 'O';
    if (board[3] == board[5] && board[4] == ' ')
        return board[4] = 'O';
    if (board[6] == board[7] && board[8] == ' ')
        return board[8] = 'O';
    if (board[7] == board[8] && board[6] == ' ')
        return board[6] = 'O';
    if (board[6] == board[8] && board[7] == ' ')
        return board[7] = 'O';


    // vertical/column
    if (board[0] == board[3] && board[6] == ' ')
        return board[6] = 'O';
    if (board[3] == board[6] && board[0] == ' ')
        return board[0] = 'O';
    if (board[0] == board[6] && board[3] == ' ')
        return board[3] = 'O';
    if (board[1] == board[4] && board[7] == ' ')
        return board[7] = 'O';
    if (board[1] == board[7] && board[4] == ' ')
        return board[4] = 'O';
    if (board[4] == board[7] && board[1] == ' ')
        return board[1] = 'O';
    if (board[2] == board[5] && board[8] == ' ')
        return board[8] = 'O';
    if (board[2] == board[8] && board[5] == ' ')
        return board[5] = 'O';
    if (board[5] == board[8] && board[2] == ' ')
        return board[2] = 'O';

    // diagonally
    if (board[0] == board[4] && board[8] == ' ')
        return board[8] = 'O';
    if (board[0] == board[8] && board[4] == ' ')
        return board[4] = 'O';
    if (board[4] == board[8] && board[0] == ' ')
        return board[0] = 'O';
    if (board[2] == board[4] && board[6] == ' ')
        return board[6] = 'O';
    if (board[2] == board[6] && board[4] == ' ')
        return board[4] = 'O';
    if (board[4] == board[6] && board[2] == ' ')
        return board[2] = 'O';

}

//___________________________________________________ Game Board _____________________________________________________

void show_board()
{
    cout << "\n\n\t\t\t\t" << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t" << setw(3) << "*" << setw(44) << "*" << endl;
    cout << "\t\t\t\t" << setw(5) << "*" << "\t\t TIC TAC TOE GAME" << setw(12) << "*" << endl;
    cout << "\t\t\t\t" << setw(3) << "*" << setw(44) << "*" << endl;
    cout << "\t\t\t\t" << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

    cout << "\n\n\t\t\t\t\t\t" << "   " << "    |   " << "    |   " << endl;
    cout << "\t\t\t\t\t\t" << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
    cout << "\t\t\t\t\t\t" << "   " << "    |   " << "    |   " << endl;
    cout << "\t\t\t\t\t\t" << "----------------------" << endl;
    cout << "\t\t\t\t\t\t" << "   " << "    |   " << "    |   " << endl;
    cout << "\t\t\t\t\t\t" << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
    cout << "\t\t\t\t\t\t" << "   " << "    |   " << "    |   " << endl;
    cout << "\t\t\t\t\t\t" << "----------------------" << endl;
    cout << "\t\t\t\t\t\t" << "   " << "    |   " << "    |   " << endl;
    cout << "\t\t\t\t\t\t" << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;
    cout << "\t\t\t\t\t\t" << "   " << "    |   " << "    |   " << endl;

    //__________________________________________________Sample Board______________________________________________

    cout << "\t\t\t\t\t\t\t\t\t\t\t" << setw(1) << "----------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|" << "   1  |   2  |   3  " << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|" << "--------------------" << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|" << "   4  |   5  |   6  " << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|" << "--------------------" << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|" << "   7  |   8  |   9  " << "|" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t" << setw(1) << "----------------------" << endl;
}

//_________________________________________________MAIN SCREEN_____________________________________________________

int main() {

    system("Color 3F");
    cout << "\n\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t" << setw(11) << "*" << setw(28) << "*" << endl;
    cout << "\t\t\t\t" << setw(13) << "*" << "\tSEMESTER PROJECT" << setw(5) << "*" << endl;
    cout << "\t\t\t\t" << setw(11) << "*" << setw(28) << "*" << endl;
    cout << "\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;

    cout << "\n\tINSTITUTE: GCUF" << "\t\t\t\t\t\t\t\t\t" << setw(5) << "SEMESTER: SPRING 2023" << endl;
    cout << "\n\tDEPARTMENT: COMPUTER SCIENCE" << "\t\t\t\t\t\t\tFACULTY: PHYSICAL SCIENCE" << endl;
    cout << "\n\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t" << setw(11) << "*" << setw(28) << "*" << endl;
    cout << "\t\t\t\t" << setw(13) << "*" << "\tTIC TAC TOE GAME" << setw(5) << "*" << endl;
    cout << "\t\t\t\t" << setw(11) << "*" << setw(28) << "*" << endl;
    cout << "\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;

    cout << "\n\n\t\t\t\t\t\t DEVELOPED BY:\n\t\t\t\t\t\t ADAN MASOOD\n\t\t\t\t\t\t AIMAN MASOOD\n\t\t\t\t\t\t FIZZA SHOAIB";
    cout << "\n\n\t\t\t\t" << " * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cin.get();
    system("cls");
    menu();

//____________________________________________________________________Quit Game_________________________________________

    char quit;
    while (true)
    {
        for (int i = 0; i < 10; i++)
        {
            board[i] = ' ';
        }
        cin >> quit;
        if (quit == 'q')
        {
            return 0;
        }
        else 
        {
            system("cls");
            menu();
        }
    }
}
