/** \addtogroup sys
 * @{
 */

/**
 * \defgroup clock Clock library
 *
 * The clock library is the interface between Contiki and the platform
 * specific clock functionality. The clock library performs a single
 * function: measuring time. Additionally, the clock library provides
 * a macro, CLOCK_SECOND, which corresponds to one second of system
 * time.
 *
 * \note The clock library need in many cases not be used
 * directly. Rather, the \ref timer "timer library" or the \ref etimer
 * "event timers" should be used.
 *
 * \sa \ref timer "Timer library"
 * \sa \ref etimer "Event timers"
 *
 * @{
 */

/*
 * Copyright (c) 2004, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 * $Id: clock.h,v 1.11 2009/01/24 15:20:11 adamdunkels Exp $
 */
#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "contiki-conf.h"

#ifdef __cplusplus
extern "C" {
#endif

#if 0 /* XXX problems with signedness and use in timer_expired(). #if:ed it out for now. */
/**
 * Check if a clock time value is less than another clock time value.
 *
 * This macro checks if a clock time value is less than another clock
 * time value. This macro is needed to correctly handle wrap-around of
 * clock time values.
 *
 */
#define CLOCK_LT(a, b) ((clock_time_t)((a) - (b)) < ((clock_time_t)(~((clock_time_t)0)) >> 1))
#endif /* 0 */

/**
 * Check if clock time t1 is less than or equal to clock time t2.
 *
 * Since clock_time_t may be an unsigned type, use this function for comparison.
 *
 * \see E.g., IETF RFC 1982 https://tools.ietf.org/rfc/rfc1982.txt.
 *
 * Return value is greater than 0 if \p t1 is equal to \p t2 or if t1
 * is less than \p t2 (modulo max clock_time).
 */
int clock_lte(clock_time_t t1, clock_time_t t2);

/**
 * Initialize the clock library.
 *
 * This function initializes the clock library and should be called
 * from the main() function of the system.
 *
 */
void clock_init(void);

/**
 * Get the current clock time.
 *
 * This function returns the current system clock time.
 *
 * \return The current clock time, measured in system ticks.
 */
#ifdef ZIPGW
unsigned long clock_time(void);
#else
CCIF clock_time_t clock_time(void);
#endif

/**
 * This is a asynchronous delay function.
 *
 * @attention Due to UNIFY running in the same thread as Z-Wave protocol, a vTaskDelay()
 * was not a good idea and this function is now returning immediately. No delays are allowed.
 *
 * @param d   Delay in seconds.
 */
void clock_delay(unsigned int d);

/**
 * A second, measured in system clock time.
 *
 * \hideinitializer
 */
#ifdef CLOCK_CONF_SECOND
#define CLOCK_SECOND CLOCK_CONF_SECOND
#else
#define CLOCK_SECOND (clock_time_t)32
#endif

int clock_fine_max(void);
unsigned short clock_fine(void);

CCIF unsigned long clock_seconds(void);

#ifdef __cplusplus
}
#endif

#endif /* __CLOCK_H__ */

/** @} */
/** @} */
