/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __TLL9081E_CMD_H__
#define __TLL9081E_CMD_H__

typedef enum _TLL9081E_H2C_CMD 
{
	H2C_9081E_RSVDPAGE	= 0x00,
	H2C_9081E_MSRRPT	= 0x01,
	H2C_9081E_SCAN		= 0x02,
	H2C_9081E_KEEP_ALIVE_CTRL = 0x03,
	H2C_9081E_DISCONNECT_DECISION = 0x04,
	H2C_9081E_INIT_OFFLOAD = 0x06,
	H2C_9081E_AP_OFFLOAD = 0x08,
	H2C_9081E_BCN_RSVDPAGE = 0x09,
	H2C_9081E_PROBERSP_RSVDPAGE = 0x0a,

	H2C_9081E_AP_WOW_GPIO_CTRL = 0x13,
	
	H2C_9081E_SETPWRMODE = 0x20,		
	H2C_9081E_PS_TUNING_PARA = 0x21,
	H2C_9081E_PS_TUNING_PARA2 = 0x22,
	H2C_9081E_PS_LPS_PARA = 0x23,
	H2C_9081E_P2P_PS_OFFLOAD = 0x24,
	H2C_9081E_SAP_PS = 0x26,
	H2C_9081E_RA_MASK = 0x40,
	H2C_9081E_RSSI_REPORT = 0x42,
	H2C_9081E_RA_PARA_ADJUST = 0x46,

	H2C_9081E_WO_WLAN = 0x80,
	H2C_9081E_REMOTE_WAKE_CTRL = 0x81,
	H2C_9081E_AOAC_GLOBAL_INFO = 0x82,
	H2C_9081E_AOAC_RSVDPAGE = 0x83,

	//Not defined in new 88E H2C CMD Format
	H2C_9081E_SELECTIVE_SUSPEND_ROF_CMD,
	H2C_9081E_P2P_PS_MODE,
	H2C_9081E_PSD_RESULT,
	MAX_9081E_H2CCMD
}TLL9081E_H2C_CMD;

typedef enum _TLL9081E_C2H_EVT
{
	C2H_9081E_DBG = 0,
	C2H_9081E_LB = 1,
	C2H_9081E_TXBF = 2,
	C2H_9081E_TX_REPORT = 3,
	C2H_9081E_BT_INFO = 9,
	C2H_9081E_FW_SWCHNL = 0x10,
	C2H_9081E_BT_MP = 11,
	C2H_9081E_RA_RPT = 12,
	C2H_9081E_RA_PARA_RPT = 14,
	C2H_9081E_EXTEND = 0xff,
	MAX_9081E_C2HEVENT	
}TLL9081E_C2H_EVT;

typedef enum _TLL9081E_EXTEND_C2H_EVT {
	EXTEND_C2H_9081E_DBG_PRINT = 0

} TLL9081E_EXTEND_C2H_EVT;

struct cmd_msg_parm {
	u8 eid; //element id
	u8 sz; // sz
	u8 buf[6];
};

enum{
	PWRS
};

typedef struct _SETPWRMODE_PARM {
	u8 Mode;//0:Active,1:LPS,2:WMMPS
	//u8 RLBM:4;//0:Min,1:Max,2: User define
	u8 SmartPS_RLBM;//LPS=0:PS_Poll,1:PS_Poll,2:NullData,WMM=0:PS_Poll,1:NullData
	u8 AwakeInterval;	// unit: beacon interval
	u8 bAllQueueUAPSD;
	u8 PwrState;//AllON(0x0c),RFON(0x04),RFOFF(0x00)
} SETPWRMODE_PARM, *PSETPWRMODE_PARM;

struct H2C_SS_RFOFF_PARAM{
	u8 ROFOn; // 1: on, 0:off
	u16 gpio_period; // unit: 1024 us
}__attribute__ ((packed));


typedef struct JOINBSSRPT_PARM_92E{
	u8 OpMode;	// RT_MEDIA_STATUS
#ifdef CONFIG_WOWLAN
	u8 MacID;       // MACID
#endif //CONFIG_WOWLAN
}JOINBSSRPT_PARM_92E, *PJOINBSSRPT_PARM_92E;

/* move to hal_com_h2c.h
typedef struct _RSVDPAGE_LOC_92E {
	u8 LocProbeRsp;
	u8 LocPsPoll;
	u8 LocNullData;
	u8 LocQosNull;
	u8 LocBTQosNull;
} RSVDPAGE_LOC_92E, *PRSVDPAGE_LOC_92E;
*/


//_SETPWRMODE_PARM
#define SET_9081E_H2CCMD_PWRMODE_PARM_MODE(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE_8BIT(__pH2CCmd, 0, 8, __Value)
#define SET_9081E_H2CCMD_PWRMODE_PARM_RLBM(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 0, 4, __Value)
#define SET_9081E_H2CCMD_PWRMODE_PARM_SMART_PS(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE((__pH2CCmd)+1, 4, 4, __Value)
#define SET_9081E_H2CCMD_PWRMODE_PARM_BCN_PASS_TIME(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE_8BIT((__pH2CCmd)+2, 0, 8, __Value)
#define SET_9081E_H2CCMD_PWRMODE_PARM_ALL_QUEUE_UAPSD(__pH2CCmd, __Value)	SET_BITS_TO_LE_1BYTE_8BIT((__pH2CCmd)+3, 0, 8, __Value)
#define SET_9081E_H2CCMD_PWRMODE_PARM_PWR_STATE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE_8BIT((__pH2CCmd)+4, 0, 8, __Value)
#define SET_9081E_H2CCMD_PWRMODE_PARM_BYTE5(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE_8BIT((__pH2CCmd)+5, 0, 8, __Value)
#define GET_9081E_H2CCMD_PWRMODE_PARM_MODE(__pH2CCmd)						LE_BITS_TO_1BYTE(__pH2CCmd, 0, 8)

//_P2P_PS_OFFLOAD
#define SET_9081E_H2CCMD_P2P_PS_OFFLOAD_ENABLE(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 0, 1, __Value)
#define SET_9081E_H2CCMD_P2P_PS_OFFLOAD_ROLE(__pH2CCmd, __Value)				SET_BITS_TO_LE_1BYTE(__pH2CCmd, 1, 1, __Value)
#define SET_9081E_H2CCMD_P2P_PS_OFFLOAD_CTWINDOW_EN(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 2, 1, __Value)
#define SET_9081E_H2CCMD_P2P_PS_OFFLOAD_NOA0_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 3, 1, __Value)
#define SET_9081E_H2CCMD_P2P_PS_OFFLOAD_NOA1_EN(__pH2CCmd, __Value)			SET_BITS_TO_LE_1BYTE(__pH2CCmd, 4, 1, __Value)
#define SET_9081E_H2CCMD_P2P_PS_OFFLOAD_ALLSTASLEEP(__pH2CCmd, __Value)		SET_BITS_TO_LE_1BYTE(__pH2CCmd, 5, 1, __Value)


// host message to firmware cmd
void ttl9081e_set_FwPwrMode_cmd(PADAPTER padapter, u8 Mode);
void ttl9081e_set_FwJoinBssReport_cmd(PADAPTER padapter, u8 mstatus);
u8 ttl9081e_set_rssi_cmd(PADAPTER padapter, u8 *param);
void ttl9081e_set_raid_cmd(PADAPTER padapter, u32 bitmap, u8* arg);
void ttl9081e_Add_RateATid(PADAPTER padapter, u64 rate_bitmap, u8 *arg, u8 rssi_level);
s32 FillH2CCmd_9081E(PADAPTER padapter, u8 ElementID, u32 CmdLen, u8 *pCmdBuffer);
u8 GetTxBufferRsvdPageNum9081E(_adapter *padapter, bool wowlan);
//u8 ttl9081c_set_FwSelectSuspend_cmd(PADAPTER padapter, u8 bfwpoll, u16 period);
s32 c2h_handler_9081e(PADAPTER padapter, u8 *buf);
#ifdef CONFIG_BT_COEXIST
void ttl9081e_download_BTCoex_AP_mode_rsvd_page(PADAPTER padapter);
#endif // CONFIG_BT_COEXIST
#ifdef CONFIG_P2P_PS
void ttl9081e_set_p2p_ps_offload_cmd(PADAPTER padapter, u8 p2p_ps_state);
#endif //CONFIG_P2P

void CheckFwRsvdPageContent(PADAPTER padapter);
void ttl9081e_set_FwMediaStatus_cmd(PADAPTER padapter, u16 mstatus_rpt );

#ifdef CONFIG_TSF_RESET_OFFLOAD
int reset_tsf(PADAPTER Adapter, u8 reset_port );
#endif	// CONFIG_TSF_RESET_OFFLOAD


#if defined(CONFIG_WOWLAN) || defined(CONFIG_AP_WOWLAN)
void SetFwRelatedForWoWLAN9081E(_adapter* padapter, u8 bHostIsGoingtoSleep);
#endif
/// TX Feedback Content
#define 	USEC_UNIT_FOR_9081E_C2H_TX_RPT_QUEUE_TIME			256

#define	GET_9081E_C2H_TX_RPT_QUEUE_SELECT(_Header)			LE_BITS_TO_1BYTE((_Header + 0), 0, 5)
#define	GET_9081E_C2H_TX_RPT_PKT_BROCAST(_Header)			LE_BITS_TO_1BYTE((_Header + 0), 5, 1)
#define	GET_9081E_C2H_TX_RPT_LIFE_TIME_OVER(_Header)			LE_BITS_TO_1BYTE((_Header + 0), 6, 1)
#define	GET_9081E_C2H_TX_RPT_RETRY_OVER(_Header)				LE_BITS_TO_1BYTE((_Header + 0), 7, 1)
#define	GET_9081E_C2H_TX_RPT_MAC_ID(_Header)					LE_BITS_TO_1BYTE((_Header + 1), 0, 8)
#define	GET_9081E_C2H_TX_RPT_DATA_RETRY_CNT(_Header)		LE_BITS_TO_1BYTE((_Header + 2), 0, 6)
#define	GET_9081E_C2H_TX_RPT_QUEUE_TIME(_Header)				LE_BITS_TO_2BYTE((_Header + 3), 0, 16)	// In unit of 256 microseconds.
#define	GET_9081E_C2H_TX_RPT_FINAL_DATA_RATE(_Header)		LE_BITS_TO_1BYTE((_Header + 5), 0, 8)



void C2HContentParsing9081E(
	IN	PADAPTER		Adapter,
	IN	u1Byte			c2hCmdId, 
	IN	u1Byte			c2hCmdLen,
	IN	pu1Byte 			tmpBuf
);
VOID
C2HPacketHandler_9081E(
	IN	PADAPTER		Adapter,
	IN	pu1Byte			Buffer,
	IN	u1Byte			Length
);

#endif//__TLL9081E_CMD_H__