/******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

// This file is generated by ZCL Advanced Platform generator. Please don't edit manually.

/**
 *
 * @defgroup aoxpc_attribute_store_dotdot_attributes Auto-Generated attribute store helper functions for dotdot attributes
 * @ingroup aoxpc_attribute_store
 *
 * @brief This component provides helpers for to read and store dotdot
 * attributes to the attribute store
 *
 * @{
 */

#ifndef AOXPC_ATTRIBUTE_STORE_DOTDOT_ATTRIBUTES_H
#define AOXPC_ATTRIBUTE_STORE_DOTDOT_ATTRIBUTES_H

#if !defined(ATTRIBUTE_TYPE_MAP) && !defined(ATTRIBUTE_VALUE_MAP)
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// Dotdot MQTT definitions
#include "zap-types.h"

// Unify definitions
#include "sl_status.h"
#include "uic_typedefs.h"

// AoX Gecko SDK
#include "aoa_types.h"

// Unify components
#include "attribute_store.h"
#endif // !defined(ATTRIBUTE_TYPE_MAP) && !defined(ATTRIBUTE_VALUE_MAP)

////////////////////////////////////////////////////////////////////////////////
// Start of cluster AoXLocator
////////////////////////////////////////////////////////////////////////////////

// Attribute Defines for AoXLocator
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_REPORTING_MODE, 0xfd100001)
///< This represents the ReportingMode attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_POSITION_AND_ORIENTATION_VALID, 0xfd100002)
///< This represents the PositionAndOrientationValid attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_POSITION_AND_ORIENTATION, 0xfd100003)
///< This represents the PositionAndOrientation attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_AZIMUTH_MASK, 0xfd100005)
///< This represents the AzimuthMask attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ELEVATION_MASK, 0xfd100006)
///< This represents the ElevationMask attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ALLOW_LIST, 0xfd100007)
///< This represents the AllowList attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_AOX_MODE, 0xfd100008)
///< This represents the AoXMode attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ANTENNA_MODE, 0xfd100009)
///< This represents the AntennaMode attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ANTENNA_ARRAY, 0xfd10000a)
///< This represents the AntennaArray attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_PERIOD_SAMPLES, 0xfd10000b)
///< This represents the PeriodSamples attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ANGLE_FILTERING, 0xfd10000c)
///< This represents the AngleFiltering attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ANGLE_FILTERING_WEIGHT, 0xfd10000d)
///< This represents the AngleFilteringWeight attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ANGLE_CORRECTION_TIMEOUT, 0xfd10000e)
///< This represents the AngleCorrectionTimeout attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_ANGLE_CORRECTION_DELAY, 0xfd10000f)
///< This represents the AngleCorrectionDelay attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_CTE_MODE, 0xfd100010)
///< This represents the CTEMode attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_CTE_SAMPLING_INTERVAL, 0xfd100011)
///< This represents the CTESamplingInterval attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_CTE_LENGTH, 0xfd100012)
///< This represents the CTELength attribute in the DotDot AoXLocator cluster
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_LOCATOR_SLOT_DURATION, 0xfd100013)
///< This represents the SlotDuration attribute in the DotDot AoXLocator cluster


#if !defined(ATTRIBUTE_TYPE_MAP) && !defined(ATTRIBUTE_VALUE_MAP)
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// AoXLocator ReportingMode
/**
 * @brief Verifies if the DotDot AoXLocator ReportingMode is supported
 *
 * @returns true if ReportingMode is supported
 * @returns false if ReportingMode is not supported
 */
bool dotdot_is_supported_aox_locator_reporting_mode (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot ReportingMode reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_reporting_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t *value);


/**
 * @brief Set the DotDot ReportingMode reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_reporting_mode new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_reporting_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t new_reporting_mode);


// AoXLocator PositionAndOrientationValid
/**
 * @brief Verifies if the DotDot AoXLocator PositionAndOrientationValid is supported
 *
 * @returns true if PositionAndOrientationValid is supported
 * @returns false if PositionAndOrientationValid is not supported
 */
bool dotdot_is_supported_aox_locator_position_and_orientation_valid (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot PositionAndOrientationValid reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_position_and_orientation_valid(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  bool *value);


/**
 * @brief Set the DotDot PositionAndOrientationValid reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_position_and_orientation_valid new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_position_and_orientation_valid(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  bool new_position_and_orientation_valid);


// AoXLocator PositionAndOrientation
/**
 * @brief Verifies if the DotDot AoXLocator PositionAndOrientation is supported
 *
 * @returns true if PositionAndOrientation is supported
 * @returns false if PositionAndOrientation is not supported
 */
bool dotdot_is_supported_aox_locator_position_and_orientation (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot PositionAndOrientation reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_position_and_orientation(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  CoordinateAndOrientation *value);


/**
 * @brief Set the DotDot PositionAndOrientation reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_position_and_orientation new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_position_and_orientation(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  CoordinateAndOrientation new_position_and_orientation);


// AoXLocator AzimuthMask
/**
 * @brief Verifies if the DotDot AoXLocator AzimuthMask is supported
 *
 * @returns true if AzimuthMask is supported
 * @returns false if AzimuthMask is not supported
 */
bool dotdot_is_supported_aox_locator_azimuth_mask (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the number of elements in the DotDot AzimuthMask attribute
 *
 * @param unid     UNID to get value for
 * @param endpoint Endpoint to get value for
 * @returns Number of elements in the array. 0 if empty of non-existing.
 */
size_t dotdot_get_aox_locator_azimuth_mask_count(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AzimuthMask reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_azimuth_mask(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  MinMaxPair *value,
  size_t index);


/**
 * @brief Set the DotDot AzimuthMask reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * @param new_azimuth_mask_count Number of elements in new_azimuth_mask
 * @param new_azimuth_mask new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_azimuth_mask(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  size_t new_azimuth_mask_count,
  MinMaxPair* new_azimuth_mask
  );


// AoXLocator ElevationMask
/**
 * @brief Verifies if the DotDot AoXLocator ElevationMask is supported
 *
 * @returns true if ElevationMask is supported
 * @returns false if ElevationMask is not supported
 */
bool dotdot_is_supported_aox_locator_elevation_mask (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the number of elements in the DotDot ElevationMask attribute
 *
 * @param unid     UNID to get value for
 * @param endpoint Endpoint to get value for
 * @returns Number of elements in the array. 0 if empty of non-existing.
 */
size_t dotdot_get_aox_locator_elevation_mask_count(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot ElevationMask reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_elevation_mask(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  MinMaxPair *value,
  size_t index);


/**
 * @brief Set the DotDot ElevationMask reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * @param new_elevation_mask_count Number of elements in new_elevation_mask
 * @param new_elevation_mask new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_elevation_mask(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  size_t new_elevation_mask_count,
  MinMaxPair* new_elevation_mask
  );


// AoXLocator AllowList
/**
 * @brief Verifies if the DotDot AoXLocator AllowList is supported
 *
 * @returns true if AllowList is supported
 * @returns false if AllowList is not supported
 */
bool dotdot_is_supported_aox_locator_allow_list (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the number of elements in the DotDot AllowList attribute
 *
 * @param unid     UNID to get value for
 * @param endpoint Endpoint to get value for
 * @returns Number of elements in the array. 0 if empty of non-existing.
 */
size_t dotdot_get_aox_locator_allow_list_count(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AllowList reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_allow_list(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  char* value,
  size_t index);


/**
 * @brief Set the DotDot AllowList reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * @param new_allow_list_count Number of elements in new_allow_list
 * @param new_allow_list new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_allow_list(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  size_t new_allow_list_count,
  const char** new_allow_list
  );


// AoXLocator AoXMode
/**
 * @brief Verifies if the DotDot AoXLocator AoXMode is supported
 *
 * @returns true if AoXMode is supported
 * @returns false if AoXMode is not supported
 */
bool dotdot_is_supported_aox_locator_aox_mode (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AoXMode reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_aox_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t *value);


/**
 * @brief Set the DotDot AoXMode reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_aox_mode new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_aox_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t new_aox_mode);


// AoXLocator AntennaMode
/**
 * @brief Verifies if the DotDot AoXLocator AntennaMode is supported
 *
 * @returns true if AntennaMode is supported
 * @returns false if AntennaMode is not supported
 */
bool dotdot_is_supported_aox_locator_antenna_mode (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AntennaMode reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_antenna_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t *value);


/**
 * @brief Set the DotDot AntennaMode reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_antenna_mode new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_antenna_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t new_antenna_mode);


// AoXLocator AntennaArray
/**
 * @brief Verifies if the DotDot AoXLocator AntennaArray is supported
 *
 * @returns true if AntennaArray is supported
 * @returns false if AntennaArray is not supported
 */
bool dotdot_is_supported_aox_locator_antenna_array (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the number of elements in the DotDot AntennaArray attribute
 *
 * @param unid     UNID to get value for
 * @param endpoint Endpoint to get value for
 * @returns Number of elements in the array. 0 if empty of non-existing.
 */
size_t dotdot_get_aox_locator_antenna_array_count(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AntennaArray reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_antenna_array(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value,
  size_t index);


/**
 * @brief Set the DotDot AntennaArray reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * @param new_antenna_array_count Number of elements in new_antenna_array
 * @param new_antenna_array new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_antenna_array(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  size_t new_antenna_array_count,
  int8_t* new_antenna_array
  );


// AoXLocator PeriodSamples
/**
 * @brief Verifies if the DotDot AoXLocator PeriodSamples is supported
 *
 * @returns true if PeriodSamples is supported
 * @returns false if PeriodSamples is not supported
 */
bool dotdot_is_supported_aox_locator_period_samples (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot PeriodSamples reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_period_samples(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value);


/**
 * @brief Set the DotDot PeriodSamples reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_period_samples new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_period_samples(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t new_period_samples);


// AoXLocator AngleFiltering
/**
 * @brief Verifies if the DotDot AoXLocator AngleFiltering is supported
 *
 * @returns true if AngleFiltering is supported
 * @returns false if AngleFiltering is not supported
 */
bool dotdot_is_supported_aox_locator_angle_filtering (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AngleFiltering reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_angle_filtering(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  bool *value);


/**
 * @brief Set the DotDot AngleFiltering reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_angle_filtering new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_angle_filtering(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  bool new_angle_filtering);


// AoXLocator AngleFilteringWeight
/**
 * @brief Verifies if the DotDot AoXLocator AngleFilteringWeight is supported
 *
 * @returns true if AngleFilteringWeight is supported
 * @returns false if AngleFilteringWeight is not supported
 */
bool dotdot_is_supported_aox_locator_angle_filtering_weight (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AngleFilteringWeight reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_angle_filtering_weight(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  double *value);


/**
 * @brief Set the DotDot AngleFilteringWeight reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_angle_filtering_weight new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_angle_filtering_weight(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  double new_angle_filtering_weight);


// AoXLocator AngleCorrectionTimeout
/**
 * @brief Verifies if the DotDot AoXLocator AngleCorrectionTimeout is supported
 *
 * @returns true if AngleCorrectionTimeout is supported
 * @returns false if AngleCorrectionTimeout is not supported
 */
bool dotdot_is_supported_aox_locator_angle_correction_timeout (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AngleCorrectionTimeout reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_angle_correction_timeout(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value);


/**
 * @brief Set the DotDot AngleCorrectionTimeout reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_angle_correction_timeout new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_angle_correction_timeout(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t new_angle_correction_timeout);


// AoXLocator AngleCorrectionDelay
/**
 * @brief Verifies if the DotDot AoXLocator AngleCorrectionDelay is supported
 *
 * @returns true if AngleCorrectionDelay is supported
 * @returns false if AngleCorrectionDelay is not supported
 */
bool dotdot_is_supported_aox_locator_angle_correction_delay (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot AngleCorrectionDelay reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_angle_correction_delay(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value);


/**
 * @brief Set the DotDot AngleCorrectionDelay reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_angle_correction_delay new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_angle_correction_delay(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t new_angle_correction_delay);


// AoXLocator CTEMode
/**
 * @brief Verifies if the DotDot AoXLocator CTEMode is supported
 *
 * @returns true if CTEMode is supported
 * @returns false if CTEMode is not supported
 */
bool dotdot_is_supported_aox_locator_cte_mode (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot CTEMode reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_cte_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t *value);


/**
 * @brief Set the DotDot CTEMode reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_cte_mode new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_cte_mode(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  uint8_t new_cte_mode);


// AoXLocator CTESamplingInterval
/**
 * @brief Verifies if the DotDot AoXLocator CTESamplingInterval is supported
 *
 * @returns true if CTESamplingInterval is supported
 * @returns false if CTESamplingInterval is not supported
 */
bool dotdot_is_supported_aox_locator_cte_sampling_interval (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot CTESamplingInterval reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_cte_sampling_interval(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value);


/**
 * @brief Set the DotDot CTESamplingInterval reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_cte_sampling_interval new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_cte_sampling_interval(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t new_cte_sampling_interval);


// AoXLocator CTELength
/**
 * @brief Verifies if the DotDot AoXLocator CTELength is supported
 *
 * @returns true if CTELength is supported
 * @returns false if CTELength is not supported
 */
bool dotdot_is_supported_aox_locator_cte_length (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot CTELength reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_cte_length(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value);


/**
 * @brief Set the DotDot CTELength reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_cte_length new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_cte_length(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t new_cte_length);


// AoXLocator SlotDuration
/**
 * @brief Verifies if the DotDot AoXLocator SlotDuration is supported
 *
 * @returns true if SlotDuration is supported
 * @returns false if SlotDuration is not supported
 */
bool dotdot_is_supported_aox_locator_slot_duration (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot SlotDuration reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_locator_slot_duration(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t *value);


/**
 * @brief Set the DotDot SlotDuration reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_slot_duration new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_locator_slot_duration(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  int8_t new_slot_duration);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // !defined(ATTRIBUTE_TYPE_MAP) && !defined(ATTRIBUTE_VALUE_MAP)
////////////////////////////////////////////////////////////////////////////////
// Start of cluster AoXPositionEstimation
////////////////////////////////////////////////////////////////////////////////

// Attribute Defines for AoXPositionEstimation
DEFINE_ATTRIBUTE(DOTDOT_ATTRIBUTE_ID_AOX_POSITION_ESTIMATION_POSITION, 0xfd110001)
///< This represents the Position attribute in the DotDot AoXPositionEstimation cluster


#if !defined(ATTRIBUTE_TYPE_MAP) && !defined(ATTRIBUTE_VALUE_MAP)
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// AoXPositionEstimation Position
/**
 * @brief Verifies if the DotDot AoXPositionEstimation Position is supported
 *
 * @returns true if Position is supported
 * @returns false if Position is not supported
 */
bool dotdot_is_supported_aox_position_estimation_position (
  const aoa_id_t unid, dotdot_endpoint_id_t endpoint);

/**
 * @brief Gets the DotDot Position reported attribute value
 *
 * @param unid        UNID to get value for
 * @param endpoint    Endpoint to get value for
 * @param value       Pointer where the value will be copied
 * @returns sl_status_ok if the value was copied to the value pointer.
 */
sl_status_t dotdot_get_aox_position_estimation_position(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  EstimatedPosition *value);


/**
 * @brief Set the DotDot Position reported attribute, creates it if it does not exist
 *
 * @param unid UNID to set value on
 * @param endpoint endpoint to set value on
 * 
 * @param new_position new value to set
 * @returns sl_status_t SL_STATUS_OK on success
 */
sl_status_t dotdot_set_aox_position_estimation_position(
  const aoa_id_t unid,
  const dotdot_endpoint_id_t endpoint,
  EstimatedPosition new_position);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // !defined(ATTRIBUTE_TYPE_MAP) && !defined(ATTRIBUTE_VALUE_MAP)

#endif // AOXPC_ATTRIBUTE_STORE_DOTDOT_ATTRIBUTES_H
/** @} end aoxpc_attribute_store_dotdot_attributes */
