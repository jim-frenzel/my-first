/**********************************************************************
* © 2007 Microchip Technology Inc.
*
* FileName:        CANFunctions.h
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       PIC32
* Compiler:        MPLAB® XC32
*
* Revisions:      6/24/13 RWW - TArget Cerebot MX7ck using XC32 1.30
*
*                 October 26, 2014 - Added peripheral library 
*                 descriptions and removed magic numbers
*
************************************************************************/

#ifndef __CAN_FUNCTIONS_H__
#define __CAN_FUNCTIONS_H__

#include "plib.h"

    #define CAN_BUS_SPEED 250000
//  #define CAN_BUS_SPEED 500000

/* This is the CAN1 FIFO message area.	*/
    #define CAN1_CHANNELS       2
    #define CAN1_FIFO_BUFFERS   8
    #define CAN1_MSG_BUFF_SIZE  16
    #define CAN1_MSG_MEMORY  CAN1_CHANNELS*CAN1_FIFO_BUFFERS*CAN1_MSG_BUFF_SIZE
    BYTE CAN1MessageFifoArea[CAN1_MSG_MEMORY];

/* This is the CAN2 FIFO message area.	*/
    #define CAN2_CHANNELS       2
    #define CAN2_FIFO_BUFFERS   8
    #define CAN2_MSG_BUFF_SIZE  16
    #define CAN2_MSG_MEMORY  CAN2_CHANNELS*CAN2_FIFO_BUFFERS*CAN2_MSG_BUFF_SIZE
    BYTE CAN2MessageFifoArea[CAN2_MSG_MEMORY];

    #define SID_BIT_MASK      0x07FF   /* Bit masking for generating SID */
    #define EID_BIT_MASK      0x03FFFF  /* Bit masking for generating EID */

    #define SID_FILTER_MASK   0x07FF    /* 11 bit mask - all bits must match */
    #define EID_FILTER_MASK   0x01FFFFFFF /* 29 bit mask - all bits must match*/

    #define CAN_SID_MSG_1     0x0201  /* 11 bit SID */
    #define CAN_SID_MSG_4     0x0202  /* 11 bit SID */

#endif

/****************************************************************************
 * Function: void CAN1Init(void);
 * Description:
 *    This function initializes CAN1 module. It sets up speed, FIFOs,
 *    filters and interrupts. FIFO0 is set up for TX with 8 message
 * 	  buffers. FIFO1 is set up for RX with 8 message buffers. Filter 0
 * 	  is set with Mask 0 for EID 0x8004001. Only RXNEMPTY interrupt and
 *    RBIF interrupt is enabled.
 *
 * Precondition:  None.
 * Parameters:    None.
 * Return Values: None.
 * Remarks:       None.
 * Example:   CAN1Init();
  ***************************************************************************/
void CAN1Init(void);

/****************************************************************************
 *   Function:          void CAN2Init(void);
 *   Description:
 * 	This function initializes CAN1 module. It sets up speed, FIFOs,
 * 	filters and interrupts. FIFO0 is set up for TX with 8 message
 * 	buffers. FIFO1 is set up for RX with 8 message buffers. Filter 0
 * 	is set with Mask 0 for SID 0x0202. Only RXNEMPTY interrupt and
 * 	RBIF interrupt is enabled.
 *
 * Precondition:	None.
 * Parameters:  	None.
 * Return Values:	None.
 * Remarks:         None.
 * Example:   CAN2Init();
  ***************************************************************************/
void CAN2Init(void);

/****************************************************************************
 * Function:            void CAN1RxMsgProcess(void);
 * Description:
 * 	This function initializes CAN2 module. It sets up speed, FIFOs,
 * 	filters and interrupts. FIFO0 is set up for TX with 8 message
 * 	buffers. FIFO1 is set up for RX with 8 message buffers. Filter 0
 * 	is set with Mask 0 for SID 0x0201. Only RXNEMPTY interrupt and
 * 	RBIF interrupt is enabled.
 *
 * Precondition:    None.
 * Parameters:      None.
 * Return Values:   None.
 * Remarks:         None.
 * Example: CAN1RxMsgProcess();
  ***************************************************************************/
void CAN1RxMsgProcess(void);

/****************************************************************************
 * Function:            void CAN2RxMsgProcess(void);
 * Description:
 *  This function will check if a CAN message is available in CAN1 channel 1.
 *  If so , the message is read. Byte 0 of the received message will indicate
 *  if LEDC and LED3 should be switched ON or OFF. *
 * 
 * Precondition:    None.
 * Parameters:      None.
 * Return Values:   None.
 * Remarks:         None.
 * Example:     CAN2RxMsgProcess();
  ***************************************************************************/
void CAN2RxMsgProcess(void);

/****************************************************************************
 * Function:    void CAN1TxSendLEDMsg(void);
 * Description:
 *    This function will check if CAN 2 received a message from CAN1.
 *    If so it will then read CAN2 Channel 1. Byte 0 of the received message
 *    will indicate if the LED4 and LEDD should be switched ON or OFF.
 *
 * Precondition:    None.
 * Parameters:      None.
 * Return Values:   None.
 * Remarks:         None.
 * Example:   CAN1TxSendLEDMsg();
  ***************************************************************************/
void CAN1TxSendLEDMsg(void);

/****************************************************************************
 * Function:    void CAN2TxSendLEDMsg(void);
 * Description:
 *    This function will send a CAN message with EID 0x8004001. In the payload,
 *    it sends one byte which is a toggle state for LED6. FIFO0 is used for
 *    sending the message.
 * Precondition:    None.
 * Parameters:      None.
 * Return Values:   None.
 * Remarks:         None.
 * Example:   CAN2TxSendLEDMsg();
  ***************************************************************************/
void CAN2TxSendLEDMsg(void);

/* End of CANFunctions.h */
