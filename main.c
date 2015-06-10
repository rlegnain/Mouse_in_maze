
#include<stdio.h>


const int ROWS = 6;
const int COLS = 6;

char maze [ROWS][COLS]= {
							   {' ' , '=' , '=' , '=' , '=' , '='},
				   	     	   {' ' , ' ' , ' ' , ' ' , ' ' , '='},
				   	     	   {'=' , ' ' , '=' , '=' , '=' , '='},
				   	     	   {'=' , ' ' , ' ' , ' ' , '=' , '='},
				   	     	   {' ' , ' ' , '=' , '=' , ' ' , ' '},
				   	     	   {'=' , ' ' , ' ' , ' ' , ' ' , '='}
};

int x_start  = 4;
int y_start  = 1;
int x_cheese  = 5;
int y_cheese  = 4;

void plotMaze();
bool find_cheese(int, int);


int main(){

	maze [y_start][x_start] = 'M';    // M is Mouse
	maze [y_cheese][x_cheese] = 'C';  // C is Cheese
	plotMaze();
	find_cheese(x_start, y_start);
	plotMaze();

	return 0;
}



// ===================== Sub-functions


bool find_cheese(int x, int y){
    //plotMaze();

	if (maze[y][x]=='C'){          // return true if mouse found cheese (solved)

		printf("solved\n");
		return true;
	}
    maze[y][x] = 'M';   // mark the visited place by M

	// Recursively search for our goal.
	if (x > 0 &&  (maze[y][x-1] == ' '  || maze[y][x-1] == 'C') &&  find_cheese(x - 1, y))
	{
	        return true;
	 }
	 if (x < COLS && (maze[y][x+1] == ' '  || maze[y][x+1] == 'C') && find_cheese(x + 1, y))
	 {
	        return true;
	 }
	    if (y > 0 && (maze[y-1][x] == ' '  || maze[y-1][x] == 'C')  &&  find_cheese(x, y-1))
	 {
	        return true;
	 }
	 if (y < ROWS && (maze[y+1][x] == ' '  || maze[y+1][x] == 'C')  &&  find_cheese(x, y+1))
	 {
	        return true;
	 }

	 maze[y][x] = ' ';   // unmark the invalid path

	 // plotMaze();
	 return false;
}



// ==================================
void plotMaze(){
	int i,j;
	for (i=0;i<6;i++){
		for (j=0;j<6;j++){
			printf("%c",maze[i][j]);
		}
		printf("\n");
	}
}

