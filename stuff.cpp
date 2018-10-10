#include <conio.h>
#include <windows.h>
int global_x_pos=0, global_y_pos=0;
vector<vector<char>> char_board;
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
void spiral(int lenght, int space)
{
    space = 1;
    if(lenght==3)
    {
        global_x_pos-=lenght-1;
        global_y_pos-=lenght;
        gotoxy(global_x_pos,global_y_pos);
        for(int i=0; i<lenght-1; i++)
        {
            cout<<lenght;
            global_y_pos++;
            gotoxy(global_x_pos,global_y_pos);
        }
        for(int i=0; i<lenght; i++)
        {
            cout<<lenght;
        }
    }
    else
    {
        if((lenght-space-1)%2==0)
        {
            gotoxy(global_x_pos,global_y_pos);
            for(int i=0; i<lenght; i++)
            {
                cout<<lenght;
            }
            lenght--;
            global_x_pos+=lenght;
            for(int i=0; i<lenght; i++)
            {
                global_y_pos++;
                gotoxy(global_x_pos,global_y_pos);
                cout<<lenght;
            }
            global_y_pos++;
            spiral(lenght-space,space);
        }
        else
        {
            global_x_pos-=lenght;
            global_y_pos-=lenght;
            gotoxy(global_x_pos,global_y_pos);
            for(int i=0; i<lenght-1; i++)
            {
                cout<<lenght;
                global_y_pos++;
                gotoxy(global_x_pos,global_y_pos);
            }
            for(int i=0; i<lenght; i++)
            {
                cout<<lenght;
            }
            global_x_pos+=lenght;
            global_y_pos+=lenght;
            spiral(lenght-space-1,space);
        }
    }
}
void spiral_it(int lenght, int space)
{
    int lenght_offset;
    for(int j=0; j<lenght; j++)
    {
        vector<char> help;
        for(int i=0; i<lenght; i++)
        {
            help.push_back((char)32);
        }
        char_board.push_back(help);
    }
    while(lenght>lenght_offset*2+space)
    {
        for(int i=lenght_offset; i<lenght-space*lenght_offset; i++)
        {
            char_board[0][i]="*";
        }
            lenght_offset++;
        for(int i=lenght_offset; i<lenght-space*(lenght_offset-1); i++)
        {
            char_board[i][lenght-1]="*";
        }
    }
    for(int j=0; j<lenght; j++)
    {
        for(int i=0; i<lenght; i++)
        {
            cout<<char_board[j][i];
        }
        cout<<"\n";
    }
}
