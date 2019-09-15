/* -----------------------------------------------------------------------------
 *
* File Name: battleExec.cpp
* Author: Blk Morrell
* KU ID: 28653
* Email Adress: blk459@ku.edu
* Assignment:   EECS-448 Project Battleship
* Description:  Handles User input for how many ships
* Date: 9-12-19
*
---------------------------------------------------------------------------- */
#include "battleExec.h"
#include <iostream>

Executive::Executive()
{
  ship_num = 0;
}

Executive::~Executive()
{
}

void Executive::startMenu()
{
  std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
            << "                   Battleship\n"
            << "Enter the number of ships(You may have up to 5 ships): \n";
  std::cin >> ship_num;
}

bool Executive::transfor(string x)
{
  
}

void Executive::testrun()
{
  int num;
  int x, y, z;
  cout << "num:";
  cin >> num;
  one.setnum(num);
  one.print();
  while (!one.IsAllMarked())
  {
    cout << "row";
    cin >> x;
    cout << "col";
    cin >> y;
    cout << "1.up 2.down 3.left 4.right";
    cin >> z;
    try
    {
      one.placement(x - 1, y - 1, z);
    }
    catch (const std::runtime_error &e)
    {
      cout << "enter a correct direction!" << endl;
    }
    one.print();
  }
}

