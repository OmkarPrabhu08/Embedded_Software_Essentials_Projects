#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_

#define SIM_SOPT2_MCGFLLCLK_MASK 0x1000000u

/*********************************************************************
*timer_config
*	description:This function initializes the timer for the KL25Z and
*	sets the values of the configuration registers 
*
*	parameters:N/A
*	returns:N/A
*********************************************************************/
void timer_config (void);


/*********************************************************************
*read_count
*	description:This function returns timer count value
*	
*
*	parameters:N/A
*	returns: int16_t TPM1_CNT
*********************************************************************/
int16_t read_count(void);

#endif /* INCLUDES_PROFILER_H_ */
