
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*	options
 *
 * 	SPI_MASTER
 * 	SPI_SLAVE
 *
 */
#define SPI_MASTER_SLAVE_SELCECTION	SPI_SLAVE

/*	options
 *
 *	SPI_RISING_EDGE
 *	SPI_FALLING_EDGE
 *
 */

#define	SPI_CLOCK_POLARITY		SPI_FALLING_EDGE


/*	options				DESCRIPTION
 *
 * 	SPI_ROLTOT			Receive On Leading edge Transmit On Trailing edge
 * 	SPI_TOLROT			Transmit On Leading edge Receive On Trailing edge
 */

#define SPI_CLOCK_PHASE			SPI_ROLTOT

/*	options
 *
 *	DIVIDED_BY_2
 * 	DIVIDED_BY_4
 * 	DIVIDED_BY_8
 * 	DIVIDED_BY_16
 * 	DIVIDED_BY_32
 * 	DIVIDED_BY_64
 * 	DIVIDED_BY_128
 *
 */


#define SPI_CLOCK_RATE_SELECTION		DIVIDED_BY_16
#endif /* SPI_CONFIG_H_ */
