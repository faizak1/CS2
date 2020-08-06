/* Author: Faiza Khan
 * Last modified: 5/9/18
 * EZ: Compile with
   g++ drawing.cpp -lcurses
 
more about the NCURSES libary:
  http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html#COMPILECURSES

Recall that you can use command man to look up online manual, e.g.,
  man mvprintw
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

char ReadSelection (string optionName,int & dimension);

class Figure{
public:
   Figure (int ox, int oy):x(ox),y(oy)
   {
   }

   int get_x()
   {
      return x;
   }
   int get_y()
   {
      return y;
   }

   /* Move invoking object by the given displacement, erase 
      current drawing and display it in the new location
    */
   void Move(int dx,int dy)
   {
	Display (true);  // the actual figure type's Display function will be called, due to late binding
	x = x+dx;
        y = y+dy;
        Display (false); //the actual figure type's Display() will be called, due to late binding
   }

   /* Allow user to place invoking object via keyboard (r,l,u,d) */
   void Place()
   {

   	// move the invoking object, until the user selects ok 
	int dim;
	char direction; 
	do
	{
		direction = ReadSelection ("Direction",dim);  
		if (direction=='r')
			Move(2,0);
		else if (direction=='l')
			Move(-2,0);
		else if (direction=='u')
			Move(0,-2);
		else if (direction=='d')
			Move(0,2);
	
	} while (direction!='o'); //o means ok... 
   }

   virtual void Edit()=0; 
   //This function is virtual, meaning that compiler needs to defer the binding to runtime, i.e., it waits until running time to decide which version of the function to be called.

   virtual void Display(bool)=0;
   // This function is virtual, meaning that compiler needs to defer the binding to runtime, i.e., it waits until running time to decide which version of the function should be called. 

private: 
   int x,y; // position of the figure 
};

//class Ractangle 
//Derived from parent Figure. It knows how to Display and Edit a Rectangle. It implements the ur evirtual functions that were declared in the abstract 
//Figure class.

class Rectangle: public Figure{
 public:
   Rectangle (int x_o,int y_o, int w=2, int h=2, char symbol='*'):Figure(x_o,y_o)
   {
      width = w;
      height = h;
      c= symbol;
   }
   //Edit()
   //  Rereads the character, height and width of the Rectangle
   void Edit()
   {
	int dim;

        c = ReadSelection ("Character",dim);

	//Read width and height... 
	ReadSelection ("height",height);
	ReadSelection ("width",width);
   }
	
   //Display(bool erase)
   //   Displays the Rectangle using the character, height and width.	

   void Display (bool erase=false)
   {
		char str[256];
		int x = get_x();
		int y = get_y();
     
		// fill str with a line of character c 
		// If erase is true, fill str with a line of space character (
		//  to erase the current drawing). 
		for (int i=0;i<width;i++)
			str[i] = (erase? ' ': c);
		// The above statement uses the conditional operator (?:), and is equivalent 
		// to: 
		//   if (erase)
		//       str[i] = ' ';
		//   else
		//       str[i] = c; 

		str[width]='\0'; //terminating character 
    
		for (int j=0;j<height;j++)
		{
			move (y+j,x); //move cursor to (x, y+j) 
			printw (str);  //display str in the current pos
	
		}
   }

  
private:
   char c;
   int width;
   int height;
};

// class Triangle
// Derived from parent Figure. It knows how to Display and Edit a Triangle.
// It implements the pure virtual functions that were declared in the abstract Figure class. 
class Triangle : public Figure
{
	public :
	Triangle (int x_o,int y_o, int s = 2, char symbol='*'):Figure(x_o,y_o)
   	{
       		s = side_length;
       		c= symbol;
    	}

	// reads the character and side length
	void Edit()
    	{
        	 int dim;
 
         	c = ReadSelection ("Character",dim);
         	ReadSelection ("side_length",side_length);


   	}

	// Display (bool erase)
	// Displays the Triangle using the character and side length
	void Display (bool erase=false)
    	{
                 char str[256];
                 int x = get_x();
                 int y = get_y();
 
	
                 // fill str with a line of character c 
                 // If erase is true, fill str with a line of space character (
                 //  to erase the current drawing). 
                 for(int i = 0; i < side_length; i++)
		 {		
			 str[i] = (erase? ' ': c);
		 }
                // The above statement uses the conditional operator (?:), and is equivalent 
                 // to: 
                 //   if (erase
                 //       str[i] = ' ';
                 //   else
                 //       str[i] = c; 
 
                 str[side_length]='\0'; //terminating character 
                 for (int j=0;j<side_length;j++)
                 {
                         move (y+j, x); //move cursor to (x, y+j) 
                         printw (str);  //display str in the current pos
			 str[side_length-j-1] = '\0';//remove last character after every line in order to create upside down triangle	
			 
    		}
	}


	private:
	char c;
	int side_length;


};

/* Display menu for the given option, read user input and return 
 *  user selection (via return value and pass-by-reference parameter
 @param optionName: the name of the option
 @param dimension: used to return user's integer input (height, width...)
 @return value: a character conresponds to user's selection
 @postcondition: The menu will be displayed in the center and bottom
     of the window.
*/
char ReadSelection (string optionName,int & dimension)
{
   int row, col;
   char ch;

   // Obtain the size of the window
   getmaxyx (stdscr, col, row);   

   // WE are displaying the menu starting at the following position in our window
   // ( (row-10)/2, col-4 ): bottom and middle part of the window... 

   // clear original text in the given position, by display an line of spaces... 
   mvprintw (col-4, (row-10)/2, "                                                   ");

   // display menu based upon the menu type
   if (optionName=="Direction")
   {
       mvprintw (col-4, (row-10)/2, "Right (r), Left(l), Up (u), Down (d), Ok (o):");

       noecho();   // no echo while we move the figure around 

       do {
         ch = getch();
       } while (ch!='r' && ch!='l' && ch!='u' && ch!='d' && ch!='o');

      echo(); //turn the echo mode back on... 
   } 
   else if (optionName=="Shape")
   {
		mvprintw (col-4, (row-10)/2, "Rectangle (R), Triangle(T), GoBack (B):");
		do {
			ch = getch();
		} while (ch!='R' && ch!='T' && ch!='B');

   } 
   else if (optionName=="Character")
   {
		mvprintw (col-4, (row-10)/2, "Character to use: ");
		ch = getch();
   } 
   else if (optionName=="width" || optionName=="height" || optionName=="side_length")
   {
      mvprintw (col-4, (row-10)/2,"Enter %s, press enter:", optionName.c_str());
	//c_str is a member function of string class, it returns a 
	//c string .. 


      // Turn buffering on, so user can use backspace/delete to modify input until Enter key is pressed
      nocbreak();

      // When enter is pressed, user input is parsed and read...
      do {
         scanw ("%d", &dimension);  //EZ: scanf input buffer to read an int value into dimension
      } while (dimension<0);

	//GO back to no buffering  mode
      cbreak();    
     
   }

   return ch; 
 
}

/* Redraw list of Figures 
 @param listFigs: the array of pointers to figure object
 @param num: the length of array listFigs
 @precondition: listFigs has been filled with the given 
  number of pointers to different Figure object (including 
  Rectangle, Triangle, or other)
 @postcondition: all figures have been redrawn 
*/

void RedrawAll (Figure * listFigs[], int num)
{
    for (int i=0;i<num;i++)
	listFigs[i]->Display(false);
}


int main()
{
	char d;
	WINDOW * wnd;
	int x,y;
	int dim;
	char shape;
  
        Figure * listFig[20]; //used to store pointers to up to 20 figures 

	wnd = initscr();
	cbreak(); // do not wait for enter key pressed to process input 

	for (int i=0;i<20;)
	{
		x=5; //default position of a figure 
		y=5;

		//add a new figure to the window 
		shape = ReadSelection("Shape",dim);
		
		if (shape == 'B')
			break;
		if (shape == 'R') 
			listFig[i] = new Rectangle (x,y);
		else if (shape =='T')
		{
			//Dynamically allocate a Triangle object and let curFig point to it
			// Todo 
			listFig[i] = new Triangle(x,y);
		}
	

		// Configure the figure 
		listFig[i]->Edit ();
			
		listFig[i]->Display(false);

   		// move the current figure, until the user selects ok 
   		listFig[i]->Place();

		i++;

		//redraw all figures ... 
		RedrawAll (listFig,i);

	}

	endwin();

}
