#ifndef PWM_REG_H_
#define PWM_REG_H_

/* =====================================================================================*/
/*                                  INCLUDES                                            */
/* =====================================================================================*/
 #include "lstd.h"

/* =====================================================================================*/
/*                                  BASE Address                                        */
/* =====================================================================================*/
 #define PWM0_BASE            (0x40028000)

/* =====================================================================================*/
/*                                  TYPEDEF UNION                                       */
/* =====================================================================================*/
typedef union {

   struct{
   u32_t ENABLE:1;
   u32_t MODE:1;
   u32_t DEBUG:1;
   u32_t LOADUPD:1;
   u32_t CMPAUPD:1;
   u32_t CMPBUPD:1;
   u32_t GENAUPD:2;
   u32_t GENBUPD:2;
   u32_t DBCTLUPD:2;
   u32_t DBRISEUPD:2;
   u32_t DBFALLUPD:2;
   u32_t FLTSRC:1;
   u32_t MINFLTPER:1;
   u32_t LATCH:1;
   u32_t :13;
    }bits;

u32_t Register;

}PWMCTL_t;

typedef union {

    struct {
    u32_t ACTZERO:2;
    u32_t ACTLOAD:2;
    u32_t ACTCMPAU:2;
    u32_t ACTCMPAD:2;
    u32_t ACTCMPBU:2;
    u32_t ACTCMPBD:2;
    u32_t :20;

    }bits;

    u32_t Register;
}PWMGEN_t;

typedef union {
    struct{

        u32_t LOAD:16;
        u32_t :16;
    }bits;

    u32_t Register;

}PWMLOAD_t;

typedef union {
    struct{

        u32_t COMP:16;
        u32_t :16;
    }bits;

    u32_t Register;

}PWMCMP_t;

typedef union{

    struct{
        u32_t COUNT:16;
        u32_t :16;
    };
    u32_t Register;

}PWMCOUNT_t;

typedef union{
    struct{
        u32_t Module0:1;
        u32_t Module1:1;
        u32_t :30;
    };
    u32_t Register;
}RCGCPWM_t;

typedef union{

    struct{
        u32_t PWMChannelsOutputEnable:8;
        u32_t :24;
    };
    u32_t Register;
}PWMENABLE_t;

typedef union{

    struct{
       u32_t INTCNTZERO:1;
       u32_t INTCNTLOAD:1;
       u32_t INTCMPAU:1;
       u32_t INTCMPAD:1;
       u32_t INTCMPBU:1;
       u32_t INTCMPBD:1;
       u32_t :26;
    }bits;

    u32_t Register;
}PWMRIS_t;

typedef union{
    struct{
        u32_t INTPWM0:1;
        u32_t INTPWM1:1;
        u32_t INTPWM2:1;
        u32_t INTPWM3:1;
        u32_t :28;
    }bits;
    u32_t Register;
}PWMISC_t;
/* =====================================================================================*/
/*                                  Register MACROS                                     */
/* =====================================================================================*/

/********************************CONTROL REGISTERS********************************/
#define PWM0CTL_Reg   ((volatile PWMCTL_t *)(PWM0_BASE + 0x040))
#define PWM1CTL_Reg   ((volatile PWMCTL_t *)(PWM0_BASE + 0x080))
#define PWM2CTL_Reg   ((volatile PWMCTL_t *)(PWM0_BASE + 0x0C0))
#define PWM3CTL_Reg   ((volatile PWMCTL_t *)(PWM0_BASE + 0x100))

/********************************LOAD REGISTERS********************************/
#define PWM0LOAD_Reg  ((volatile PWMLOAD_t *)(PWM0_BASE + 0x050))
#define PWM1LOAD_Reg  ((volatile PWMLOAD_t *)(PWM0_BASE + 0x090))
#define PWM2LOAD_Reg  ((volatile PWMLOAD_t *)(PWM0_BASE + 0x0D0))
#define PWM3LOAD_Reg  ((volatile PWMLOAD_t *)(PWM0_BASE + 0x110))

/********************************COMPARE REGISTERS********************************/
#define PWM0CMPA_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x058))
#define PWM1CMPA_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x098))
#define PWM2CMPA_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x0D8))
#define PWM3CMPA_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x118))

#define PWM0CMPB_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x05C))
#define PWM1CMPB_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x09C))
#define PWM2CMPB_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x0DC))
#define PWM3CMPB_Reg  ((volatile PWMCMP_t *)(PWM0_BASE + 0x11C))

/********************************GENERATOR REGISTERS********************************/
#define PWM0GENA_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x060))
#define PWM1GENA_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x0A0))
#define PWM2GENA_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x0E0))
#define PWM3GENA_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x120))

#define PWM0GENB_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x064))
#define PWM1GENB_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x0A4))
#define PWM2GENB_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x0E4))
#define PWM3GENB_Reg ((volatile PWMGEN_t *)(PWM0_BASE + 0x124))

#define PWMENABLE_Reg ((volatile PWMENABLE_t* )(PWM0_BASE + 0x008))


#define PWM0COUNTER1_Reg ((volatile PWMCOUNT_t* )(PWM0_BASE +  0x054))
#define PWM0COUNTER2_Reg ((volatile PWMCOUNT_t* )(PWM0_BASE +  0x094))
#define PWM0COUNTER3_Reg ((volatile PWMCOUNT_t* )(PWM0_BASE +  0x0D4))
#define PWM0COUNTER4_Reg ((volatile PWMCOUNT_t* )(PWM0_BASE +  0x114))

#define PWM0RawInterruptStatus0 ((volatile PWMRIS_t*)(PWM0_BASE +  0x048))
#define PWM0RawInterruptStatus1 ((volatile PWMRIS_t*)(PWM0_BASE +  0x088))
#define PWM0RawInterruptStatus2 ((volatile PWMRIS_t*)(PWM0_BASE +  0x0C8))
#define PWM0RawInterruptStatus3 ((volatile PWMRIS_t*)(PWM0_BASE +  0x108))


#define PWM_InterruptStatusClear ((volatile PWMISC_t*)(PWM0_BASE +  0x01C))

/* =====================================================================================*/
/*                                  TYPEDEF struct                                      */
/* =====================================================================================*/

/*
typedef struct {

    PWMCTL_t  PWMCTL;
    u32_t PWMINTEN;
    u32_t PWMRIS;
    u32_t PWMISC;
    PWMLOAD_t PWMLOAD;
    u32_t PWMCOUNT;
    PWMCMP_t PWMCMPA;
    PWMCMP_t PWMCMPB;
    PWMGEN_t PWMGENA;
    PWMGEN_t PWMGENB;
    u32_t PWMDBCTL;
    u32_t PWMDBRISE;
    u32_t PWMDBFALL;
    u32_t PWMFLTSRC0;
    u32_t PWMFLTSRC1;
    u32_t PWMMINFLTPER;

}PWM_Generator_t;
*/

/* =====================================================================================*/
/*                                  MACROS                                              */
/* =====================================================================================*/

/*
 #define PWM_Generator0       ((volatile PWM_Generator_t*)(PWM0_base + 0x040))
 #define PWM_Generator1       ((volatile PWM_Generator_t*)(PWM0_base + 0x080))
 #define PWM_Generator2       ((volatile PWM_Generator_t*)(PWM0_base + 0x0C0))
 #define PWM_Generator3       ((volatile PWM_Generator_t*)(PWM0_base + 0x100))
*/



#endif /* PWM_REG_H_ */
