/*
 * tegra20_das.h - Definitions for Tegra20 DAS driver
 *
 * Author: Stephen Warren <swarren@nvidia.com>
 * Copyright (C) 2010 - NVIDIA, Inc.
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

#ifndef __TEGRA20_DAS_H__
#define __TEGRA20_DAS_H__

 #define TEGRA20_DAS_DAP_CTRL_SEL			0x00
#define TEGRA20_DAS_DAP_CTRL_SEL_COUNT			5
#define TEGRA20_DAS_DAP_CTRL_SEL_STRIDE			4
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_MS_SEL_P		31
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_MS_SEL_S		1
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA1_TX_RX_P	30
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA1_TX_RX_S	1
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA2_TX_RX_P	29
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_SDATA2_TX_RX_S	1
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_CTRL_SEL_P		0
#define TEGRA20_DAS_DAP_CTRL_SEL_DAP_CTRL_SEL_S		5

 #define TEGRA20_DAS_DAP_SEL_DAC1	0
#define TEGRA20_DAS_DAP_SEL_DAC2	1
#define TEGRA20_DAS_DAP_SEL_DAC3	2
#define TEGRA20_DAS_DAP_SEL_DAP1	16
#define TEGRA20_DAS_DAP_SEL_DAP2	17
#define TEGRA20_DAS_DAP_SEL_DAP3	18
#define TEGRA20_DAS_DAP_SEL_DAP4	19
#define TEGRA20_DAS_DAP_SEL_DAP5	20

 #define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL			0x40
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_COUNT		3
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_STRIDE		4
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_SDATA2_SEL_P	28
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_SDATA2_SEL_S	4
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_SDATA1_SEL_P	24
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_SDATA1_SEL_S	4
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_CLK_SEL_P	0
#define TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_DAC_CLK_SEL_S	4
 
#define TEGRA20_DAS_DAC_SEL_DAP1	0
#define TEGRA20_DAS_DAC_SEL_DAP2	1
#define TEGRA20_DAS_DAC_SEL_DAP3	2
#define TEGRA20_DAS_DAC_SEL_DAP4	3
#define TEGRA20_DAS_DAC_SEL_DAP5	4
 
#define TEGRA20_DAS_DAP_ID_1 0
#define TEGRA20_DAS_DAP_ID_2 1
#define TEGRA20_DAS_DAP_ID_3 2
#define TEGRA20_DAS_DAP_ID_4 3
#define TEGRA20_DAS_DAP_ID_5 4

#define TEGRA20_DAS_DAC_ID_1 0
#define TEGRA20_DAS_DAC_ID_2 1
#define TEGRA20_DAS_DAC_ID_3 2

#ifdef CONFIG_PM
#define TEGRA20_DAS_CACHE_SIZE	((((TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL) + (TEGRA20_DAS_DAC_INPUT_DATA_CLK_SEL_STRIDE*TEGRA20_DAS_DAC_ID_3))>>2) + 1)
#endif

struct tegra20_das {
	struct device *dev;
	void __iomem *regs;
	struct dentry *debug;
#ifdef CONFIG_PM
	u32  reg_cache[TEGRA20_DAS_CACHE_SIZE];
#endif
};

#ifdef CONFIG_PM
 extern int tegra20_das_resume();
#endif
 
extern int tegra20_das_connect_dap_to_dac(int dap_id, int dac_sel);
 
extern int tegra20_das_connect_dap_to_dap(int dap_id, int other_dap_sel,
					int master, int sdata1rx,
					int sdata2rx);
 
extern int tegra20_das_connect_dac_to_dap(int dac_id, int dap_sel);

extern int tegra20_das_set_tristate(int dap_id, int is_tristate);

#endif
