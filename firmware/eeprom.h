#ifndef EEPROM_H
#define EEPROM_H

#include "eeprom-types.h"

#define ACCESS_RECORDS_SIZE \
	(EEPROM_SIZE - NUM_DOORS * sizeof(struct door_config))

#define NUM_ACCESS_RECORDS \
	(ACCESS_RECORDS_SIZE / sizeof(struct access_record))

struct eeprom_config {
	struct door_config door[NUM_DOORS];
	struct access_record access[NUM_ACCESS_RECORDS];
};

uint16_t eeprom_get_free_access_record_count(void);

int8_t eeprom_get_access_record(uint16_t id, struct access_record *rec);

int8_t eeprom_set_access_record(uint16_t id, const struct access_record *rec);

int8_t eeprom_get_access(uint8_t type, uint32_t key, uint8_t *doors);

int8_t eeprom_has_access(uint8_t type, uint32_t key, uint8_t door_id);

int8_t eeprom_set_access(uint8_t type, uint32_t key, uint8_t doors);

void eeprom_remove_all_access(void);

int8_t eeprom_get_door_config(uint8_t id, struct door_config *cfg);

int8_t eeprom_set_door_config(uint8_t id, const struct door_config *cfg);

#endif /* EEPROM_H */
