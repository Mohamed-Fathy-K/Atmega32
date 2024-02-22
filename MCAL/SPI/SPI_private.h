

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define	SPCR							*((volatile u8*)0x2D)
#define SPCR_SPIE						7
#define SPCR_SPE						6
#define SPCR_DORD						5
#define SPCR_MSTR						4
#define SPI_MASTER						11
#define SPI_SLAVE						10
#define SPCR_CPOL						3
#define SPI_RISING_EDGE					10
#define SPI_FALLING_EDGE				11
#define SPCR_CPHA						2
#define	SPI_TOLROT						10
#define SPI_ROLTOT						11
#define SPCR_SPR1						1
#define SPCR_SPR0						0
#define DIVIDED_BY_4					7
#define DIVIDED_BY_16					1
#define DIVIDED_BY_64					2
#define DIVIDED_BY_128					3
#define DIVIDED_BY_2					4
#define DIVIDED_BY_8					5
#define DIVIDED_BY_32					6

#define	SPSR							*((volatile u8*)0x2E)
#define SPSR_SPIF						7
#define SPSR_WCOL						6
#define SPSR_SPI2X						0

#define	SPDR							*((volatile u8*)0x2F)


#endif /* SPI_PRIVATE_H_ */
