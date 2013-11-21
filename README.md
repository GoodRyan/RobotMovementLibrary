RobotMovementLibrary
====================

A library providing functions that allow for robot movement. This includes forward movement, backward movement, and left/right turns.

Functions
=========

void initializePinOuts() - Sets the proper pins as output and associates them with their corresponding clocks.

void configureTimer() - Configures the timers so that the duty cycle is 50% when set/reset mode is used, and inializes all TACCTL's to 101 or reset mode.

void leftMotorBackward() - Moves the left motor backward, this function is hidden from the user.

void leftMotorForward() - Moves the left motor forward, this function is hidden from the user.

void rightMotorBackward() - Moves the right motor backward, this function is hidden from the user.

void rightMotorForward()  - Moves the right motor forward, this function is hidden from the user.

void moveRobotForward() - Moves the robot forward using the rightMotorForward() and leftMotorForward() functions.

void moveRobotBackward() - moves the robot forward using the rightMotorBackward() and leftMotorBackward() functions.

void turnRobotLeft() - turns the robot left using the leftMotorBackward() and rightMotorForward() functions, allowing for a tight turn.

void turnRobotRight() - turns the robot right using the leftMotorForward() and rightMotorBackward() functions, allowing for a tight turn.
