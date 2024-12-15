#include "stdint.h"


#define __weak    __attribute__ ((weak, alias("_Default_Handler")));



int main(void);
void _reset_handler(void);
void _Default_Handler(void);
void _NMI_handler(void) __weak;
void _HardFault_handler(void) __weak;
void _MemManage_handler(void) __weak;
void _BusFault_handler(void) __weak;
void _UsageFault_handler(void) __weak;
void _Reserved_handler(void) __weak;
void _SVCall_Handler(void) __weak;
void _DebugMonitor_Handler(void) __weak;
void _PendSV_Handler(void) __weak;
void _SysTick_Handler(void) __weak;
void _IRQ0(void) __weak;
void _IRQ1(void) __weak;
void _IRQ2(void) __weak;



extern uint32_t _Stack_Top ;
extern uint32_t _E_Text ;
extern uint32_t _S_Data ;
extern uint32_t _E_Data ;
extern uint32_t _S_Bss ;
extern uint32_t _E_Bss ;


uint32_t victors[] __attribute__ ((section(".vectors")))= 
{
	(uint32_t)&_Stack_Top,
	(uint32_t)&_reset_handler,
	(uint32_t)&_NMI_handler,
	(uint32_t)&_HardFault_handler,
	(uint32_t)&_MemManage_handler,
	(uint32_t)&_BusFault_handler,
	(uint32_t)&_UsageFault_handler,
	(uint32_t)&_Reserved_handler,
	(uint32_t)&_Reserved_handler,
	(uint32_t)&_Reserved_handler,
	(uint32_t)&_Reserved_handler,
	(uint32_t)&_SVCall_Handler,
	(uint32_t)&_DebugMonitor_Handler,
	(uint32_t)&_PendSV_Handler,
	(uint32_t)&_SysTick_Handler,
	(uint32_t)&_IRQ0,
	(uint32_t)&_IRQ1,
	(uint32_t)&_IRQ2,
};

void _reset_handler(void)
{
	//copy data from flash to ram
	uint32_t Data_Size = (unsigned char*)&_E_Data -(unsigned char*)&_S_Data ;
	unsigned char* P_SRC = (unsigned char*)&_E_Text ;
	unsigned char* P_DST = (unsigned char*)&_S_Data ; 
	uint32_t i = 0;
	for(i = 0; i < Data_Size ; i++)
	{
		*((unsigned char*)P_DST++) =  *((unsigned char*)P_SRC++) ; 
	}
	// Init .bss with 0 
	uint32_t Bss_Size = (unsigned char*)&_E_Bss -(unsigned char*)&_S_Bss ;
	P_DST = (unsigned char*)&_S_Bss ;
	for(i = 0; i < Data_Size ; i++)
	{
		*((unsigned char*)P_DST++) =  0 ; 
	}
	//Jump to main fuction.		
	main();
}

void _Default_Handler(void)
{
	_reset_handler();
}


