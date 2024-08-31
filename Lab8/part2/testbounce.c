#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define RADIUS 20
#define VELOCITY_RANGE 5

int main() {
    srand(time(NULL));

    float xc = WIDTH / 2.0, yc = HEIGHT / 2.0; // Initial position
    float dx = (rand() % (2 * VELOCITY_RANGE + 1)) - VELOCITY_RANGE; // Initial x velocity
    float dy = (rand() % (2 * VELOCITY_RANGE + 1)) - VELOCITY_RANGE; // Initial y velocity

    gfx_open(WIDTH, HEIGHT, "Bounce Animation");

    while(1) {
        gfx_clear();

        // Move the circle
        xc += dx;
        yc += dy;

        // Bounce off the walls
        if (xc + RADIUS >= WIDTH || xc - RADIUS <= 0) {
            dx = -dx;
        }
        if (yc + RADIUS >= HEIGHT || yc - RADIUS <= 0) {
            dy = -dy;
        }

        // Draw the circle
        gfx_circle(xc, yc, RADIUS);
        gfx_flush();

        // Check for user input
        if (gfx_event_waiting()) {
            char c = gfx_wait();
            if (c == 1) { // Mouse click event
                xc = gfx_xpos();
                yc = gfx_ypos();
                dx = (rand() % (2 * VELOCITY_RANGE + 1)) - VELOCITY_RANGE; // New random x velocity
                dy = (rand() % (2 * VELOCITY_RANGE + 1)) - VELOCITY_RANGE; // New random y velocity
            }
        }

        // Sleep for smooth animation
        usleep(50000); // Adjust this value as needed for smoother or faster animation
    }

    return 0;
}