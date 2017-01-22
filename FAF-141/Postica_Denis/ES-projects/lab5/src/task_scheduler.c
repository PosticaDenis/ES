#include "task_scheduler.h"
#include "utils.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdlib.h>

#define MAX_TASKS 20
#define MILLIS_PER_CLOCK 10

uint8_t tasks_count = 0;
Task **tasks;
int32_t tasks_remaining_time[MAX_TASKS];

void TASK_SCHEDULER_start(){
	tasks = malloc(sizeof(Task*) * MAX_TASKS);

	// set prescaller to 8
	bit_set_1(&TCCR1B,CS11);

	// set mode CTC
	bit_set_1(&TCCR1B,WGM12);

	// enable interupts for 1A
	bit_set_1(&TIMSK,OCIE1A);


	TCNT1 = 0;
	OCR1A = 1250; // 0.01 ms

	sei();
}

void TASK_SCHEDULER_add(Task *task){
	if(tasks_count < MAX_TASKS - 1){
		tasks[tasks_count] = task;
		tasks_remaining_time[tasks_count] = task->delay;
		tasks_count++;
	}
}

ISR(TIMER1_COMPA_vect){
	int i;
	for(i = 0; i < tasks_count;i++){
		// avoid overflow
		if(tasks_remaining_time[i] >= 0){
			tasks_remaining_time[i] -= MILLIS_PER_CLOCK;
		}

		uint8_t should_run = tasks[i]->enabled && tasks_remaining_time[i] <= 0;
		if(should_run){
			tasks[i]->handler();
		}

		if(!tasks[i]->enabled || should_run){
			tasks_remaining_time[i] = tasks[i]->interval;
		}
	}
}
