#include <stdlib.h>
#include "myLib.h"
#include "game.h"

// Prototypes
void initialize();

// State Prototypes
// TODO 1.2: Add your state and state transition function prototypes here
void start();
void goToStart();
void game();
void goToGame();
void pause();
void goToPause();
void win();
void goToWin();
void lose();
void goToLose();

// States
enum {START, GAME, PAUSE, WIN, LOSE};
int state;


// Button Variables
unsigned short buttons;
unsigned short oldButtons;

// Random Seed
int seed;

int main() {

    initialize();

    while(1) {

        // Update button variables
        oldButtons = buttons;
        buttons = BUTTONS;

        // State Machine
        // TODO 1.0: Make the state machine here
        switch(state) {
            case START:
                start();
                break;
            case GAME:
                game();
                break;
            case PAUSE:
                pause();
                break;
            case WIN:
                win();
                break;
            //check below
            case LOSE:
                lose();
                break;
            default:
                break;
        }


    }
}

// Sets up GBA
void initialize() {

    REG_DISPCTL = MODE3 | BG2_ENABLE;

    // TODO 1.3: Call your goToStart function here
    goToStart();

}

// TODO 1.1: Make your state and state transition functions
void start() {

    seed++;

    if (BUTTON_PRESSED(BUTTON_START)) {
        goToGame();
        // STILL TODO1.1: seeds the random num generator
        //srand() vs / & rand()
        srand(seed);
        rand();

        initGame();
    }
}
void goToStart() {
    fillScreen(CYAN);
    state = START;
}

void game() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToPause();
    }
    if (BUTTON_PRESSED(BUTTON_A)) {
        goToWin();
    }
    if (BUTTON_PRESSED(BUTTON_B)) {
        goToLose();
    }


}
void goToGame() {
    fillScreen(BLACK);
    state = GAME;
}
void pause() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToGame();
    }
    if (BUTTON_PRESSED(BUTTON_SELECT)) {
        goToStart();
    }
}
void goToPause() {
    fillScreen(GRAY);
    state = PAUSE;
}
void win() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToStart();
    }
}
void goToWin() {
    fillScreen(GREEN);
    state = WIN;
}
void lose() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        goToStart();
    }
}
void goToLose() {
    fillScreen(RED);
    state = LOSE;
}
