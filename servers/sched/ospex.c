#include "ospex.h"
#include "glo.h"
void OSSendPtab(){
	
//	printf("Scheduler (sched/ospex.c): %d \n", our_message.m_source);
//	printf("Scheduler int: %d \n", our_message.m1_i1);
	
	if (recordSched == 1) {
		struct pi pi_struct[NR_PROCS+NR_TASKS];
	
		struct proc process_table[NR_PROCS+NR_TASKS];
		sys_getproctab((struct proc *) &process_table);
		if (process_count < HISTORY) {
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
	
			sys_vircopy(SELF, (vir_bytes) &pi_struct, srcAddr, (vir_bytes) pInfoPtrs[process_count], sizeof(pi_struct));
			process_count++;
		}
		sys_getrunqhead(1, SELF);
//		u64_t cpuFreq = cpu_get_freq(0);
	}
}
