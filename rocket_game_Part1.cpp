#include<bits/stdc++.h>
using namespace std;

class Board{

    vector<vector<string>> arr{
            {"S.","a1","a2","a3","Da"},
            {"b1","  ","  ","  ","  "},
            {"b2","  ","  ","  ","  "},
            {"b3","  ","  ","  ","  "},
            {"Db","  ","  ","  ","  "}
    };
    string LastMove;
public:

    Board(){}
    void PrintBoard()
    {
        for (int i=0;i<5;i++)
        {
            if (i == 1)
            {
                cout << "....................\n";


            }
            for (int j=0;j<5;j++)
            {

                if (j == 1)
                    cout << ":";
                if(j > 1){
                    cout << "|";
                }

                if (j==0){
                    cout <<arr[i][j];
                }
                else{
                    cout <<arr[i][j] << "|" ;
                }

            }
            cout <<endl;
        }
        cout << endl;
    }
    void Move(string s)
    {
        string a = s;
        if (valid_move(s))
        {
            if (a[0]=='a')
            {
                for (int i=0;i<4;i++)
                {
                    for (int j=1;j<4;j++)
                    {
                        if (arr[i][j]==a)
                        {
                             // if there are board rocket in the next move so jump
                            if (arr[i+1][j]!="  ")
                            {
                                if (arr[i+2][j]=="  ")
                                {
                                    arr[i][j]="  ";
                                    arr[i+2][j]=a;
                                    LastMove= "i" + to_string(i + 2);
                                    a="d";
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Move!\n";
                                    break;
                                }
                            }

                            //if there isn't board rocket in next move
                            arr[i][j]="  ";
                            arr[i+1][j]=a;
                            LastMove= "i" + to_string(i + 1);
                            a="d";
                            break;
                        }
                    }
                    if (a=="d")
                    {
                        break;
                    }
                }
            }
            else if (a[0]=='b')
            {
                for (int i=1;i<4;i++)
                {
                    for (int j=0;j<4;j++)
                    {
                        if (arr[i][j]==a)
                        {
                            //if there is a rocket in next move

                            if (arr[i][j+1]!="  ")
                            {
                                if (arr[i][j+2]=="  ")
                                {
                                    arr[i][j]="  ";
                                    arr[i][j+2]=a;
                                    LastMove= "j" + to_string(j + 2);
                                    a="d";
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid Move!\n";
                                    break;
                                }
                            }

                            //if there isn't a rocket in next move
                            arr[i][j]="  ";
                            arr[i][j+1]=a;
                            LastMove= "j" + to_string(j + 1);
                            a="d";
                            break;

                        }
                    }
                    if (a=="d")
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "Invalid Move!\n";
        }
    }
    bool Point()
    {
        if (LastMove == "j4" || LastMove == "i4")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool valid_move(string _move)
    {
//        check if i can play in this place or not
        if (_move[0] == 'a' || _move[0] == 'b')
        {
            // loop on board to check if place is empty or not
            for (int i=0;i<5;i++)
            {
                for (int j=0;j<5;j++)
                {
                    if (arr[i][j] == _move and (i==4||j==4))
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        return false;
    }

    int check_end()
    {
        int c1=0,c2=0;
        for (int j=1;j<5;j++)
        {
            if (arr[4][j]!="  ")
            {
                c1++;
            }
        }
        if (c1==3)
        {
            return 1;
        }
        for (int i=1;i<5;i++)
        {
            if (arr[i][4]!="  ")
            {
                c2++;
            }
        }
        if (c1==3)
        {
            return 1;
        }
        else if (c2==3)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

};

class Player
{
private:
    string name;
    int score;
public:
    Player()
    {
        score=0;
    }
    Player(string n)
    {
        name = n;
        score = 0;
    }
    void set_name(string n)
    {
        name = n;
    }
    void incScore()
    {
        score++;
    }
    string get_name()
    {
        return name;
    }
    int get_score()
    {
        return score;
    }
};

class GameControl
{
private:
    Board  board;
    int turn;
public:
    GameControl()
    {
        turn=1;
    }
    void Turn()
    {
        if (turn==1)
        {
            turn=2;
        }
        else
        {
            turn=1;
        }

    }
    void interface()
    {
        // set names for players
        Player player1("Player1");
        Player player2("Player2");
        string player1Name,player2Name;
        cout << "----------------Welcome to Rocket game----------------\n"
                "------------------------------------------------------\n";
        cout << "Player 1, please enter your name : ";
        cin >> player1Name;
        player1.set_name(player1Name);
        cout << "Player 2, please enter your name : ";
        cin >> player2Name;
        player2.set_name(player2Name);

        cout << "\n***********LET'S START THE GAME***********\n" ;
        board.PrintBoard();

        //game turns
        string move;
        while(true)
        {
            while(true)
            {


                //enter rocket to move
                cout << player1Name << " Which rocket you want to move (A1 or A2 or A3): ";
                cin >> move;
                if (move == "a1" || move == "a2" || move == "a3" && board.valid_move(move))
                {

                    board.Move(move);
                    if (board.Point())
                    {
                        player1.incScore();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            board.PrintBoard();
            cout << player1Name << "s'score : " << player1.get_score() << endl;
            cout << player2Name << "s'score : " << player2.get_score() << endl << endl;
            if (board.check_end() == 1)
            {
                cout << player1Name << " Win!!\n\n";
                break;
            }
            Turn();
            while(true)
            {
                cout << player2Name << " Which rocket you want to move (B1 or B2 or B3): ";
                cin >> move;
                if ((move == "b1" || move == "b2" || move == "b3" ) && board.valid_move(move) )
                {
                    board.Move(move);
                    if (board.Point())
                    {
                        player2.incScore();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            cout << endl;
            board.PrintBoard();
            cout << player1Name << " score : " << player1.get_score() << endl;
            cout << player2Name << " score : " << player2.get_score() << endl << endl;
            if (board.check_end() == 2)
            {
                cout << player2Name << " Win!!\n\n";
                break;
            }
            Turn();
        }
    }
};

int main()
{
    GameControl Rocket_Game;
    Rocket_Game.interface();
    return 0;
}

