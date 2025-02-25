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

#ifndef ATTRIBUTE_STORE_HELPER_H
#define ATTRIBUTE_STORE_HELPER_H

// Includes from this component
#include "attribute_store.h"

// Generic includes
#include <stdbool.h>

// Type that we use to represent "any" number
typedef float number_t;

/**
 * @defgroup attribute_store_value_helpers Attribute Store Value Helpers
 * @ingroup attribute_store
 * @brief Helper functions to perform actions on the attribute store.
 *
 * This module contains various helper function to ease the access of the
 * attribute store.
 *
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Indicate whether a value is defined in the attribute store.
 *
 * @param node        The Attribute store node under
 *                    which the value must be retrieved
 * @param value_state The value_state to retrieve
 *
 * @returns true  If the value is defined (its size > 0)
 * @returns false If the value is undefined (its size == 0)
 */
bool attribute_store_is_value_defined(
  attribute_store_node_t node, attribute_store_node_value_state_t value_state);

/**
 * @brief Indicate whether reported and desired values are matched in the attribute store.
 *
 * @param node        The Attribute store node under
 *                    which the value must be retrieved
 *
 * @returns true  If the values are matched
 * @returns false If the value are unmatched
 */
bool attribute_store_is_value_matched(attribute_store_node_t node);

/**
 * @brief Set the Desired value to the same as the Reported value.
 *
 * @param node        The Attribute store node for which DESIRED
 *                    must be aligned to REPORTED
 *
 * @returns sl_status_t
 */
sl_status_t
  attribute_store_set_desired_as_reported(attribute_store_node_t node);

/**
 * @brief Set the Reported value to the same as the Desired value.
 *
 * @param node        The Attribute store node for which REPORTED
 *                    must be aligned to DESIRED
 *
 * @returns sl_status_t
 */
sl_status_t
  attribute_store_set_reported_as_desired(attribute_store_node_t node);

/**
 * @brief Set the Reported value to "undefined" (0 size no value)
 *
 * @param node        The Attribute store node for which REPORTED
 *                    must be set to nothing
 */
void attribute_store_undefine_reported(attribute_store_node_t node);

/**
 * @brief Set the Reported value of an Attribute Store node
 *
 * @param node        The Attribute store node for which REPORTED
 *                    must be updated
 * @param value       A pointer to a variable containing
 *                    the data to be written for the node.
 * @param value_size  The number of bytes to read from the value pointer.
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t attribute_store_set_reported(attribute_store_node_t node,
                                         const void *value,
                                         uint8_t value_size);

/**
 * @brief Reads the reported value of an attribute store node
 *
 * @param node          The Attribute store node under
 *                      which the value must be retrieved
 * @param value         Pointer where to copy the value
 * @param expected_size  The size of the pointer of read_value
 *
 * @returns SL_STATUS_OK    if the read value has the expected size and
 *                          has been copied to the pointer.
 * @returns SL_STATUS_FAIL  if the value is undefined, has not the expected
 *                          size or has not been copied to the pointer.
 */
sl_status_t attribute_store_get_reported(attribute_store_node_t node,
                                         void *value,
                                         size_t expected_size);

/**
 * @brief Sets a numerical value for an Attribute Store node
 *
 * Note: The storage type will be taken from Attribute Store registration
 * The default type will be int32_t is no registration has been made for a
 * given attribute
 *
 * @param node          The Attribute store node to set
 * @param value         Value to set
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t attribute_store_set_reported_number(attribute_store_node_t node,
                                                number_t value);

/**
 * @brief Sets a numerical value for an Attribute Store node
 *
 * Note: The storage type will be taken from Attribute Store registration
 * The default type will be int32_t is no registration has been made for a
 * given attribute
 *
 * @param node          The Attribute store node to set
 * @param value         Value to set
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t attribute_store_set_desired_number(attribute_store_node_t node,
                                               number_t value);

/**
 * @brief Gets a numerical value from an Attribute Store node
 *
 * Note: The storage type will be taken from Attribute Store registration
 * The default type will be int32_t is no registration has been made for a
 * given attribute
 *
 * @param node          The Attribute store node to get
 *
 * @returns Reported value found in the attribute store.
 *          Returns FLT_MIN if no value is defined or an error occured reading the
 *          value.
 */
number_t attribute_store_get_reported_number(attribute_store_node_t node);

/**
 * @brief Gets a numerical value from an Attribute Store node
 *
 * Note: The storage type will be taken from Attribute Store registration
 * The default type will be int32_t is no registration has been made for a
 * given attribute
 *
 * @param node          The Attribute store node to get
 *
 * @returns Desired value found in the attribute store.
 *          Returns FLT_MIN if no value is defined or an error occured reading the
 *          value.
 */
number_t attribute_store_get_desired_number(attribute_store_node_t node);

/**
 * @brief Safely copies a String in the Attribute Store
 *
 * @param node          The Attribute store node under
 *                      which the value must be written
 * @param string        C char array containing a String
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t attribute_store_set_reported_string(attribute_store_node_t node,
                                                const char *string);

/**
 * @brief Safely copies a String in the Attribute Store
 *
 * @param node          The Attribute store node under
 *                      which the value must be written
 * @param string        C char array containing a String
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t attribute_store_set_desired_string(attribute_store_node_t node,
                                               const char *string);

/**
 * @brief Safely retrieves a String from the Attribute Store
 *
 *
 * @param node          The Attribute store node where a string is saved.
 * @param string [out]  C char array pointer where the string data will be copied
 *                      NULL termination is guaranteed.
 * @param maximum_size  Capacity of the string pointer
 *
 * @returns SL_STATUS_OK if the entire string was retrived. ("" string would work)
 * @returns SL_STATUS_FAIL if the attribute does not exist, value was undefined or
 * the string could not be copied.
 */
sl_status_t attribute_store_get_reported_string(attribute_store_node_t node,
                                                char *string,
                                                size_t maximum_size);

/**
 * @brief Safely retrieves a String from the Attribute Store
 *
 * @param node          The Attribute store node where a string is saved.
 * @param string [out]  C char array pointer where the string data will be copied
 *                      NULL termination is guaranteed.
 * @param maximum_size  Capacity of the string pointer
 *
 * @returns SL_STATUS_OK if the entire string was retrived. ("" string would work)
 * @returns SL_STATUS_FAIL if the attribute does not exist, value was undefined or
 * the string could not be copied.
 */
sl_status_t attribute_store_get_desired_string(attribute_store_node_t node,
                                               char *string,
                                               size_t maximum_size);

/**
 * @brief Safely retrieves a String from the Attribute Store
 *
 * @param node          The Attribute store node where a string is saved.
 * @param string [out]  C char array pointer where the string data will be copied
 *                      NULL termination is guaranteed.
 * @param maximum_size  Capacity of the string pointer
 *
 * @returns SL_STATUS_OK if the entire string was retrived. ("" string would work)
 * @returns SL_STATUS_FAIL if the attribute does not exist, value was undefined or
 * the string could not be copied.
 */
sl_status_t attribute_store_get_desired_else_reported_string(
  attribute_store_node_t node, char *string, size_t maximum_size);

/**
 * @brief Safely concatenate a string to a String attribute in the Attribute Store
 *
 * @param node          The Attribute store node under
 *                      which the value must be concatenated
 * @param string        C char array containing a String
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t
  attribute_store_concatenate_to_reported_string(attribute_store_node_t node,
                                                 const char *string);

/**
 * @brief Set the Desired value to "undefined" (0 size no value)
 *
 * @param node        The Attribute store node for which DESIRED
 *                    must be set to nothing
 */
void attribute_store_undefine_desired(attribute_store_node_t node);

/**
 * @brief Set the Desired value of an Attribute Store node
 *
 * @param node        The Attribute store node for which DESIRED
 *                    must be updated
 * @param value       A pointer to a variable containing
 *                    the data to be written for the node.
 * @param value_size  The number of bytes to read from the value pointer.
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 */
sl_status_t attribute_store_set_desired(attribute_store_node_t node,
                                        const void *value,
                                        uint8_t value_size);

/**
 * @brief Reads the desired value of an attribute store node
 *
 * @param node          The Attribute store node under
 *                      which the value must be retrieved
 * @param value         Pointer where to copy the value
* @param expected_size  The size of the pointer of read_value
 *
 * @returns SL_STATUS_OK    if the read value has the expected size and
 *                          has been copied to the pointer.
 * @returns SL_STATUS_FAIL  if the value is undefined, has not the expected
 *                          size or has not been copied to the pointer.
 */
sl_status_t attribute_store_get_desired(attribute_store_node_t node,
                                        void *value,
                                        size_t expected_size);

/**
 * @brief Reads the desired value of an attribute store node, or the reported if
 * desired is undefined.
 *
 * @param node          The Attribute store node under
 *                      which the value must be retrieved
 * @param value         Pointer where to copy the value
 * @param expected_size  The size of the pointer of read_value
 *
 * @returns SL_STATUS_OK    if the read value has the expected size and
 *                          has been copied to the pointer.
 * @returns SL_STATUS_FAIL  if the value is undefined, has not the expected
 *                          size or has not been copied to the pointer.
 */
sl_status_t attribute_store_get_desired_else_reported(
  attribute_store_node_t node, void *value, size_t expected_size);

/**
 * @brief Copy the value from a node to another.
 *
 * @param source_node       The node that contains a value to be copied to
 *                          another node.
 * @param destination_node  The node that the source_node's value will be copied
 *                          into.
 * @param value_state       The value state to be copied from source_node to
 *                          destination_node

 * @returns SL_STATUS_OK if the value_state value was copied from source_node
 *                       to destination_node. Empty value copy will be considered
 *                        successful.
 * @returns SL_STATUS_NOT_FOUND if one of the attribute store nodes does not exist
 * @returns SL_FAIL if the value cannot be copied
 *
 */
sl_status_t
  attribute_store_copy_value(attribute_store_node_t source_node,
                             attribute_store_node_t destination_node,
                             attribute_store_node_value_state_t value_state);

/**
 * @brief Read an arbitrary sized value from the attribute store
 * and writes it to a pointer.
 *
 * @param node          The Attribute store node under
 *                      which the value must be retrieved
 * @param value_state   The value_state to retrieve
 * @param read_value    A pointer where to copy the read
 *                      value from the attribute store.
* @param expected_size  The size of the pointer of read_value
 *
 * @returns SL_STATUS_OK    if the read value has the expected size and
 *                          has been copied to the pointer.
 * @returns SL_STATUS_FAIL  if the value is undefined, has not the expected
 *                          size or has not been copied to the pointer.
 */
sl_status_t
  attribute_store_read_value(attribute_store_node_t node,
                             attribute_store_node_value_state_t value_state,
                             void *read_value,
                             size_t expected_size);

/**
 * @brief Adds if missing and sets the value of the first child of a node with a given type.
 * and writes its reported value.
 *
 * If there is no child of the given type for the parent, it will be created.
 *
 * @param parent        The Attribute store node under
 *                      which the child's reported value must be written
 * @param type          The type of the child
 * @param value         A pointer to a variable containing
 *                      the data to be written for the node.
 * @param value_size    The number of bytes to read from the value pointer.
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value

 */
sl_status_t attribute_store_set_child_reported(attribute_store_node_t parent,
                                               attribute_store_type_t type,
                                               const void *value,
                                               uint8_t value_size);

/**
 * @brief Adds if missing and sets the value of the first child of a node with a given type.
 * and writes its desired value.
 *
 * If there is no child of the given type for the parent, it will be created.
 *
 * @param parent        The Attribute store node under
 *                      which the child's desired value must be written
 * @param type          The type of the child
 * @param value         A pointer to a variable containing
 *                      the data to be written for the node.
 * @param value_size    The number of bytes to read from the value pointer.
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value

 */
sl_status_t attribute_store_set_child_desired(attribute_store_node_t parent,
                                              attribute_store_type_t type,
                                              const void *value,
                                              uint8_t value_size);

/**
 * @brief Finds the reported value of the first child of a node with a given type.
 *
 * @param parent        The Attribute store node under
 *                      which the child's reported value must be read
 * @param type          The type of the child
 * @param value         A pointer to a variable containing
 *                      the data to be read from the node's child.
 * @param expected_size The expected size of the memory to be copied in
 *                      the value pointer
 *
 * @returns sl_status_t returned by @ref attribute_store_get_node_attribute_value
 */
sl_status_t attribute_store_get_child_reported(attribute_store_node_t parent,
                                               attribute_store_type_t type,
                                               void *value,
                                               size_t expected_size);

/**
 * @brief Adds and sets the reported value of the first child of a node with a
 * given type only if it did not exist.
 *
 * If the child already exists, it will not be created.
 *
 * @param parent        The Attribute store node under
 *                      which the child's reported value must be written
 * @param type          The type of the child
 * @param value         A pointer to a variable containing
 *                      the data to be written for the node.
 * @param value_size    The number of bytes to read from the value pointer.
 *
 * @returns sl_status_t returned by @ref attribute_store_set_node_attribute_value
 *          SL_STATUS_ALREADY_EXIST if the child was already present.
 */
sl_status_t attribute_store_set_child_reported_only_if_missing(
  attribute_store_node_t parent,
  attribute_store_type_t type,
  const void *value,
  uint8_t value_size);

/**
 * @brief Visit all nodes in the tree.
 *
 * This function visits all the attribute store nodes under the "top" node and
 * applies the function passed in parameter.
 * @param top First node to be visited
 * @param func function to execute
 */
void attribute_store_walk_tree(attribute_store_node_t top,
                               void (*function)(attribute_store_node_t));

/**
 * @brief Add multiple nodes to a parent if they are not already present.
 *
 * This is a helper function that will add  a list of nodes to the parent
 * if they are not already present.
 *
 * @param parent_node Parent node for the nodes to add.
 * @param attributes array of attribute types
 * @param count number of attributes to add.
 */
void attribute_store_add_if_missing(attribute_store_node_t parent_node,
                                    const attribute_store_type_t attributes[],
                                    uint32_t count);

/**
 * @brief Adds a child with a given reported value under a parent node, if
 * it does not already exist.
 *
 * This is a helper function that will add a child with a given reported value
 * if the child does not already exist.
 *
 * @param parent_node   Parent node.
 * @param type          Attribute Store type of the child node.
 * @param value         A pointer to a variable containing
 *                      the data to be set for the reported value
 * @param value_size    The number of bytes to read from the value pointer.
 * @returns Attribute Store Node ID of the created (or existing) node
 */
attribute_store_node_t
  attribute_store_emplace(attribute_store_node_t parent_node,
                          attribute_store_type_t type,
                          const void *value,
                          uint8_t value_size);

/**
 * @brief Adds a child with a given desired value under a parent node, if
 * it does not already exist.
 *
 * This is a helper function that will add a child with a given desired value
 * if the child does not already exist.
 *
 * @param parent_node   Parent node.
 * @param type          Attribute Store type of the child node.
 * @param value         A pointer to a variable containing
 *                      the data to be set for the desired value
 * @param value_size    The number of bytes to read from the value pointer.
 * @returns Attribute Store Node ID of the created (or existing) node
 */
attribute_store_node_t
  attribute_store_emplace_desired(attribute_store_node_t parent_node,
                                  attribute_store_type_t type,
                                  const void *value,
                                  uint8_t value_size);

/**
 * @brief Loop helper that register the same callback function for many attribute
 * types
 *
 * @param callback_function The function to invoke when the node's
 *                          value is updated.
 * @param types             Array of attribute types for which a
 *                          callback will be registered.
 * @param types_count       The number of elements in the types array.
 * @returns SL_STATUS_OK    If the callbacks were registered successfully.
 */
sl_status_t attribute_store_register_callback_by_type_to_array(
  attribute_store_node_changed_callback_t callback_function,
  const attribute_store_type_t types[],
  uint32_t types_count);

/**
 * @brief Removes all children of an attribute store node.
 *
 * This is a helper function that will make sure a node has no more children.
 *
 * @param node Node for which all the children should be deleted
 *
 * @returns SL_STATUS_OK if no more children, SL_STATUS_FAIL if an error occurred
 *          and a child could not be deleted.
 */
sl_status_t attribute_store_delete_all_children(attribute_store_node_t node);

#ifdef __cplusplus
}
#endif

/** @} end attribute_store_value_helpers */

#endif  //attribute_store_helper_H
