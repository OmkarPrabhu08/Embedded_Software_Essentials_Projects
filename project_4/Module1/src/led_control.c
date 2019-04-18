/*
 * led_control.c
 *
 *  Created on: 03-May-2017
 *      Author: Omkar
 */

#include "led_control.h"


void red_on(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;

		TPM2_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM2_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable portb clock
		PORTB_PCR18 = PORT_PCR_MUX(3);//pinmux

		PTB_BASE_PTR->PDDR = 1<<18;

		TPM2_CnSC(0) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM2_CnV(0) |= TPM2_MOD/8;

}
void red_off(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;

		TPM2_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM2_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable portb clock
		PORTB_PCR18 = PORT_PCR_MUX(3);//pinmux

		PTB_BASE_PTR->PDDR = 1<<18;

		TPM2_CnSC(0) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM2_CnV(0) = 0;

}
void green_on(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;

		TPM2_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM2_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable portb clock
		PORTB_PCR19 = PORT_PCR_MUX(3);//pinmux

		PTB_BASE_PTR->PDDR = 1<<19;

		TPM2_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM2_CnV(1) |= TPM2_MOD/8;

}
void green_off(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;

		TPM2_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM2_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable portb clock
		PORTB_PCR19 = PORT_PCR_MUX(3);//pinmux

		PTB_BASE_PTR->PDDR = 1<<19;

		TPM2_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM2_CnV(1) = 0;

}
void blue_on(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;

		TPM0_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM0_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;//enable portb clock
		PORTD_PCR1 = PORT_PCR_MUX(4);//pinmux

		PTD_BASE_PTR->PDDR = 1<<1;

		TPM0_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM0_CnV(1) |= TPM0_MOD/8;

}
void blue_off(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;

		TPM0_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM0_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;//enable portb clock
		PORTD_PCR1 = PORT_PCR_MUX(4);//pinmux

		PTD_BASE_PTR->PDDR = 1<<1;

		TPM0_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM0_CnV(1) = 0;

}
void red_brightness(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;

		TPM2_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM2_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable portb clock
		PORTB_PCR18 = PORT_PCR_MUX(3);//pinmux

		PTB_BASE_PTR->PDDR = 1<<18;

		TPM2_CnSC(0) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM2_CnV(0) |= TPM2_MOD/(128/(*Command->data));

}
void green_brightness(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM2_MASK;

		TPM2_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM2_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable portb clock
		PORTB_PCR19 = PORT_PCR_MUX(3);//pinmux

		PTB_BASE_PTR->PDDR = 1<<19;

		TPM2_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM2_CnV(1) |= TPM2_MOD/(128/(*Command->data));

}
void blue_brightness(CI_Msg *Command)
{
	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock
		SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;

		TPM0_SC |= (TPM_SC_CMOD(1) | TPM_SC_PS(1));
		TPM0_MOD = 60000;

		SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;//enable portb clock
		PORTD_PCR1 = PORT_PCR_MUX(4);//pinmux

		PTD_BASE_PTR->PDDR = 1<<1;

		TPM0_CnSC(1) = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
		TPM0_CnV(1) |= TPM0_MOD/(128/(*Command->data));

}
