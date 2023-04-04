#include<bits/stdc++.h>
using namespace std;
struct Move
{
    int R,C;
};
class Board
{
private:
    vector<vector<string>> arr{
            {"  ","a1","a2","a3","  "},
            {"b1","  ","  ","  ","  "},
            {"b2","  ","  ","  ","  "},
            {"b3","  ","  ","  ","  "},
            {"  ","  ","  ","  ","  "}
    };
    string lst_move;
    Move lastMoveRC;
    int step;
    string umove;
public:
    Board(){}
    void printB()
    {
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++)
            {
                cout << "|" <<arr[i][j] << "|" ;
            }
            cout <<endl;
        }
        cout << endl;
    }
    string element(int i, int j)
    {
        return arr[i][j];
    }
    void Move(string s)
    {
        string a = s;
        umove = s;
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
                            if (arr[i+1][j]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i+1][j]=a;
                                lst_move="i"+to_string(i+1);
                                step =1;
                                lastMoveRC.R = i+1;
                                lastMoveRC.C = j;
                                a="d";
                                break;
                            }
                            else if (arr[i+1][j]!="  " && arr[i+2][j]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i+2][j]=a;
                                lst_move="i"+to_string(i+2);
                                step = 2;
                                lastMoveRC.R = i+2;
                                lastMoveRC.C = j;
                                a="d";
                                break;
                            }
                            else
                            {
                                continue;
                            }
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
                            if (arr[i][j+1]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i][j+1]=a;
                                lst_move="j"+to_string(j+1);
                                step = 1;
                                lastMoveRC.R = i;
                                lastMoveRC.C = j+1;
                                a="d";
                                break;
                            }
                            else if (arr[i][j+1]!="  " && arr[i][j+2]=="  ")
                            {
                                arr[i][j]="  ";
                                arr[i][j+2]=a;
                                lst_move="j"+to_string(j+2);
                                step = 2;
                                lastMoveRC.R = i;
                                lastMoveRC.C = j+2;
                                a="d";
                                break;
                            }
                            else
                            {
                                continue;
                            }
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

    void Undo()
    {
        if (lst_move[0]=='i')
        {
            arr[lastMoveRC.R][lastMoveRC.C] = "  ";
            arr[lastMoveRC.R-step][lastMoveRC.C] =umove ;
        }
        else if (lst_move[0]=='j')
        {
            arr[lastMoveRC.R][lastMoveRC.C] = "  ";
            arr[lastMoveRC.R][lastMoveRC.C-step] =umove;
        }
    }

    bool Point()
    {
        if (lst_move=="j4"||lst_move=="i4")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool valid_move(string a)
    {
        if (a[0]=='a'||a[0]=='b')
        {
            for (int i=0;i<5;i++)
            {
                for (int j=0;j<5;j++)
                {
                    if (arr[i][j]==a)
                    {
                        if (i==4||j==4)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }

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

    bool Awin()
    {
        int c1=0;
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
        else
        {
            return 0;
        }
    }

    bool Bwin()
    {
        int c1=0;
        for (int i=1;i<5;i++)
        {
            if (arr[i][4]!="  ")
            {
                c1++;
            }
        }
        if (c1==3)
        {
            return 1;
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
    void inc_score()
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

class PvsP
{
private:
    Board  b;
    int turn;
public:
    PvsP()
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
        Player one("Player1");
        Player two("Player2");
        string name1,name2;
        cout << "       Welcome to Rocket game\n\n";
        cout << "Player 1, Enter your name : ";
        cin >> name1;
        one.set_name(name1);
        cout << "Player 2, Enter your name : ";
        cin >> name2;
        two.set_name(name2);
        string mv;
        b.printB();
        while(true)
        {
            while(true)
            {
                cout << name1 << " you want to move (a1/a2/a3): ";
                cin >> mv;
                if (mv == "a1" || mv == "a2" || mv == "a3" && b.valid_move(mv) )
                {
                    b.Move(mv);
                    if (b.Point())
                    {
                        one.inc_score();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            b.printB();
            cout << name1 << " score : " << one.get_score() << endl;
            cout << name2 << " score : " << two.get_score() << endl << endl;
            if (b.check_end()==1)
            {
                cout << name1 << " Win!!\n\n";
                break;
            }
            Turn();
            while(true)
            {
                cout << name2 << " you want to move (b1/b2/b3): ";
                cin >> mv;
                if ((mv == "b1" || mv == "b2" || mv == "b3" ) && b.valid_move(mv) )
                {
                    b.Move(mv);
                    if (b.Point())
                    {
                        two.inc_score();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            b.printB();
            cout << name1 << " score : " << one.get_score() << endl;
            cout << name2 << " score : " << two.get_score() << endl << endl;
            if (b.check_end()==2)
            {
                cout << name2 << " Win!!\n\n";
                break;
            }
            Turn();
        }
    }
};

class AI
{
private:
    Board b;
    int turn;
public:
    AI()
    {
        turn = 1;
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
        Player A("Player 1");
        Player B("AI");
        string name;
        cout << "       Welcome to Rocket game\n\n";
        cout << "Enter your Name : ";
        cin >> name;
        A.set_name(name);
        string mv;
        b.printB();
        while(true)
        {

            //Player Turn ...............
            while(true)
            {
                cout << name << " you want to move (b1/b2/b3): ";
                cin >> mv;
                if (mv == "b1" || mv == "b2" || mv == "b3" && b.valid_move(mv) )
                {
                    b.Move(mv);
                    if (b.Point())
                    {
                        A.inc_score();
                    }
                    break;
                }
                else
                {
                    cout << "Invalid input!!\n";
                }
            }
            b.printB();
            cout << name << " score : " << A.get_score() << endl;
            cout << "AI" << " score : " << B.get_score() << endl;
            if (b.check_end()==2)
            {
                cout << name << " Win!!\n\n";
                break;
            }
            Turn();

            //Computer Turn ...............

            Move bm = findBestMove(b);
            mv = b.element(bm.R, bm.C);
            b.Move(mv);
            if (b.Point())
            {
                B.inc_score();
            }
            b.printB();
            cout << name << " score : " << A.get_score() << endl;
            cout << "AI" << " score : " << B.get_score() << endl;
            if (b.check_end()==1)
            {
                cout << "AI" << " Win!!\n\n";
                break;
            }



        }
    }

    int Evaluate(Board b)
    {
        if (b.Awin())
        {
            return -10;
        }
        else if (b.Bwin())
        {
            return 10;
        }
        else
        {
            return 0;
        }
    }

    int minimax(Board b, int depth, bool ismax)
    {

        int score = Evaluate(b);

        //BASE CASE

        // If Maximizer has won the game return his/her
        // evaluated score
        if (score == 10)
        {
            return score-depth;
        }

        // If Minimizer has won the game return his/her
        // evaluated score
        if (score == -10)
        {
            return score+depth;
        }

        // If this maximizer's move
        if (ismax)
        {
            int best = -1000;
            int c=1;
            // Traverse all cells
            for (int i = 0; i<4; i++)
            {
                for (int j = 1; j<4; j++)
                {
                    if (b.element(i,j)[0]=='a')
                    {
                        // Check if cell is empty
                        if (b.element(i+1,j)=="  ")
                        {
                            if (b.valid_move("a"+to_string(j)))
                            {
                                // Make the move
                                b.Move("a"+to_string(j));

                                // Call minimax recursively and choose
                                // the maximum value
                                best = max( best,
                                            minimax(b, depth+1, !ismax) );

                                // Undo the move
                                b.Undo();

                            }
                            else
                            {
                                continue;
                            }
                        }

                        else if (b.element(i+2,j)=="  ")
                        {
                            if (b.valid_move("a"+to_string(j)))
                            {
                                // Make the move
                                b.Move("a"+to_string(j));

                                // Call minimax recursively and choose
                                // the maximum value
                                best = max( best,
                                            minimax(b, depth+1, !ismax) );

                                // Undo the move
                                b.Undo();

                            }
                            else
                            {
                                continue;
                            }
                        }


                    }
                }
            }
            return best;
        }

            // If this minimizer's move
        else if (!ismax)
        {
            int best = 1000;
            static int c=1;
            // Traverse all cells
            for (int i = 1; i<4; i++)
            {
                for (int j = 0; j<4; j++)
                {
                    if (b.element(i,j)[0]=='b')
                    {
                        // Check if cell is empty
                        if (b.element(i,j+1)=="  ")
                        {
                            if (b.valid_move("b"+to_string(i)))
                            {
                                // Make the move
                                b.Move("b"+to_string(i));

                                // Call minimax recursively and choose
                                // the maximum value
                                best = min( best,
                                            minimax(b, depth+1, ismax) );

                                // Undo the move
                                b.Undo();

                            }
                        }

                        else if (b.element(i,j+2)=="  ")
                        {
                            if (b.valid_move("b"+to_string(i)))
                            {
                                // Make the move
                                b.Move("b"+to_string(i));

                                // Call minimax recursively and choose
                                // the maximum value
                                best = min( best,
                                            minimax(b, depth+1, ismax) );

                                // Undo the move
                                b.Undo();
                            }
                        }
                        c++;

                    }
                }
            }
            return best;
        }
    }

    Move findBestMove(Board b)
    {
        int bestVal = -1000;
        Move bestMove;
        bestMove.R = -1;
        bestMove.C = -1;
        int c=1;
        // Traverse all cells, evaluate minimax function for
        // all empty cells. And return the cell with optimal
        // value.
        for (int i = 0; i<4; i++)
        {
            for (int j = 1; j<4; j++)
            {

                if (b.element(i,j)[0]=='a')
                {
                    if (b.valid_move("a"+to_string(j)))
                    {
                        // Make the move
                        b.Move("a"+to_string(j));

                        // compute evaluation function for this
                        // move.
                        int moveVal = minimax(b, 0, true);

                        // Undo the move
                        b.Undo();

                        // If the value of the current move is
                        // more than the best value, then update
                        // best/
                        if (moveVal > bestVal)
                        {
                            bestMove.R = i;
                            bestMove.C = j;
                            bestVal = moveVal;
                        }

                    }
                    c++;
                }
                /*else if (b.element(i,j)[0]=='b')
                {
                    if (b.valid_move("b"+to_string(c)))
                    {
                        // Make the move
                        b.Move("b"+to_string(c));

                        // compute evaluation function for this
                        // move.
                        int moveVal = minimax(b, 0, false);

                        // Undo the move
                        b.Undo();

                        // If the value of the current move is
                        // more than the best value, then update
                        // best/
                        if (moveVal > bestVal)
                        {
                            bestMove.R = i;
                            bestMove.C = j;
                            bestVal = moveVal;
                        }

                    }
                    c++;
                }*/
            }
        }

        printf("The value of the best Move is : %d\n\n",
               bestVal);

        return bestMove;
    }
};


int main()
{
    AI m;
    m.interface();
    return 0;
}
