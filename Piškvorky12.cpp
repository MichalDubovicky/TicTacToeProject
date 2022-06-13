#include <iostream>
#include <sstream>
#include <string>
using namespace std;


string checkField(string x[9]) {
    string t = "X";
    for (int i = 0; i < 2; i++)
    {
        if (i == 1) { t = "O"; }
        if ((x[0] == t && x[1] == t && x[2] == t) || (x[3] == t && x[4] == t && x[5] == t) || (x[6] == t && x[7] == t && x[8] == t)) { return t; }
        if ((x[0] == t && x[4] == t && x[8] == t) || (x[2] == t && x[4] == t && x[6] == t)) { return t; }
        if ((x[0] == t && x[3] == t && x[6] == t) || (x[1] == t && x[4] == t && x[7] == t) || (x[2] == t && x[5] == t && x[8] == t)) { return t; }
    }


    bool end = true;
    for (int i = 0; i < 9; i++)
    {
        if (x[i] == " ") {
            end = false;
        }
    }
    if (end) { return "-"; }
    return " ";
}
void printField(string x[9]) {
    cout << "\n\n\n";
    cout << "        -------------------\n";
    cout << "        |     |     |     |\n";
    cout << "        |  " + x[0] + "  |  " + x[1] + "  |  " + x[2] + "  |\n";
    cout << "        |     |     |     |\n";
    cout << "        -------------------\n";
    cout << "        |     |     |     |\n";
    cout << "        |  " + x[3] + "  |  " + x[4] + "  |  " + x[5] + "  |\n";
    cout << "        |     |     |     |\n";
    cout << "        -------------------\n";
    cout << "        |     |     |     |\n";
    cout << "        |  " + x[6] + "  |  " + x[7] + "  |  " + x[8] + "  |\n";
    cout << "        |     |     |     |\n";
    cout << "        -------------------\n\n";

}
void singlePlayer() {

    srand(time(0));
    string t = "";
    string input = "";
    string currentPlayer = "X";
    string game[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
    int temp = 0;
    int random = 0;
    if (rand() % 2 == 1) { currentPlayer = "X"; }
    else { currentPlayer = "O"; }
    while (true)
    {
        system("cls");
        printField(game);
        t = checkField(game);
        if (t == "-") { cout << "\n\n            field is full!!!\n\n\n"; system("pause"); return; }
        else if (t == "X" || t == "O") {
            cout << "\n        winner is: " + currentPlayer + "\n\n\n";
            system("pause");
            return;
        }
        if (currentPlayer == "X") {
            cout << "        [ " + currentPlayer + " ] chooce (1-9): ";
            cin >> input;
            try
            {
                temp = stoi(input);
                if (game[temp - 1] == " ") {
                    game[temp - 1] = currentPlayer;
                    system("cls");
                    printField(game);
                    t = checkField(game);
                    if (t == "-") { cout << "\n\n            field is full!!!\n\n\n"; system("pause"); return; }
                    else if (t == "X" || t == "O") {
                        cout << "\n        winner is: " + currentPlayer + "\n\n\n";
                        system("pause");
                        return;
                    }
                    if (currentPlayer == "X") { currentPlayer = "O"; }
                    else { currentPlayer = "X"; }
                }
            }
            catch (const std::exception&)
            {

            }
        }
        else
        {
            while (true)
            {
                random = rand() % 9;
                if (game[random] == " ") {
                    game[random] = currentPlayer;
                    system("cls");
                    printField(game);
                    t = checkField(game);
                    if (t == "-") { cout << "\n\n            field is full!!!\n\n\n"; system("pause"); return; }
                    else if (t == "X" || t == "O") {
                        cout << "\n        winner is: " + currentPlayer + "\n\n\n";
                        system("pause");
                        return;
                    }
                    if (currentPlayer == "X") { currentPlayer = "O"; }
                    else { currentPlayer = "X"; }
                    break;
                }
            }
        }


    }
}
void multiPlayer() {
    srand(time(0));
    string t = "";
    string input = "";
    string currentPlayer = "X";
    string game[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
    int temp = 0;
    if (rand() % 2 == 1) { currentPlayer = "X"; }
    else { currentPlayer = "O"; }
    while (true)
    {
        system("cls");
        printField(game);

        cout << "        [ " + currentPlayer + " ] chooce (1-9): ";
        cin >> input;
        try
        {
            temp = stoi(input);
            if (game[temp - 1] == " ") {
                game[temp - 1] = currentPlayer;
                t = checkField(game);
                system("cls");
                printField(game);
                t = checkField(game);
                if (t == "-") { cout << "\n\n            field is full!!!\n\n\n"; system("pause"); return; }
                else if (t == "X" || t == "O") {
                    cout << "\n        winner is: " + currentPlayer + "\n\n\n";
                    system("pause");
                    return;
                }
                if (currentPlayer == "X") { currentPlayer = "O"; }
                else { currentPlayer = "X"; }
            }
        }
        catch (const std::exception&)
        {

        }

    }
}
void menu() {
    string temp;
    system("cls");
    cout << "\n\n\n";
    cout << "   --------------------------------\n";
    cout << "   |                              |\n";
    cout << "   |            OPTIONS           |\n";
    cout << "   |      1-  SINGLE PLAYER       |\n";
    cout << "   |      2-  MULTI PLAYER        |\n";
    cout << "   |      3-  LEAVE GAME          |\n";
    cout << "   |                              |\n";
    cout << "   --------------------------------\n\n";
    cout << "             >>>Choose: ";
    cin >> temp;
    if (temp == "1") {
        singlePlayer();
    }
    else if (temp == "2") {
        multiPlayer();
    }
    else if (temp == "3") {
        exit(1);
    }
    else {

    }
}

int main()
{
    while (true) {
        menu();
    }
}