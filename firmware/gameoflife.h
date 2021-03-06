#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include "constants.h"
#include "keyboard.h"
#include "led.h"
#include "util.h"

/*
 * The index of the outermost cell in the grid.
 */
const uint8_t OUTERMOST_CELL = 13;

const uint8_t DELAY = 10;

/*
 * These are the colors of cells with different numbers of
 * neighbors. The 0:th entry is the color an alive cell has
 * when it has no alive neighbors, and the 8:th when it has 
 * eight alive neighbors.
 */
const Color CELL_COLORS[9] = {
    {0.0, 0.0, 1.0},
    {0.0, 0.5, 0.5},
    {0.0, 0.7, 0.3},
    {0.0, 1.0, 0.0},
    {0.3, 0.7, 0.0},
    {0.5, 0.5, 0.0},
    {0.7, 0.3, 0.0},
    {0.9, 0.1, 0.0},
    {1.0, 0.0, 0.0}
};

void gameoflife_setup(LED leds[][Ze::NUM_COLS], uint32_t cells[Ze::NUM_ROWS]);

void gameoflife_update(LED leds[][Ze::NUM_COLS], 
        Ze::Board* board, uint32_t cells[Ze::NUM_ROWS], uint64_t it);

#endif
