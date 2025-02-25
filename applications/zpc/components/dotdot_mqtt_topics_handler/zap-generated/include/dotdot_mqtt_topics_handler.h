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
 * @defgroup dotdot_mqtt_topics_handler DotDot MQTT Topics Handler
 * @ingroup dotdot_mqtt_topics_handler
 * @brief It reads the ZCL attribute state and publish the state to the MQTT interface.
 *        It also Parse WriteAttributes MQTT topic and update the desired state of
 *        writable ZCL attributes in the Attribute Store.
 *
 * @{
 */

// This file is generated by ZCL Advanced Platform generator. Please don't edit manually.
#ifndef DOTDOT_MQTT_TOPICS_HANDLER_H
#define DOTDOT_MQTT_TOPICS_HANDLER_H

#include <stdint.h>
#include <stdbool.h>

#include "sl_status.h"
#include "zap-types.h"
#include "attribute_store.h"
#include "zwave_unid.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
* @brief Initialize all dotdot mqtt topics hanlder module
​*
* @return sl_status_t SL_STATUS_OK on success
​*/
sl_status_t dotdot_mqtt_topics_handler_init(void);


#ifdef __cplusplus
}
#endif // __cplusplus
#endif // DOTDOT_MQTT_TOPICS_HANDLER_H
/** @} end dotdot_mqtt_topics_handler */
