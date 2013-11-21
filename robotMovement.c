#include "robotMovement.h"

void initializePinOuts(){
    P1DIR |= BIT2;
    P1SEL |= BIT2;

    P1DIR |= BIT1;
    P1SEL |= BIT1;

    P2DIR |= BIT0;
    P2SEL |= BIT0;

    P2DIR |= BIT1;
    P2SEL |= BIT1;
}

void configureTimer(){
	TA0CTL &= ~(MC1|MC0);            // stop timer A0
	TA1CTL &= ~(MC1|MC0);            // stop timer A0

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;

	TA0CCR0 = 100;                // set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 50;

	TA1CCR0 = 100;
	TA1CCR1 = 50;

	TA0CCTL0 |= OUTMOD2|OUTMOD0;
	TA0CCTL1 |= OUTMOD2|OUTMOD0;

	TA1CCTL0 |= OUTMOD2|OUTMOD0;
	TA1CCTL1 |= OUTMOD2|OUTMOD0;

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;

}

void leftMotorBackward(){
	TA0CCTL1 &= ~OUTMOD1;
	TA0CCTL1 |= OUTMOD2|OUTMOD0;
	_delay_cycles(20000);
	TA0CCTL0 &= ~OUTMOD0;
	TA0CCTL0 |= OUTMOD2;
}

void leftMotorForward(){
	TA0CCTL0 &= ~OUTMOD1;
	TA0CCTL0 |= OUTMOD2|OUTMOD0;
	_delay_cycles(20000);
	TA0CCTL1 &= ~OUTMOD0;
	TA0CCTL1 |= OUTMOD2;
}

void rightMotorBackward(){
	TA1CCTL1 &= ~OUTMOD1;
	TA1CCTL1 |= OUTMOD2|OUTMOD0;
	_delay_cycles(20000);
	TA1CCTL0 &= ~OUTMOD0;
	TA1CCTL0 |= OUTMOD2;

}

void rightMotorForward(){
	TA1CCTL0 &= ~OUTMOD1;
	TA1CCTL0 |= OUTMOD2|OUTMOD0;
	_delay_cycles(20000);
	TA1CCTL1 &= ~OUTMOD0;
	TA1CCTL1 |= OUTMOD2;
}

void moveRobotForward(){
	leftMotorForward();
	rightMotorForward();
}

void moveRobotBackward(){
	leftMotorBackward();
	rightMotorBackward();
}

void turnRobotLeft(){
	leftMotorBackward();
	rightMotorForward();
}

void turnRobotRight(){
	leftMotorForward();
	rightMotorBackward();
}
