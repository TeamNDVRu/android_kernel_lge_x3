/*
 * tegra20_spdif.h - Definitions for Tegra20 SPDIF driver
 *
 * Author: Stephen Warren <swarren@nvidia.com>
 * Copyright (C) 2011 - NVIDIA, Inc.
 *
 * Based on code copyright/by:
 * Copyright (c) 2008-2009, NVIDIA Corporation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef __TEGRA20_SPDIF_H__
#define __TEGRA20_SPDIF_H__

#include "tegra_pcm.h"


#define TEGRA20_SPDIF_CTRL				0x0
#define TEGRA20_SPDIF_STATUS				0x4
#define TEGRA20_SPDIF_STROBE_CTRL			0x8
#define TEGRA20_SPDIF_DATA_FIFO_CSR			0x0C
#define TEGRA20_SPDIF_DATA_OUT				0x40
#define TEGRA20_SPDIF_DATA_IN				0x80
#define TEGRA20_SPDIF_CH_STA_RX_A			0x100
#define TEGRA20_SPDIF_CH_STA_RX_B			0x104
#define TEGRA20_SPDIF_CH_STA_RX_C			0x108
#define TEGRA20_SPDIF_CH_STA_RX_D			0x10C
#define TEGRA20_SPDIF_CH_STA_RX_E			0x110
#define TEGRA20_SPDIF_CH_STA_RX_F			0x114
#define TEGRA20_SPDIF_CH_STA_TX_A			0x140
#define TEGRA20_SPDIF_CH_STA_TX_B			0x144
#define TEGRA20_SPDIF_CH_STA_TX_C			0x148
#define TEGRA20_SPDIF_CH_STA_TX_D			0x14C
#define TEGRA20_SPDIF_CH_STA_TX_E			0x150
#define TEGRA20_SPDIF_CH_STA_TX_F			0x154
#define TEGRA20_SPDIF_USR_STA_RX_A			0x180
#define TEGRA20_SPDIF_USR_DAT_TX_A			0x1C0


#define TEGRA20_SPDIF_CTRL_CAP_LC			(1 << 30)

#define TEGRA20_SPDIF_CTRL_RX_EN			(1 << 29)

#define TEGRA20_SPDIF_CTRL_TX_EN			(1 << 28)

#define TEGRA20_SPDIF_CTRL_TC_EN			(1 << 27)

#define TEGRA20_SPDIF_CTRL_TU_EN			(1 << 26)

#define TEGRA20_SPDIF_CTRL_IE_TXE			(1 << 25)

#define TEGRA20_SPDIF_CTRL_IE_RXE			(1 << 24)

#define TEGRA20_SPDIF_CTRL_IE_P				(1 << 23)

#define TEGRA20_SPDIF_CTRL_IE_B				(1 << 22)

#define TEGRA20_SPDIF_CTRL_IE_C				(1 << 21)

#define TEGRA20_SPDIF_CTRL_IE_U				(1 << 20)

#define TEGRA20_SPDIF_CTRL_QE_RU			(1 << 19)

#define TEGRA20_SPDIF_CTRL_QE_TU			(1 << 18)

#define TEGRA20_SPDIF_CTRL_QE_RX			(1 << 17)

#define TEGRA20_SPDIF_CTRL_QE_TX			(1 << 16)

#define TEGRA20_SPDIF_CTRL_LBK_EN			(1 << 15)

#define TEGRA20_SPDIF_CTRL_PACK				(1 << 14)


#define TEGRA20_SPDIF_BIT_MODE_16BIT			0
#define TEGRA20_SPDIF_BIT_MODE_20BIT			1
#define TEGRA20_SPDIF_BIT_MODE_24BIT			2
#define TEGRA20_SPDIF_BIT_MODE_RAW			3

#define TEGRA20_SPDIF_CTRL_BIT_MODE_SHIFT		12
#define TEGRA20_SPDIF_CTRL_BIT_MODE_MASK		(3                          << TEGRA20_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA20_SPDIF_CTRL_BIT_MODE_16BIT		(TEGRA20_SPDIF_BIT_MODE_16BIT << TEGRA20_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA20_SPDIF_CTRL_BIT_MODE_20BIT		(TEGRA20_SPDIF_BIT_MODE_20BIT << TEGRA20_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA20_SPDIF_CTRL_BIT_MODE_24BIT		(TEGRA20_SPDIF_BIT_MODE_24BIT << TEGRA20_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA20_SPDIF_CTRL_BIT_MODE_RAW			(TEGRA20_SPDIF_BIT_MODE_RAW   << TEGRA20_SPDIF_CTRL_BIT_MODE_SHIFT)


#define TEGRA20_SPDIF_STATUS_TX_BSY			(1 << 28)

#define TEGRA20_SPDIF_STATUS_TC_BSY			(1 << 27)


#define TEGRA20_SPDIF_STATUS_TU_BSY			(1 << 26)

#define TEGRA20_SPDIF_STATUS_TX_ERR			(1 << 25)

#define TEGRA20_SPDIF_STATUS_RX_ERR			(1 << 24)

#define TEGRA20_SPDIF_STATUS_IS_P			(1 << 23)

#define TEGRA20_SPDIF_STATUS_IS_B			(1 << 22)


#define TEGRA20_SPDIF_STATUS_IS_C			(1 << 21)

#define TEGRA20_SPDIF_STATUS_IS_U			(1 << 20)


#define TEGRA20_SPDIF_STATUS_QS_RU			(1 << 19)


#define TEGRA20_SPDIF_STATUS_QS_TU			(1 << 18)


#define TEGRA20_SPDIF_STATUS_QS_RX			(1 << 17)

#define TEGRA20_SPDIF_STATUS_QS_TX			(1 << 16)


#define TEGRA20_SPDIF_STROBE_CTRL_PERIOD_SHIFT		16
#define TEGRA20_SPDIF_STROBE_CTRL_PERIOD_MASK		(0xff << TEGRA20_SPDIF_STROBE_CTRL_PERIOD_SHIFT)

#define TEGRA20_SPDIF_STROBE_CTRL_STROBE		(1 << 15)


#define TEGRA20_SPDIF_STROBE_CTRL_DATA_STROBES_SHIFT	8
#define TEGRA20_SPDIF_STROBE_CTRL_DATA_STROBES_MASK	(0x1f << TEGRA20_SPDIF_STROBE_CTRL_DATA_STROBES_SHIFT)


#define TEGRA20_SPDIF_STROBE_CTRL_CLOCK_PERIOD_SHIFT	0
#define TEGRA20_SPDIF_STROBE_CTRL_CLOCK_PERIOD_MASK	(0x3f << TEGRA20_SPDIF_STROBE_CTRL_CLOCK_PERIOD_SHIFT)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_CLR		(1 << 31)

#define TEGRA20_SPDIF_FIFO_ATN_LVL_U_ONE_SLOT		0
#define TEGRA20_SPDIF_FIFO_ATN_LVL_U_TWO_SLOTS		1
#define TEGRA20_SPDIF_FIFO_ATN_LVL_U_THREE_SLOTS	2
#define TEGRA20_SPDIF_FIFO_ATN_LVL_U_FOUR_SLOTS		3

#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_SHIFT		29
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_MASK		\
		(0x3                                    << TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_RU1_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_ONE_SLOT    << TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_RU2_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_TWO_SLOTS   << TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_RU3_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_THREE_SLOTS << TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_RU4_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_FOUR_SLOTS  << TEGRA20_SPDIF_DATA_FIFO_CSR_RU_ATN_LVL_SHIFT)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_FULL_COUNT_SHIFT		24
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RU_FULL_COUNT_MASK		(0x1f << TEGRA20_SPDIF_DATA_FIFO_CSR_RU_FULL_COUNT_SHIFT)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_CLR			(1 << 23)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_SHIFT		21
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_MASK		\
		(0x3                                   << TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_TU1_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_ONE_SLOT    << TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_TU2_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_TWO_SLOTS   << TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_TU3_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_THREE_SLOTS << TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_TU4_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_U_FOUR_SLOTS  << TEGRA20_SPDIF_DATA_FIFO_CSR_TU_ATN_LVL_SHIFT)

#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_EMPTY_COUNT_SHIFT	16
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TU_EMPTY_COUNT_MASK		(0x1f << SPDIF_DATA_FIFO_CSR_TU_EMPTY_COUNT_SHIFT)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_CLR			(1 << 15)

#define TEGRA20_SPDIF_FIFO_ATN_LVL_D_ONE_SLOT			0
#define TEGRA20_SPDIF_FIFO_ATN_LVL_D_FOUR_SLOTS			1
#define TEGRA20_SPDIF_FIFO_ATN_LVL_D_EIGHT_SLOTS		2
#define TEGRA20_SPDIF_FIFO_ATN_LVL_D_TWELVE_SLOT		3

#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_SHIFT		13
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_MASK		\
		(0x3                                     << TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_RU1_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_ONE_SLOT     << TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_RU4_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_FOUR_SLOTS   << TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_RU8_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_EIGHT_SLOTS  << TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_RU12_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_TWELVE_SLOTS << TEGRA20_SPDIF_DATA_FIFO_CSR_RX_ATN_LVL_SHIFT)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_FULL_COUNT_SHIFT		8
#define TEGRA20_SPDIF_DATA_FIFO_CSR_RX_FULL_COUNT_MASK		(0x1f << TEGRA20_SPDIF_DATA_FIFO_CSR_RX_FULL_COUNT_SHIFT)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_CLR			(1 << 7)


#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_SHIFT		5
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_MASK		\
		(0x3                                     << TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_TU1_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_ONE_SLOT     << TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_TU4_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_FOUR_SLOTS   << TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_TU8_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_EIGHT_SLOTS  << TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_SHIFT)
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_TU12_WORD_FULL	\
		(TEGRA20_SPDIF_FIFO_ATN_LVL_D_TWELVE_SLOTS << TEGRA20_SPDIF_DATA_FIFO_CSR_TX_ATN_LVL_SHIFT)

 
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_EMPTY_COUNT_SHIFT	0
#define TEGRA20_SPDIF_DATA_FIFO_CSR_TX_EMPTY_COUNT_MASK		(0x1f << SPDIF_DATA_FIFO_CSR_TX_EMPTY_COUNT_SHIFT)

 
#define TEGRA20_SPDIF_DATA_OUT_DATA_16_SHIFT			0
#define TEGRA20_SPDIF_DATA_OUT_DATA_16_MASK			(0xffff << TEGRA20_SPDIF_DATA_OUT_DATA_16_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_20_SHIFT			0
#define TEGRA20_SPDIF_DATA_OUT_DATA_20_MASK			(0xfffff << TEGRA20_SPDIF_DATA_OUT_DATA_20_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_24_SHIFT			0
#define TEGRA20_SPDIF_DATA_OUT_DATA_24_MASK			(0xffffff << TEGRA20_SPDIF_DATA_OUT_DATA_24_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_P			(1 << 31)
#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_C			(1 << 30)
#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_U			(1 << 29)
#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_V			(1 << 28)

#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_DATA_SHIFT		8
#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_DATA_MASK		(0xfffff << TEGRA20_SPDIF_DATA_OUT_DATA_RAW_DATA_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_AUX_SHIFT		4
#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_AUX_MASK		(0xf << TEGRA20_SPDIF_DATA_OUT_DATA_RAW_AUX_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_PREAMBLE_SHIFT		0
#define TEGRA20_SPDIF_DATA_OUT_DATA_RAW_PREAMBLE_MASK		(0xf << TEGRA20_SPDIF_DATA_OUT_DATA_RAW_PREAMBLE_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_16_PACKED_RIGHT_SHIFT	16
#define TEGRA20_SPDIF_DATA_OUT_DATA_16_PACKED_RIGHT_MASK	(0xffff << TEGRA20_SPDIF_DATA_OUT_DATA_16_PACKED_RIGHT_SHIFT)

#define TEGRA20_SPDIF_DATA_OUT_DATA_16_PACKED_LEFT_SHIFT	0
#define TEGRA20_SPDIF_DATA_OUT_DATA_16_PACKED_LEFT_MASK		(0xffff << TEGRA20_SPDIF_DATA_OUT_DATA_16_PACKED_LEFT_SHIFT)

 

#define TEGRA20_SPDIF_DATA_IN_DATA_P				(1 << 31)
#define TEGRA20_SPDIF_DATA_IN_DATA_C				(1 << 30)
#define TEGRA20_SPDIF_DATA_IN_DATA_U				(1 << 29)
#define TEGRA20_SPDIF_DATA_IN_DATA_V				(1 << 28)

#define TEGRA20_SPDIF_DATA_IN_DATA_PREAMBLE_SHIFT		24
#define TEGRA20_SPDIF_DATA_IN_DATA_PREAMBLE_MASK		(0xf << TEGRA20_SPDIF_DATA_IN_DATA_PREAMBLE_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_16_SHIFT			0
#define TEGRA20_SPDIF_DATA_IN_DATA_16_MASK			(0xffff << TEGRA20_SPDIF_DATA_IN_DATA_16_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_20_SHIFT			0
#define TEGRA20_SPDIF_DATA_IN_DATA_20_MASK			(0xfffff << TEGRA20_SPDIF_DATA_IN_DATA_20_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_24_SHIFT			0
#define TEGRA20_SPDIF_DATA_IN_DATA_24_MASK			(0xffffff << TEGRA20_SPDIF_DATA_IN_DATA_24_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_RAW_DATA_SHIFT		8
#define TEGRA20_SPDIF_DATA_IN_DATA_RAW_DATA_MASK		(0xfffff << TEGRA20_SPDIF_DATA_IN_DATA_RAW_DATA_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_RAW_AUX_SHIFT		4
#define TEGRA20_SPDIF_DATA_IN_DATA_RAW_AUX_MASK			(0xf << TEGRA20_SPDIF_DATA_IN_DATA_RAW_AUX_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_RAW_PREAMBLE_SHIFT		0
#define TEGRA20_SPDIF_DATA_IN_DATA_RAW_PREAMBLE_MASK		(0xf << TEGRA20_SPDIF_DATA_IN_DATA_RAW_PREAMBLE_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_16_PACKED_RIGHT_SHIFT	16
#define TEGRA20_SPDIF_DATA_IN_DATA_16_PACKED_RIGHT_MASK		(0xffff << TEGRA20_SPDIF_DATA_IN_DATA_16_PACKED_RIGHT_SHIFT)

#define TEGRA20_SPDIF_DATA_IN_DATA_16_PACKED_LEFT_SHIFT		0
#define TEGRA20_SPDIF_DATA_IN_DATA_16_PACKED_LEFT_MASK		(0xffff << TEGRA20_SPDIF_DATA_IN_DATA_16_PACKED_LEFT_SHIFT)

 
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_22050			0x4
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_24000			0x6
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_32000			0x3
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_44100			0x0
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_48000			0x2
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_88200			0x8
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_96000			0xA
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_176400			0xC
#define TEGRA20_SPDIF_CH_STA_TX_A_SF_192000			0xE

#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT		24
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_MASK		\
		(0xF                                 << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_22050	\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_22050  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_24000		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_24000  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_32000		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_32000  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_44100		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_44100  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_48000		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_48000  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_88200		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_88200  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_96000		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_96000  << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_176400		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_176400 << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_192000		\
		(TEGRA20_SPDIF_CH_STA_TX_A_SF_192000 << TEGRA20_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)

 #define TEGRA20_SPDIF_CH_STA_TX_B_SF_8000			0x6
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_11025			0xA
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_12000			0x2
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_16000			0x8
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_22050			0xB
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_24000			0x9
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_32000			0xC
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_44100			0xF
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_48000			0xD
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_88200			0x7
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_96000			0x5
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_176400			0x3
#define TEGRA20_SPDIF_CH_STA_TX_B_SF_192000			0x1

#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT		4
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_MASK		\
		(0xF                                 << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_8000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_8000   << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_11025		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_11025  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_12000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_12000  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_16000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_16000  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_22050		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_22025  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_24000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_24000  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_32000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_32000  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_44100		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_44100  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_48000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_48000  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_88200		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_88200  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_96000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_96000  << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_176400		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_176400 << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_192000		\
		(TEGRA20_SPDIF_CH_STA_TX_B_SF_192000 << TEGRA20_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)

 
#ifdef CONFIG_PM
#define TEGRA20_SPDIF_CTRL_CACHE_SIZE		((TEGRA20_SPDIF_DATA_FIFO_CSR >> 2) + 1)
#define TEGRA20_SPDIF_TX_CACHE_SIZE		(((TEGRA20_SPDIF_CH_STA_TX_F - TEGRA20_SPDIF_CH_STA_TX_A) >> 2) + 1)
#endif

struct tegra20_spdif {
	struct clk *clk_spdif_out;
	struct tegra_pcm_dma_params capture_dma_data;
	struct tegra_pcm_dma_params playback_dma_data;
	void __iomem *regs;
	struct dentry *debug;
	u32 reg_ctrl;
#ifdef CONFIG_PM
	u32  reg_ctrl_cache[TEGRA20_SPDIF_CTRL_CACHE_SIZE];
	u32  reg_tx_cache[TEGRA20_SPDIF_TX_CACHE_SIZE];
#endif
};

#endif