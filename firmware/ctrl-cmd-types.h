#ifndef CTRL_CMD_TYPES_H
#define CTRL_CMD_TYPES_H

#include <stdint.h>
#include "eeprom-types.h"

#define CTRL_MSG_HEADER_SIZE		2
#define CTRL_MSG_MAX_PAYLOAD_SIZE	16

struct ctrl_msg {
	uint8_t type;
	uint8_t length;
	uint8_t payload[CTRL_MSG_MAX_PAYLOAD_SIZE];
};

/* Input:  none
 * Output: struct device_descriptor
 */
#define CTRL_CMD_GET_DEVICE_DESCRIPTOR	0

/* Input:  struct struct ctrl_cmd_get_door_config
 * Output: struct door_config
 */
#define CTRL_CMD_GET_DOOR_CONFIG	10

/* Input:  struct struct ctrl_cmd_set_door_config
 * Output: none
 */
#define CTRL_CMD_SET_DOOR_CONFIG	11

/* Input:  struct ctrl_cmd_get_access_record
 * Output: struct access_record
 */
#define CTRL_CMD_GET_ACCESS_RECORD	20

/* Input:  struct ctrl_cmd_set_access_record
 * Output: none
 */
#define CTRL_CMD_SET_ACCESS_RECORD	21

/* Payload depend on the query */
#define CTRL_CMD_OK			0
/* Payload is an error code (int8_t) */
#define CTRL_CMD_ERROR			255

struct device_descriptor {
	uint8_t major_version;
	uint8_t minor_version;

	uint8_t num_doors;
	uint16_t num_access_records;
};

struct ctrl_cmd_get_door_config {
	uint8_t index;
};

struct ctrl_cmd_set_door_config {
	uint8_t index;
	struct door_config config;
};

struct ctrl_cmd_get_access_record {
	uint16_t index;
};

struct ctrl_cmd_set_access_record {
	uint16_t index;
	struct access_record record;
};

#endif /* CTRL_CMD_TYPES_H */
