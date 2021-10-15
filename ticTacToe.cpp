/* Abdulrazzak Jouhar 2020 */

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
using namespace std;
#define print(x,y,z) cout << x << " " << y << " " << z << endl;

// main game grid
char grid[3][3] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};

void play(int num, char player);
void check(string plwin);
void display();
void action(char fspl);
void PvP();
void PvC();
void playC(int num,char player);
void actionC();
int start();

bool running = true;
bool ending = false;
int draw = 0;
int mytime = 1;

int main()
{
    int mode = start();

    if (mode == 1)
    {
        PvC();
    }
    else if(mode == 2)
    {
        PvP();
    }
    else
    {
        main();
    }
    

    return 0;
}

int start()
{
    string st;
    cout << "1Player OR 2Players.. ";
    cin >> st;
    int mode;
    if (st == "1" || st == "2") 
    {
        if (st == "1") mode = 1;
        else mode = 2;
    }
    else 
    {
        mode = 10;
    }

    return mode;
}

void display()
{
    system("cls");
    cout << endl;
    print(grid[0][0],grid[0][1],grid[0][2]);
    print(grid[1][0],grid[1][1],grid[1][2]);
    print(grid[2][0],grid[2][1],grid[2][2]);
}

void PvP()
{
    display();

    while (running == true)
    {
        action('X');
        if (running == false)
            break;
        display();
        check("player 1");
        if (ending == true)
            break;

        action('O');
        if (running == false)
            break;
        display();
        check("player 2");
        if (ending == true)
            break;
    }
}

void PvC()
{
    display();

    while (running == true)
    {
        action('X');
        if (running == false)
            break;
        display();
        check("player 1");
        if (ending == true)
            break;

        actionC();
        if (running == false)
            break;
        display();
        check("Computer");
        if (ending == true)
            break;
    }
}

void playC(int num,char player)
{

    switch (num)
    {
    case 1:
        if (grid[0][0] == '1')
        {
            grid[0][0] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 2:
        if (grid[0][1] == '2')
        {
            grid[0][1] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 3:
        if (grid[0][2] == '3')
        {
            grid[0][2] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 4:
       if (grid[1][0] == '4')
        {
            grid[1][0] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 5:
        if (grid[1][1] == '5')
        {
            grid[1][1] = '5';
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 6:
        if (grid[1][2] == '6')
        {
            grid[1][2] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }

    case 7:
        if (grid[2][0] == '7')
        {
            grid[2][0] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 8:
        if (grid[2][1] == '8')
        {
            grid[2][1] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    case 9:
        if (grid[2][2] == '9')
        {
            grid[2][2] = player;
            draw++;
            break;
        }
        else
        {
            actionC();
            break;
        }
    }

}

void play(int num ,char player)
{

    switch (num)
    {
    case 1:
        if (grid[0][0] == '1')
        {
            grid[0][0] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 2:
        if (grid[0][1] == '2')
        {
            grid[0][1] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 3:
        if (grid[0][2] == '3')
        {
            grid[0][2] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 4:
       if (grid[1][0] == '4')
        {
            grid[1][0] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 5:
        if (grid[1][1] == '5')
        {
            grid[1][1] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 6:
        if (grid[1][2] == '6')
        {
            grid[1][2] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }

    case 7:
        if (grid[2][0] == '7')
        {
            grid[2][0] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 8:
        if (grid[2][1] == '8')
        {
            grid[2][1] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    case 9:
        if (grid[2][2] == '9')
        {
            grid[2][2] = player;
            draw++;
            break;
        }
        else
        {
            display();
            action(player);
            break;
        }
    
    default:
        SetConsoleTextAttribute(h,12);
        cout << endl << "Invalid entry ,Game Over... " << endl;
        SetConsoleTextAttribute(h,15);
        running = false;
        break;
        
    }

}

void check(string plwin)
{

    if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
    {
        cout << plwin << " win" << endl;
        ending = true;
    }
    else if (draw == 9)
    {
       cout << "no one win's (draw) " << endl;
       ending = true; 
    }
    else
    {
        
    }
}

void action(char fspl)
{
    int number;

    cout << endl << "\'" << fspl << "\'" << "choose a number (from 1 to 9)  " ;
    cin >> number;
    play(number,fspl);
}

void actionC()
{
    srand(mytime);
    int random = (rand() % 9) + 1;
    mytime++;

    playC(random,'O');
}