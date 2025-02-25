/******************************************************************************
 * # License
 * <b>Copyright 2021 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

/**
 * @file zwapi_serial.h
 * @brief Serial Port API for the Z-Wave module.
 * Used for low level read/write functions to the serial port.
 */

#ifndef ZWAPI_SERIAL_H
#define ZWAPI_SERIAL_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// CLEANUP: Should really be private to zwapi, but zw_programmer.c and
// ZWFirmwareUpdate.c calls these functions directly.

/**
 * @brief Initialize the serial port to 115200 BAUD 8N1
 * @returns the file descriptor for the serial device.
 *
 * @zgw_name SerialInit
 */
int zwapi_serial_init(const char *serial_port);

/**
 * @brief De-Initialize the serial port.
 *
 * @zgw_name SerialClose
 */
void zwapi_serial_close(void);

/**
 * @brief Closes and re-initialize the last open serial port.
 * @returns the file descriptor for the serial device.
 *
 * @zgw_name SerialRestart
 */
int zwapi_serial_restart(void);

/**
 * @brief Reads a byte from the serial port device.
 * @param c char  to store data from serial port to.
 * @returns 0 if no characters are available, otherwise this returns 1
 * (length of the read data)
 *
 * @zgw_name SerialGetByte
 */
int zwapi_serial_get_byte(uint8_t *c);

/**
 * @brief Write a byte to serial port device.
 *
 * @zgw_name SerialPutByte
 */
void zwapi_serial_put_byte(uint8_t c);

/**
 * @brief Reads the output of the serial port device and stores the content in
 * a buffer.
 * @param c buffer to store data from serial port to.
 * @param len length of buffer.
 * @returns The length of the data copied in the buffer.
 *
 * @zgw_name SerialGetBuffer
 */
int zwapi_serial_get_buffer(uint8_t *c, int len);

/**
 * @brief Writes the content of a buffer to the serial port device.
 *
 * @param c buffer with data to write to serial port.
 * @param len length of data in buffer.
 *
 * @zgw_name SerialPutBuffer
 */
void zwapi_serial_put_buffer(uint8_t *c, int len);

/**
 * @brief Check the file descriptor for the serial device is available for I/O
 * operations.
 *
 * @returns true if the file is available, false if not or if an error occurred.
 *
 * @zgw_name SerialCheck
 */
bool zwapi_serial_is_file_available(void);

/**
 * @brief Flush the serial output if using buffered output.
 *
 * This function calls tcdrain, which waits that the TTY buffer data has been
 * written to the hardware.
 *
 * @zgw_name SerialFlush
 */
void zwapi_serial_drain_buffer(void);

#ifdef __cplusplus
}
#endif

#endif  // ZWAPI_SERIAL_H
