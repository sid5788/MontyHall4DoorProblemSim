#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GAMES 3000000
//Reference Code: http://rosettacode.org/wiki/Monty_Hall_problem#C
int main(void){
    unsigned i, j, k, choice, winsbystay=0, winsbyswitch=0, door[4];
    //initialize random seed.
    srand(time(NULL));
    for (i=0; i<GAMES; i++){
	    //give door 1 either a car or a goat randomly.
        door[0] = (!(rand()%2)) ? 1: 0;

    if(door[0]) {
        //if 1st door has car, give other doors goats.
       door[1]=door[2]=door[3]=0;
    } else {
       //give door 2 either a car or a goat randomly.
       door[1] = (!(rand()%2)) ? 1: 0;
       if(door[1]) {
          //if 2nd door got the car, give other doors goat
          door[2]=door[3]=0;
       }else {
	      //else, give 3rd door car or goat, give 4th door what's left.
          door[2] = (!(rand()%2)) ? 1:0;
          door[3] = (!door[2]) ? 1: 0;
       }
    }
	//choose a random door.
    choice = rand()%4;
    //if none of the other doors have the car then you will win by staying.
    if((!(door[((choice+1)%4)])) && (!(door[((choice+2)%4)])) &&  (!(door[((choice+3)%4)]))) winsbystay++;
    }
    //If we switch to any of the other doors chance of winning 
    winsbyswitch = 3000000 - winsbystay;
   //We can only switch to one of two doors so winsbyswitch divide by 2.
    winsbyswitch/=2;
    printf("\nAfter %u games.\n Staying Wins: %u .  That is %f%%. \n Switching Wins: %u .  That is %f%%. \n", GAMES, winsbystay, (float)winsbystay*100.0/(float)i, winsbyswitch, (float)winsbyswitch*100.0/(float)i);
return 1;
}
