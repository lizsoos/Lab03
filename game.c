#include <stdlib.h>
#include "myLib.h"
#include "game.h"

// Variables
// UNCOMMENT 2.1
PLAYER player;
// UNCOMMENT 3.0
// BULLET bullets[BULLETCOUNT];
BALL balls[BALLCOUNT];
int ballsRemaining;

// Initialize the game
void initGame() {

	// UNCOMMENT 2.4
	initPlayer();

	// UNCOMMENT 3.3
	// initBullets();

	initBalls();
	ballsRemaining = BALLCOUNT;
}

// Updates the game each frame
void updateGame() {

	// UNCOMMENT 2.5
	updatePlayer();

	// TODO 3.2: Update all the bullets


	// TODO 4.0: Update all the balls

}

// Draws the game each frame
void drawGame() {

	// UNCOMMENT 2.6
	drawPlayer();
	drawBar();

	// TODO 3.5: Draw all the bullets


	// TODO 4.1: Draw all the balls

}

// Draws the bar protecting the player
void drawBar() {
	drawRect(120, 0, 3, 240, RED);
}

// UNCOMMENT 2.2: All the way to the end of drawPlayer
// Initialize the player
void initPlayer() {

	player.row = 140;
	player.col = 118;
	player.oldRow = player.row;
	player.oldCol = player.col;
	player.cdel = 1;
	player.height = 10;
	player.width = 5;
	player.color = GREEN;
	player.bulletTimer = 20;

}

// Handle every-frame actions of the player
void updatePlayer() {

	// Move the player
	if (BUTTON_HELD(BUTTON_LEFT)
		&& player.col >= player.cdel) {

		player.col -= player.cdel;

	} else if (BUTTON_HELD(BUTTON_RIGHT)
		&& player.col + player.width - 1 < SCREENWIDTH - player.cdel) {

		player.col += player.cdel;

	}

	// Fire bullets
	if (BUTTON_PRESSED(BUTTON_A) && player.bulletTimer >= 20) {

		// UNCOMMENT 3.4
		// fireBullet();  // TODO 3.5: Back in main.c, comment out the state transition from game to win
		// player.bulletTimer = 0;
	}

	player.bulletTimer++;
}

// Draw the player
void drawPlayer() {

	drawRect(player.oldRow, player.oldCol, player.height, player.width, BLACK);
	drawRect(player.row, player.col, player.height, player.width, player.color);

	player.oldRow = player.row;
	player.oldCol = player.col;
}

// UNCOMMENT 3.1: All the way to the bottom of drawBullet
// // Initialize the pool of bullets
// void initBullets() {

// 	// TODO 3.0: Initialize the data for all of the bullets as per the instructions

// }

// // Spawn a bullet
// void fireBullet() {

// 	// TODO 3.3: Find the first inactive bullet, initialize it, and set it active

// }

// // Handle every-frame actions of a bullet
// void updateBullet(BULLET* b) {

// 	// TODO 3.1: If active, move the bullet upwards, and set it inactive if it goes off the screen

// }

// // Draw a bullet
// void drawBullet(BULLET* b) {

// 	if(b->active) {
// 		drawRect(b->oldRow, b->oldCol, b->height, b->width, BLACK);
// 		drawRect(b->row, b->col, b->height, b->width, b->color);
// 	} else if (!b->erased) {
// 		drawRect(b->oldRow, b->oldCol, b->height, b->width, BLACK);
// 		b->erased = 1;
// 	}
// 	b->oldRow = b->row;
// 	b->oldCol = b->col;
// }

// Initialize the balls
void initBalls() {

	for (int i = 0; i < BALLCOUNT; i++) {

		balls[i].height = 10;
		balls[i].width = 10;
		balls[i].row = rand() % 110;
		balls[i].col = rand() % 130 + 10;
		balls[i].oldRow = balls[i].row;
		balls[i].oldCol = balls[i].col;
		balls[i].rdel = 1;
		balls[i].cdel = 1;
		balls[i].color = BLUE;
		balls[i].active = 1;
		balls[i].erased = 0;
	}
}

// Handle every-frame actions of a ball
void updateBall(BALL* b) {

	if (b->active) {

		// Bounce the ball off the sides of the box
		if (b->row <= 0 || b->row + b->height-1 >= 120)
			b->rdel *= -1;
		if (b->col <= 0 || b->col + b->width-1 >= SCREENWIDTH-1)
			b->cdel *= -1;

		// Move the ball
		b->row += b->rdel;
		b->col += b->cdel;

		// Handle ball-bullet collisions
		// TODO 5.0: Loop through all the bullets, and if an active bullet is hitting this ball,
		//            put the bullet back in the pool, and update the score.



		// TODO 5.1: Back in main.c, transition to win state if ballsRemaining == 0
	}
}

// Draw a ball
void drawBall(BALL* b) {

	if(b->active) {
		drawRect(b->oldRow, b->oldCol, b->height, b->width, BLACK);
		drawRect(b->row, b->col, b->height, b->width, b->color);
	} else if (!b->erased) {
		drawRect(b->oldRow, b->oldCol, b->height, b->width, BLACK);
		b->erased = 1;
	}
	b->oldRow = b->row;
	b->oldCol = b->col;
}