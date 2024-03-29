/** -----------------------------------------------------------------------------
*
* File Name: battleExec.cpp
* Author: Blake Morrell
* KU ID: 2866535
* Email Adress: blknm4598@ku.edu
* Assignment:   EECS-448 Project Battleship
* Description:  Handles User input for how many ships
* Date: 9-12-19
*
---------------------------------------------------------------------------- */
#include "battleExec.h"
#include "board.h"
#include "player.h"
#include <string>
#include <cctype>
#include <limits>
#include <iostream>
#include <unistd.h>
using namespace std;

Executive::Executive()
{
    ship_num = 0; //sets starting ship amount to zero
}

void Executive::run()
{
  string location; //row and column on the map
  int dir; //direction that the ship faces
  startMenu(); //opens start menu

  CalculateWinHits(ship_num);//ship_num is inputted by user, this function is called to find total hits to win game

  player player1; //creates player 1 with the number of ships obtained from input
  player1.setnum(ship_num);
  cout<<"\n---------PLAYER 1----------\n\n";
  player1.print();
  while(!player1.IsAllMarked())
  {
    cout<<"\nPick which column (A-H) and row (1-8) (Must be in the form [col][row] i.e.: A1): ";
    cin>>location;
    while(!transfor(location))
    {
      cout<<"Invalid Position. Try again: ";
      cin>>location;
    }
    cout<<"\nWhich direction will your ship face?\n";
    cout<<"Choose 1 for up, 2 for down, 3 for left, or 4 for right: ";
    cin>>dir;
    while(1) //checking for right input
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
        cin >> dir;
      }
      else
      {
        break;
      }
    }
    while((dir < 1) || (dir > 4)) //error checking
    {
      cout<<"You must enter a number between 1 and 4. Try again: ";
      cin>>dir;
      while(1) //checking for right input
      {
        if(cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
          cin >> dir;
        }
        else
        {
          break;
        }
      }
    }
    try
    {
      player1.placement(row, col, dir);
      player1.print();
    }
    catch (const std::runtime_error &e)
    {
      cout << "enter a correct direction!" << endl;
    }
  }
    cout << "\nTYPE anything THEN PRESS ENTER to place Player2 Ships\n";
    string dummy;
    cin >> dummy;
    ClearScreen();

    player player2; //creates player 1 with the number of ships obtained from input
    player2.setnum(ship_num);
    cout<<"\n---------PLAYER 2----------\n\n";
    player2.print();

    while(!player2.IsAllMarked())
    {
      cout<<"\nPick which column (A-H) and row (1-8) (Must be in the form [col][row] i.e.: A1): ";
      cin>>location;
      while(!transfor(location))
      {
        cout<<"Invalid Position. Try again: ";
        cin>>location;
      }
      cout<<"\nWhich direction will your ship face?\n";
      cout<<"Choose 1 for up, 2 for down, 3 for left, or 4 for right: ";
      cin>>dir;
      while(1) //checking for right input
      {
        if(cin.fail())
        {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
          cin >> dir;
        }
        else
        {
          player2.printHidden();
          break;
        }
      }
      while((dir < 1) || (dir > 4)) //error checking
      {
        cout<<"You must enter a number between 1 and 4. Try again: ";
        cin>>dir;
        while(1) //checking for right input
        {
          if(cin.fail())
          {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
            cin >> dir;
          }
          else
          {
            break;
          }
        }
      }
      try
      {
        player2.placement(row, col, dir);
        player2.print();
      }
      catch (const std::runtime_error &e)
      {
        cout << "enter a correct direction!" << endl;
      }
  }
  cout << "\nATTACK phase, TYPE anything and PRESS ENTER to begin -> \n";
  cin >> dummy;
  ClearScreen();
  while(player1.GetHits() != win_hits && player2.GetHits() != win_hits)   /////add while loop to check win condition
  {   string x;

      cout<<"\n---------PLAYER 1----------\n\n";

        player1.printHidden();
        player1.print();


      cout <<"\nEnter attack coordinates (A-H),(1-8) (i.e. A1): ";
      cin >>x;
      while(!transfor(x))
      {
        // cout <<x;
        // cout << row <<" " <<col;
        cout<<"Invalid position. Try again: ";
        cin>>x;
      }
      while(player1.hitRetry(row, col))
      {
        cout<<"You've already tried that spot before! Try again: ";
        cin>>x;
        while(!transfor(x))
        {
          // cout <<x;
          // cout << row <<" " <<col;
          cout<<"Invalid position. Try again: ";
          cin>>x;
        }
      }
      if(player2.attack(row,col)) //here we want to change map
      {
        player1.update(row,col, true); //here, we want to only update grid

        //if(player2.GetHits() == win_hits) break;
      }
      else   {
        player1.update(row,col, false);

      }

      player1.printHidden();
      player1.print();


      if (player2.GetHits() == win_hits)
      {
        cout<<"\nPLAYER 1 WINS. Thanks for playing!\n";
        break;
      }

      cout << "\nEND OF TURN, TYPE anything and PRESS ENTER to SWITCH players -> \n";
      cin >> dummy;
      ClearScreen();

      cout<<"\n---------PLAYER 2----------\n\n";

      player2.printHidden();
      player2.print();

      cout <<"\nEnter attack coordinates (A-H),(1-8) (i.e. A1): ";
      cin >>x;

      while(!transfor(x))
      {
        cout<<"Invalid position. Try again: ";
        cin>>x;
      }
      while(player2.hitRetry(row, col))
      {
        cout<<"You've already tried that spot before! Try again: ";
        cin>>x;
        while(!transfor(x))
        {
          // cout <<x;
          // cout << row <<" " <<col;
          cout<<"Invalid position. Try again: ";
          cin>>x;
        }
      }

      if(player1.attack(row,col)) //here we want to change map
      {
        player2.update(row,col, true); //here, we want to only update grid
        //if(player1.GetHits() == win_hits) break;
      }
      else {
        player2.update(row,col, false);

      }


      player2.printHidden();
      player2.print();

      if (player1.GetHits() == win_hits)
      {
        cout<<"\nPLAYER 2 WINS. Thanks for playing!\n";
        break;
      }

      cout << "\nEND OF TURN, TYPE anything and PRESS ENTER to SWITCH players -> \n";
      cin >> dummy;
      ClearScreen();
  }
}

Executive::~Executive()
{

}

void Executive::startMenu()
{
  cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
       << "x                  Battleship                x\n"
       << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n"
       << "Enter the number of ships for this game (You may have up to 5 ships): ";
  cin >> ship_num;
  while(1) //checking for right input
  {
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
      cin >> ship_num;
    }
    else
    {
      break;
    }
  }
  while((ship_num < 1) || (ship_num > 5))
  {
    cout << "You must enter a number between 0 and 5, try again.\n"
         << "Enter the number of ships for this game (You may have up to 5 ships): ";
    cin >> ship_num;
    while(1) //checking for right input
    {
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Bad entry.  Enter a NUMBER: "; //if not an int, must try again.
        cin >> ship_num;
      }
      else
      {
        break;
      }
    }
  }
}

bool Executive::inputChecker(string x)
{
  string y = "ABCDEFGH";
  string z = "abcdefgh";
  string nums = "12345678";
  char first_char = x.at(0);
  char second_char = x.at(1);
  bool flag = false;
  for(int i =0; i< 8; i++)
  {
    if ((first_char == y.at(i) || first_char == z.at(i)))
    {
      for(int k=0; k < 8; k++)
      {
        if(second_char == nums.at(k))
        {
          flag = true;
        }
      }
    }
  }
  return flag;
}
bool Executive::transfor(string x)
{
  //int value = stoi(x.substr(0, 1));
  //cout << value << endl;
  if (x.size() < 2 || x.size() != 2)
  {
    return false;
  }
  else if(!inputChecker(x))
  {
    return false;
  }
  else if (transtoint(x.at(0)) && transfromchar(stoi(x.substr(1, 1))))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Executive::transfromchar(int x)
{
  bool flag = false;
  for (int i = 1; i < 9; i++)
  {
    if (x == i)
    {
      row = i-1;
      flag = true;
    }
  }
  return flag;
}
bool Executive::transtoint(char x)
{
  string y = "ABCDEFGH";
  string z="abcdefgh";
  bool flag = false;
  for (int i = 0; i < 8; i++)
  {
    if (x == y.at(i)||x==z.at(i))
    {
      col = i;
      flag = true;
    }
  }
  return flag;
}

void Executive::ClearScreen()
{
  cout << "Switching Players in\n";
  usleep(1000000);
  cout << "3\n";
  usleep(1000000);
  cout << "2\n";
  usleep(1000000);
  cout << "1\n";
  usleep(1000000);
  for(int i = 0; i < 100; i++)
  {
    cout << '\n';
  }
}

void Executive::CalculateWinHits(int ship_num)
{
    for(int i = ship_num; i > 0; i--)
    {
        win_hits += i;
    }
}
