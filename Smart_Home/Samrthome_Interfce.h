/*
 * Samrthome_Interfce.h
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */

#ifndef SAMRTHOME_INTERFCE_H_
#define SAMRTHOME_INTERFCE_H_

#define Numberofuser 3
#define Timer1_iNTA 0b10100010
#define Timer1_iNTB 0b00011010

#define MOTOR_CLOSED 1700
#define MOTOR_OPENED 600
#define Periodic_time 20000




void Servo_Int(void);
void Door_OPened(void);
void Door_CLosed(void);
void LightON(void);
void LightOFF(void);

#endif /* SAMRTHOME_INTERFCE_H_ */
