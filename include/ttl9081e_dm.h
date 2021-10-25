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
#ifndef __TLL9081E_DM_H__
#define __TLL9081E_DM_H__


void ttl9081e_init_dm_priv(IN PADAPTER Adapter);
void ttl9081e_deinit_dm_priv(IN PADAPTER Adapter);
void ttl9081e_InitHalDm(IN PADAPTER Adapter);
void ttl9081e_HalDmWatchDog(IN PADAPTER Adapter);

//VOID ttl9081c_dm_CheckTXPowerTracking(IN PADAPTER Adapter);

//void ttl9081c_dm_RF_Saving(IN PADAPTER pAdapter, IN u8 bForceInNormal);

#ifdef CONFIG_ANTENNA_DIVERSITY
void	AntDivCompare9081e(PADAPTER Adapter, WLAN_BSSID_EX *dst, WLAN_BSSID_EX *src);
u8 AntDivBeforeLink9081e(PADAPTER Adapter );
#endif
#endif

