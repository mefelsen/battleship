/* -----------------------------------------------------------------------------
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
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
//#include <fstream>
//#include <limits>


class Executive
{
public:

    /** Default constructor
   @pre
   @post
   @param None  */
    Executive();

    /** destructor
     @pre
     @post
     @param None  */
    ~Executive();


    /** function to print the inital starting screen
     @pre  N/A
     @post Gives data to Flood class
     @param None  */

    void startMenu();

private:

      int rows;
      int cols;
      int ship_num;





};
#endif