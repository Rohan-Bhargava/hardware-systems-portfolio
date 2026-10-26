#ifndef SYSTEM_BRINGUP_H
#define SYSTEM_BRINGUP_H

#include<stm32h5xx.h>

#ifndef DEFAULT_HW_TIMEOUT 
#define DEFAULT_HW_TIMEOUT 1000000U
#endif

#ifndef TIMEOUT_PWR_VOS 
#define TIMEOUT_PWR_VOS DEFAULT_HW_TIMEOUT 
#endif

#ifndef TIMEOUT_ICACHE
#define TIMEOUT_ICACHE DEFAULT_HW_TIMEOUT 
#endif

#ifndef TIMEOUT_FLASH
#define TIMEOUT_FLASH DEFAULT_HW_TIMEOUT 
#endif

void MySystemBringUp(void);

#endif