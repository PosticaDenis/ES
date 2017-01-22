#ifndef TASK_H
#define TASK_H
#include <stdint.h>

typedef struct Task {
	uint32_t delay;
	uint32_t interval;
	uint8_t enabled;
	void (*handler)();
} Task;

#endif
