#include <iostream>
#include <cmath>
#include <algorithm> 
#include <string> 

using namespace std;
const int ROWS = 3;
const int COLS = 3;

//Setting BV,ongoing, player1 and player2 as global variebles, as they are used in
//most functions and the same arguments are used through out the entire program
char** BV; // Board Values
bool ongoing;


struct Player {
    string name;
    char character;
    int wins = 0;
};
Player player1, player2;

bool checkWin() {
    bool win = false;
    // Check diagonal for a win
    if (BV[0][0] == BV[1][1] && BV[1][1] == BV[2][2] || BV[0][2] == BV[1][1] && BV[1][1] == BV[2][0]) {
        win = true;
    }
    // Check vertical and horizontal for a win
    else {
        for (int i = 0; i < 3; i++) {
            if (BV[i][0] == BV[i][1] && BV[i][1] == BV[i][2] || BV[0][i] == BV[1][i] && BV[1][i] == BV[2][i]) {
                win = true;
                break;
            }
        }
    }

    return win;
}

char* intIdToPointer(int iD) {
    int r = floor((iD - 1) / 3);
    int c = (iD + 2) % 3;
    return &BV[r][c];
}

bool ifAvailable(char* pos) {
    return (*pos >= '1' && *pos <= '9');
}

void printAvailable() {
    for (int i = 1; i <= 9; i++)
        if (ifAvailable(intIdToPointer(i)))
            cout << i << " ";
}

void printBoard() {
    for (int r = 0; r < 3; r++) {
        cout << "\n\t\t|";
        for (int c = 0; c < 3; c++)
            cout << BV[r][c] << "|";
    }
}

void resetBoard() {
    char count = '0';
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            count++;
            BV[r][c] = count;
        }
    }
}

void playerTurn(Player& p) {
    cout << "\n" << p.name << " choose an empty field!";
    bool repeat = false;
    char* value;
    do {
        if (repeat) cout << "Please enter an available field.";
        int chosen;
        cin >> chosen;
        value = intIdToPointer(chosen);
        repeat = !ifAvailable(value);
    } while (repeat);

    *value = p.character;

    if (checkWin()) {
        ongoing = false;
        cout << "Victory for #" << ++p.wins << " for " << p.name << endl;
    }
}

string uppercase(string input) {
    transform(input.begin(), input.end(), input.begin(), toupper);
    return input;
}

void GetPlayerInfo() {
    cout << "Enter name of player 1: ";
    getline(cin, player1.name);

    cout << "Enter non-numerical (not 1-9) character for player 1: ";
    string charac1;
    while (true) {
        getline(cin, charac1);
        if (charac1.length() == 1 && !isdigit(charac1[0])) {
            player1.character = charac1[0];
            break;
        }
        else {
            cout << "Please enter a single non-numerical character for player 1: ";
        }
    }

    string name2;
    cout << "Enter name of player 2: ";
    do {
        getline(cin, name2);
        if (uppercase(name2) == uppercase(player1.name)) {
            cout << "Please enter a different name than player 1: ";
        }
    } while (uppercase(name2) == uppercase(player1.name));

    string charac2;
    cout << "Enter non-numerical (not 1-9) character for player 2: ";
    while (true) {
        getline(cin, charac2);
        if (charac2.length() == 1 && !isdigit(charac2[0]) && toupper(charac2[0]) != toupper(player1.character)) {
            player2.character = charac2[0];
            break;
        }
        else {
            cout << "Please enter a single non-numerical character different from player 1's character: ";
        }
    }

    player2.name = name2;
    cout << "\033[2J\033[1;1H";
}

void PrintWinner() {
    if (player1.wins > player2.wins)
        cout << player1.name << " wins " << player1.wins << ":" << player2.wins<<endl;
    else
        if (player1.wins < player2.wins)
            cout << player2.name << " wins " << player2.wins << ":" << player1.wins<<endl;
        else cout<<"It is a draw " << player1.wins << ":" << player2.wins<<endl;
    cout << "Thanks for playing!!";
}

void SwapPlayers() {
    Player temp = player1;
    player1 = player2;
    player2 = temp;
}

int main() {
    int chosen;
    char respond;
    char* value;
    bool repeat;

    GetPlayerInfo();
    cout << "Lets start"<<endl;

    // initialize the board values (Dynamic 2D Arrays)
    BV = new char* [ROWS];
    char count = '0';

    for (int r = 0; r < ROWS; r++) {
        BV[r] = new char[COLS];
        for (int c = 0; c < COLS; c++) {
            count++;
            BV[r][c] = count;
        }
    }

    // Game start
    int counter=1;
    ongoing = true;
    do {
        while (counter <= ROWS*COLS && ongoing) {
            cout << endl << "The fields with the following field ID numbers are still free:";
            printAvailable();
            cout << endl << "The board currently looks as follows:";
            printBoard();

            if (counter % 2 == 0) {
                playerTurn(player2);
            }
            else {
                playerTurn(player1);
            }

            counter++;
            if (ongoing) cout << "\033[2J\033[1;1H";
        }

        // if no one has won, and all 9 attempts are used, the game is a tie
        if (ongoing)
            cout << "It is a tie" << endl;

        printBoard();
        do {
            cout << endl << "Do you want to play another game? (y/n)";
            cin >> respond;
            if (respond == 'y') {
                resetBoard();
                SwapPlayers();
                counter = 1;
                ongoing = true;
                cout << "\033[2J\033[1;1H";
            }
            else
                if (respond == 'n') ongoing = false;

        } while (!(respond == 'y' || respond == 'n'));

    } while (ongoing);

    PrintWinner();

    // delete
    for (int r = 0; r < ROWS; r++)
        delete[] BV[r];

    delete[] BV;
    BV = nullptr;

    return 0;
}
