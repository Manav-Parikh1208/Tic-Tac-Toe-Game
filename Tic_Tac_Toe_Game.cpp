#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

string p1,p2;
char token='x';
bool tie=false;
int row,col,digit=1,t_win1_s=0,t_win2_s=0;
char eg[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char game[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

void intro()
{
	fflush(stdin);
	cout<<"\nEnter Name Of Player 1 : ";
	getline(cin,p1);
	
	cout<<"\nEnter Name Of Player 2 : ";
	getline(cin,p2);
	
	cout<<endl<<endl<<p1<<" Will Enter First";
	cout<<endl<<p2<<" Will Enter Second";
}

void structure_s()
{
	cout<<"\n"<<" "<<eg[0][0]<<" | "<<eg[0][1]<<" | "<<eg[0][2];
	cout<<"\n---|---|---";
	cout<<"\n"<<" "<<eg[1][0]<<" | "<<eg[1][1]<<" | "<<eg[1][2];
	cout<<"\n---|---|---";
	cout<<"\n"<<" "<<eg[2][0]<<" | "<<eg[2][1]<<" | "<<eg[2][2];
}

void structure()
{
	cout<<"\n"<<" "<<game[0][0]<<" | "<<game[0][1]<<" | "<<game[0][2];
	cout<<"\n---|---|---";
	cout<<"\n"<<" "<<game[1][0]<<" | "<<game[1][1]<<" | "<<game[1][2];
	cout<<"\n---|---|---";
	cout<<"\n"<<" "<<game[2][0]<<" | "<<game[2][1]<<" | "<<game[2][2];
}

bool valid()
{
	for(int i=0;i<3;i++)
	{
		if(game[i][0]!=' ' && game[i][0] == game[i][1] && game[i][1] == game[i][2])
        {
            return true;
        }
        if(game[0][i]!=' ' && game[0][i] == game[1][i] && game[1][i] == game[2][i])
        {
            return true;
        }
	}
	if(game[0][0]!=' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2])
    {
        return true;
    }
    if(game[0][2]!=' ' && game[0][2] == game[1][1] && game[1][1] == game[2][0])
    {
        return true;
    }
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(game[i][j] == ' ')
            {
				return false;
            }
		}
	}
	tie=true;
	return true;
}

void start()
{	
	if(token=='x')
	{
		cout<<endl<<p1<<" Please Enter : ";
		cin>>digit;
	}
	if(token=='o')
	{
		cout<<endl<<p2<<" Please Enter : ";
		cin>>digit;
	}
	
	if(digit<1 || digit>9)
	{
		cout<<"\n\nPlease Enter A Valid Input\n";
        start();
        return;
	}
	
	if(digit==1)
	{
		row=0;
		col=0;
	}
	if(digit==2)
	{
		row=0;
		col=1;
	}
	if(digit==3)
	{
		row=0;
		col=2;
	}
	if(digit==4)
	{
		row=1;
		col=0;
	}
	if(digit==5)
	{
		row=1;
		col=1;
	}
	if(digit==6)
	{
		row=1;
		col=2;
	}
	if(digit==7)
	{
		row=2;
		col=0;
	}
	if(digit==8)
	{
		row=2;
		col=1;
	}
	if(digit==9)
	{
		row=2;
		col=2;
	}
	
	if(game[row][col]!='x' && game[row][col]!='o')
	{
		game[row][col] = token;
		token = (token == 'x') ? 'o' : 'x';
	}
	
	else
	{
		cout<<"\n\nThere Is No Empty Spaces";
		start();
	}
}

void start_c()
{	
	if(token=='x')
	{
		cout<<endl<<p1<<" Please Enter : ";
		cin>>digit;
	}
	if(token=='o')
	{
		do
        {
            digit=rand()%9+1;
            row=(digit-1)/3;
            col=(digit-1)%3;
            /*if(game[1][1]==' ')
            {
            	digit=5;
			}
			for(int i=0;i<3;i++)
			{
				if(game[i][0]=='x' && game[i][1]=='x')
				{
					digit=
				}
			}*/
        } 
		while (game[row][col]!=' ');
        
        cout<<endl<<p2<<" Has Chosen : "<<digit;
	}
	
	if(digit<1 || digit>9)
	{
		cout<<"\n\nPlease Enter A Valid Input\n";
        start();
        return;
	}
	
	if(digit==1)
	{
		row=0;
		col=0;
	}
	if(digit==2)
	{
		row=0;
		col=1;
	}
	if(digit==3)
	{
		row=0;
		col=2;
	}
	if(digit==4)
	{
		row=1;
		col=0;
	}
	if(digit==5)
	{
		row=1;
		col=1;
	}
	if(digit==6)
	{
		row=1;
		col=2;
	}
	if(digit==7)
	{
		row=2;
		col=0;
	}
	if(digit==8)
	{
		row=2;
		col=1;
	}
	if(digit==9)
	{
		row=2;
		col=2;
	}
	
	if(game[row][col]!='x' && game[row][col]!='o')
	{
		game[row][col] = token;
		token = (token == 'x') ? 'o' : 'x';
	}
	
	else
	{
		cout<<"\n\nThere Is No Empty Spaces";
		start_c();
	}
}

void reset()
{
	for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            game[i][j] = ' ';
        }
    }
    
    token = 'x';
    tie = false;
}

void case_1()
{
	cout<<"\nWelcome To Tic-Tac-Toe\n\n";
				
	reset();
	intro();
	cout<<endl;
	structure_s();
	cout<<endl<<endl;
	while(!valid())
	{
		start();
		cout<<endl;
		structure();
		cout<<endl;
	}
	
	if(tie)
	{
		cout<<"\nIt's A Draw";
	}
	else if(token=='x')
	{
		cout<<"\n"<<p2<<" WINS";
		t_win2_s++;
	}
	else if(token=='o')
	{
		cout<<"\n"<<p1<<" WINS";
		t_win1_s++;
	}
}

void case_2()
{
	cout<<"\nWelcome To Tic-Tac-Toe\n\n";
				
	reset();
	fflush(stdin);
	cout<<"\nEnter Name Of Player : ";
	getline(cin,p1);
	p2="Computer";
	
	cout<<endl;
	structure_s();
	cout<<endl<<endl;
	while(!valid())
	{
		start_c();
		cout<<endl;
		structure();
		cout<<endl;
	}
	
	if(tie)
	{
		cout<<"\nIt's A Draw";
	}
	else if(token=='x')
	{
		cout<<"\n"<<p2<<" WINS";
		t_win2_s++;
	}
	else if(token=='o')
	{
		cout<<"\n"<<p1<<" WINS";
		t_win1_s++;
	}
}

void how_to_play()
{
    system("cls");
    cout << "********** HOW TO PLAY TIC-TAC-TOE **********\n\n";
    
    cout << "1. The game is played on a 3x3 grid.\n";
    cout << "2. Players take turns to enter their move.\n";
    cout << "   - Player 1 uses 'X'\n";
    cout << "   - Player 2 (or Computer) uses 'O'\n";
    cout << "3. To make a move, enter a number (1-9) corresponding to the grid position:\n\n";
    
    cout << "   1 | 2 | 3 \n";
    cout << "  ---|---|---\n";
    cout << "   4 | 5 | 6 \n";
    cout << "  ---|---|---\n";
    cout << "   7 | 8 | 9 \n\n";
    
    cout << "4. The game ends when a player gets three of their marks in a row:\n";
    cout << "   - Horizontally, Vertically, or Diagonally.\n";
    cout << "5. If all 9 squares are filled and no player has won, it's a draw.\n";
    cout << "6. To win, a player must match three symbols ('X' or 'O') in a line.\n\n";
    
    cout << "Example Winning Combinations:\n";
    cout << "   X | X | X      O |   |    \n";
    cout << "  ---|---|---    ---|---|---  \n";
    cout << "     | O |        O | O | O  \n";
    cout << "  ---|---|---    ---|---|---  \n";
    cout << "     |   | O      X |   | X  \n\n";
    
}

void scoreboard()
{
	cout<<"\n***Tic Tac Toe***\n";
	cout<<"------------------------------------------------";
	cout<<"\nPlayer Name"<<setw(25)<<"Wins"<<endl;
	cout<<"------------------------------------------------\n";
	cout<<p1<<setw(30)<<t_win1_s<<endl;
	cout<<p2<<setw(30)<<t_win2_s;
}

int main()
{
	int ch;
	cout<<endl<<"*******TIC-TAC-TOE*******";
	while(1)
	{
		cout<<"\n\nMenu:\n1.Play With A Friend \n2.Play With Computer \n3.How To Play \n4.Scoreboard \n5.Exit \n\nEnter Your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				system("cls");
				case_1();
				break;
				
			case 2:
				system("cls");
				case_2();
				break;
				
			case 3:
				system("cls");
				how_to_play();
				break;
				
			case 4:
				system("cls");
				scoreboard();
				break;
				
			case 5:
				exit(1);
		}
	}
}
