/**
 * 27/07/2021
 * Module: Config
 * -----------------------------------------------------------------------------
 * Authors:
 * - Daniel Mohedano <https://github.com/danmohedano>
 * -----------------------------------------------------------------------------
 * Configuration parameters for the application
 */
#ifndef CONFIG_H
#define CONFIG_H

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1800
#define X_OFFSET (SCREEN_WIDTH / 2)
#define Y_OFFSET (SCREEN_HEIGHT / 2)

#define DT 0.001
#define SCALE 3.0
#define DISPLAY_DELAY 5

#define RECORDING_TIME_S 5
#define RECORDING_DT_S (RECORDING_TIME_S * DT)
#define RECORDING_DT_MS (RECORDING_TIME_S * DT * 1000)

#endif