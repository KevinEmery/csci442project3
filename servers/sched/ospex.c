#include "ospex.h"
#include "glo.h"

void OSSendPtab(void){
	
	printf("Scheduler: %d \n", our_message.m_source);
	
	struct pi pi_struct[NR_PROCS+NR_TASKS];

	struct proc process_table[NR_PROCS+NR_TASKS];
	sys_getproctab(&process_table);

	int i;
	for (i = 0; i < NR_PROCS + NR_TASKS; i++) {
		strcpy(pi_struct[i].p_name, process_table[i].p_name);
		pi_struct[i].p_endpoint = process_table[i].p_endpoint;
		pi_struct[i].p_priority = process_table[i].p_priority;
		pi_struct[i].p_cpu_time_left = process_table[i].p_cpu_time_left;
		pi_struct[i].p_rts_flags = process_table[i].p_rts_flags;
		pi_struct[i].p_user_time = process_table[i].p_user_time;
		pi_struct[i].p_sys_time = process_table[i].p_sys_time;
		pi_struct[i].p_cycles = process_table[i].p_cycles;
		pi_struct[i].p_times.enter_queue = process_table[i].p_accounting.enter_queue;
		pi_struct[i].p_times.time_in_queue = process_table[i].p_accounting.time_in_queue;
		pi_struct[i].p_times.dequeues = process_table[i].p_accounting.dequeues;
		pi_struct[i].p_times.ipc_sync = process_table[i].p_accounting.ipc_sync;
		pi_struct[i].p_times.ipc_async = process_table[i].p_accounting.ipc_async;
		pi_struct[i].p_times.preempted = process_table[i].p_accounting.preempted;	
	}
	
//	sys_vircopy(SELF, (vir_bytes) &pi_struct, our_message.m_source, (vir_bytes) our_message.m1_p1, sizeof(pi_struct));
}
