/*
 * SPI_Interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: DELL
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Master_INIT(void);
void SPI_Slave_INIT(void);
u8 SPI_Transfer(u8 Data);

#endif /* SPI_INTERFACE_H_ */
