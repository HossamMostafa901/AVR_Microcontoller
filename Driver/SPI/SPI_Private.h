/*
 * SPI_Private.h
 *
 *  Created on: Jun 17, 2023
 *      Author: DELL
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_SPCR  *((volatile u8*)0x2D)
#define SPI_SPSR  *((volatile u8*)0x2E)
#define SPI_SPDR  *((volatile u8*)0x2F)

#endif /* SPI_PRIVATE_H_ */
