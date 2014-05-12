/*****************************************************************************
 * Copyright (c) 2014 Ted John, Kevin Burke, Matthias Lanzinger
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 * 
 * This file is part of OpenRCT2.
 * 
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef _ADDRESSES_H_
#define _ADDRESSES_H_

#pragma warning(disable : 4731)

#define RCT2_ADDRESS(address, type)				((type*)(address))
#define RCT2_GLOBAL(address, type)				(*((type*)(address)))
#define RCT2_CALLPROC(address)					(((void(*)())(address))())
#define RCT2_CALLFUNC(address, returnType)		(((returnType(*)())(address))())

#define RCT2_CALLFUNC_1(address, returnType, a1, v1)							(((returnType(*)(a1))(address))(v1))
#define RCT2_CALLFUNC_2(address, returnType, a1, a2, v1, v2)					(((returnType(*)(a1, a2))(address))(v1, v2))
#define RCT2_CALLFUNC_3(address, returnType, a1, a2, a3, v1, v2, v3)			(((returnType(*)(a1, a2, a3))(address))(v1, v2, v3))
#define RCT2_CALLFUNC_4(address, returnType, a1, a2, a3, a4, v1, v2, v3, v4)	(((returnType(*)(a1, a2, a3, a4))(address))(v1, v2, v3, v4))
#define RCT2_CALLFUNC_5(address, returnType, a1, a2, a3, a4, a5, v1, v2, v3, v4, v5)	(((returnType(*)(a1, a2, a3, a4, a5))(address))(v1, v2, v3, v4, v5))

#define RCT2_CALLPROC_1(address, a1, v1)									RCT2_CALLFUNC_1(address, void, a1, v1)
#define RCT2_CALLPROC_2(address, a1, a2, v1, v2)							RCT2_CALLFUNC_2(address, void, a1, a2, v1, v2)
#define RCT2_CALLPROC_3(address, a1, a2, a3, v1, v2, v3)					RCT2_CALLFUNC_3(address, void, a1, a2, a3, v1, v2, v3)
#define RCT2_CALLPROC_4(address, a1, a2, a3, a4, v1, v2, v3, v4)			RCT2_CALLFUNC_4(address, void, a1, a2, a3, a4, v1, v2, v3, v4)
#define RCT2_CALLPROC_5(address, a1, a2, a3, a4, a5, v1, v2, v3, v4, v5)	RCT2_CALLFUNC_5(address, void, a1, a2, a3, a4, a5, v1, v2, v3, v4, v5)

#define RCT2_ADDRESS_RIDE_PROPERTIES				0x00997C9D
#define RCT2_ADDRESS_LAND_TOOL_SIZE					0x009A9800

#define RCT2_ADDRESS_SCENARIO_LIST					0x009A9FF4
#define RCT2_ADDRESS_NUM_SCENARIOS					0x009AA008

#define RCT2_ADDRESS_APP_PATH						0x009AA214

#define RCT2_ADDRESS_CONFIG_MUSIC					0x009AAC72
#define RCT2_ADDRESS_CONFIG_FLAGS					0x009AAC74
#define RCT2_ADDRESS_CONFIG_SOUND_QUALITY			0x009AAC77
#define RCT2_ADDRESS_CONFIG_METRIC					0x009AAC78
#define RCT2_ADDRESS_CONFIG_FAHRENHEIT				0x009AAC79
#define RCT2_ADDRESS_CONFIG_KEYBOARD_SHORTCUTS		0x009AAC7A
#define RCT2_ADDRESS_CONFIG_EDGE_SCROLLING			0x009AACBA
#define RCT2_ADDRESS_CONFIG_CURRENCY				0x009AACBB
#define RCT2_ADDRESS_CONFIG_CONSTRUCTION_MARKER		0x009AACBF

#define RCT2_ADDRESS_EXPANSION_NAMES				0x009AACC0
#define RCT2_ADDRESS_EXPANSION_FLAGS				0x009AB4C0
#define RCT2_ADDRESS_CONFIG_RESOLUTION_WIDTH		0x009AB4C2
#define RCT2_ADDRESS_CONFIG_RESOLUTION_HEIGHT		0x009AB4C4

#define RCT2_ADDRESS_APP_PATH_SLASH					0x009AB4D9
#define RCT2_ADDRESS_SAVED_GAMES_PATH				0x009AB5DA
#define RCT2_ADDRESS_SCENARIOS_PATH					0x009AB6E9
#define RCT2_ADDRESS_LANDSCAPES_PATH				0x009AB7FB
#define RCT2_ADDRESS_OBJECT_DATA_PATH				0x009AB90E
#define RCT2_ADDRESS_TRACKS_PATH					0x009ABA1E
#define RCT2_ADDRESS_SAVED_GAMES_PATH_2				0x009ABB37

#define RCT2_ADDRESS_SCREEN_DPI						0x009ABDC8
#define RCT2_ADDRESS_SCREEN_WIDTH					0x009ABDD8
#define RCT2_ADDRESS_SCREEN_HEIGHT					0x009ABDDA

#define RCT2_ADDRESS_DIRTY_BLOCK_WIDTH				0x009ABDE4
#define RCT2_ADDRESS_DIRTY_BLOCK_HEIGHT				0x009ABDE6
#define RCT2_ADDRESS_DIRTY_BLOCK_COLUMNS			0x009ABDE8
#define RCT2_ADDRESS_DIRTY_BLOCK_ROWS				0x009ABDEC

#define RCT2_ADDRESS_RUN_INTRO_TICK_PART			0x009AC319

#define RCT2_ADDRESS_INPUT_STATE					0x009DE51D
#define RCT2_ADDRESS_CURSOR_DOWN_WINDOWCLASS		0x009DE51F
#define RCT2_ADDRESS_CURSOR_DOWN_WINDOWNUMBER		0x009DE520
#define RCT2_ADDRESS_CURSOR_DOWN_WIDGETINDEX		0x009DE524

#define RCT2_ADDRESS_CURSOR_DRAG_LAST_X				0x009DE52A
#define RCT2_ADDRESS_CURSOR_DRAG_LAST_Y				0x009DE52C
#define RCT2_ADDRESS_CURSOR_DRAG_WINDOWNUMBER		0x009DE52E
#define RCT2_ADDRESS_CURSOR_DRAG_WINDOWCLASS		0x009DE530

#define RCT2_ADDRESS_TOOLTIP_WINDOW_CLASS			0x009DE533
#define RCT2_ADDRESS_TOOLTIP_WINDOW_NUMBER			0x009DE534
#define RCT2_ADDRESS_TOOLTIP_WIDGET_INDEX			0x009DE536
#define RCT2_ADDRESS_TOOLTIP_CURSOR_X				0x009DE538
#define RCT2_ADDRESS_TOOLTIP_CURSOR_Y				0x009DE53A
#define RCT2_ADDRESS_TOOLTIP_TIMEOUT				0x009DE53C
#define RCT2_ADDRESS_TOOLTIP_NOT_SHOWN_TICKS		0x009DE53E

#define RCT2_ADDRESS_TOOL_WINDOWNUMBER				0x009DE542
#define RCT2_ADDRESS_TOOL_WINDOWCLASS				0x009DE544
#define RCT2_ADDRESS_CURRENT_TOOL					0x009DE545
#define RCT2_ADDRESS_TOOL_WIDGETINDEX				0x009DE546

#define RCT2_ADDRESS_CURSOR_OVER_WINDOWCLASS		0x009DE55C
#define RCT2_ADDRESS_CURSOR_OVER_WINDOWNUMBER		0x009DE55E
#define RCT2_ADDRESS_CURSOR_OVER_WIDGETINDEX		0x009DE560

#define RCT2_ADDRESS_MAP_SELECTION_FLAGS			0x009DE58A
#define RCT2_ADDRESS_MAP_SELECTION_A_X				0x009DE58C
#define RCT2_ADDRESS_MAP_SELECTION_B_X				0x009DE58E
#define RCT2_ADDRESS_MAP_SELECTION_A_Y				0x009DE590
#define RCT2_ADDRESS_MAP_SELECTION_B_Y				0x009DE592
#define RCT2_ADDRESS_MAP_SELECTION_TYPE				0x009DE594

#define RCT2_ADDRESS_SCREEN_FLAGS					0x009DEA68
#define RCT2_ADDRESS_SCREENSHOT_COUNTDOWN			0x009DEA6D
#define RCT2_ADDRESS_PLACE_OBJECT_MODIFIER			0x009DEA70
#define RCT2_ADDRESS_ON_TUTORIAL					0x009DEA71

#define RCT2_ADDRESS_WINDOW_DPI						0x009DEA74

#define RCT2_ADDRESS_NUM_DSOUND_DEVICES				0x009E2B88
#define RCT2_ADDRESS_DSOUND_DEVICES					0x009E2B8C

#define RCT2_ADDRESS_CMDLINE						0x009E2D98

#define RCT2_ADDRESS_LAND_RAISE_COST				0x009E2E1C
#define RCT2_ADDRESS_LAND_LOWER_COST				0x009E2E20
#define RCT2_ADDRESS_SELECTED_TERRAIN_EDGE			0x009E2E24
#define RCT2_ADDRESS_SELECTED_TERRAIN_SURFACE		0x009E2E25

#define RCT2_ADDRESS_G1_ELEMENTS					0x009EBD28

#define RCT2_ADDRESS_CURRENT_MONTH_YEAR				0x00F663A8
#define RCT2_ADDRESS_CURRENT_MONTH_TICKS			0x00F663AA

#define RCT2_ADDRESS_MAP_ELEMENTS					0x00F663B8

#define RCT2_ADDRESS_SPRITE_LIST					0x010E63BC
#define RCT2_ADDRESS_SPRITES_NEXT_INDEX				0x013573BC
#define RCT2_ADDRESS_SPRITES_START_VEHICLE			0x013573BE
#define RCT2_ADDRESS_SPRITES_START_PEEP				0x013573C0
#define RCT2_ADDRESS_SPRITES_START_TEXTFX			0x013573C2
#define RCT2_ADDRESS_SPRITES_START_LITTER			0x013573C4

#define RCT2_ADDRESS_CURRENT_LOAN					0x013573E0
#define RCT2_ADDRESS_MAXIMUM_LOAN					0x013580F0
#define RCT2_ADDRESS_PARK_FLAGS						0x013573E4
#define RCT2_ADDRESS_PARK_ENTRANCE_FEE				0x013573E8
#define RCT2_ADDRESS_GUESTS_IN_PARK					0x01357844
#define RCT2_ADDRESS_MONTHLY_RIDE_INCOME			0x01357894
#define RCT2_ADDRESS_CURRENT_PARK_RATING			0x01357CB0
#define RCT2_ADDRESS_PARK_RATING_HISTORY			0x01357CB2
#define RCT2_ADDRESS_GUESTS_IN_PARK_HISTORY			0x01357CD2
#define RCT2_ADDRESS_OBJECTIVE_TYPE					0x013580F8
#define RCT2_ADDRESS_OBJECTIVE_YEAR					0x013580F9
#define RCT2_ADDRESS_OBJECTIVE_CURRENCY				0x013580FC
#define RCT2_ADDRESS_OBJECTIVE_NUM_GUESTS			0x01358100
#define RCT2_ADDRESS_BALANCE_HISTORY				0x0135812C
#define RCT2_ADDRESS_CURRENT_PROFIT					0x01358330
#define RCT2_ADDRESS_WEEKLY_PROFIT_HISTORY			0x0135833C
#define RCT2_ADDRESS_CURRENT_PARK_VALUE				0x0135853C
#define RCT2_ADDRESS_PARK_VALUE_HISTORY				0x01358540
#define RCT2_ADDRESS_COMPLETED_COMPANY_VALUE		0x01358740
#define RCT2_ADDRESS_TOTAL_ADMISSIONS				0x01358744
#define RCT2_ADDRESS_INCOME_FROM_ADMISSIONS			0x01358748
#define RCT2_ADDRESS_CURRENT_COMPANY_VALUE			0x0135874C
#define RCT2_ADDRESS_AWARD_LIST						0x01358760
#define RCT2_ADDRESS_CURRENT_MONEY_ENCRYPTED		0x013587F8
#define RCT2_ADDRESS_CURRENT_INTEREST_RATE			0x0135934A
#define RCT2_ADDRESS_EXPENDITURE_TABLE				0x01357848
#define RCT2_ADDRESS_CURRENT_RESEARCH_LEVEL			0x013573FF

#define RCT2_ADDRESS_HANDYMAN_COLOUR				0x01357BCD
#define RCT2_ADDRESS_MECHANIC_COLOUR				0x01357BCE
#define RCT2_ADDRESS_SECURITY_COLOUR				0x01357BCF

#define RCT2_ADDRESS_CURRENT_INTEREST_RATE			0x0135934A

#define RCT2_ADDRESS_MAP_SIZE						0x01358834
#define RCT2_ADDRESS_PARK_SIZE						0x013580EA

#define RCT2_ADDRESS_SCENARIO_NAME					0x0135920A
#define RCT2_ADDRESS_SCENARIO_DETAILS				0x0135924A

#define RCT2_ADDRESS_PARK_ENTRANCE_X				0x01359350
#define RCT2_ADDRESS_PARK_ENTRANCE_Y				0x01359358
#define RCT2_ADDRESS_PARK_ENTRANCE_Z				0x01359360

#define RCT2_ADDRESS_CURRENT_TICKS					0x013628F4
#define RCT2_ADDRESS_RIDE_LIST						0x013628F8
#define RCT2_ADDRESS_RIDE_COUNT						0x013587C8
#define RCT2_ADDRESS_RIDE_FLAGS						0x0097CF40
#define RCT2_ADDRESS_SAVED_VIEW_X					0x0138869A
#define RCT2_ADDRESS_SAVED_VIEW_Y					0x0138869C
#define RCT2_ADDRESS_RIDE_MEASUREMENTS				0x0138B60C

#define RCT2_ADDRESS_CLIMATE						0x013CA746
#define RCT2_ADDRESS_CURRENT_WEATHER				0x013CA74A
#define RCT2_ADDRESS_NEXT_WEATHER					0x013CA74B
#define RCT2_ADDRESS_CURRENT_TEMPERATURE			0x013CA74C
#define RCT2_ADDRESS_NEXT_TEMPERATURE				0x013CA74D
#define RCT2_ADDRESS_CLIMATE_UPDATE_TIMER			0x013CA748
#define RCT2_ADDRESS_CURRENT_WEATHER_EFFECT			0x013CA74E
#define RCT2_ADDRESS_NEXT_WEATHER_EFFECT			0x013CA74F
#define RCT2_ADDRESS_CURRENT_WEATHER_GLOOM			0x013CA750
#define RCT2_ADDRESS_NEXT_WEATHER_GLOOM				0x013CA751
#define RCT2_ADDRESS_CURRENT_RAIN_LEVEL				0x013CA752
#define RCT2_ADDRESS_NEXT_RAIN_LEVEL				0x013CA753

#define RCT2_ADDRESS_NEWS_ITEM_LIST					0x013CA754

#define RCT2_ADDRESS_CURRENT_FONT_SPRITE_BASE		0x013CE950

#define RCT2_ADDRESS_TILE_MAP_ELEMENT_POINTERS		0x013CE9A4
#define RCT2_ADDRESS_GAME_COMMAND_ERROR_TEXT		0x0141E9AC
#define RCT2_ADDRESS_GAME_COMMAND_ERROR_TITLE		0x0141E9AE

#define RCT2_ADDRESS_GAME_COMMAND_ERROR_STRING_ID	0x0141E9AE
#define RCT2_ADDRESS_CURRENT_ROTATION				0x0141E9E0

#define RCT2_ADDRESS_WATER_RAISE_COST			0x0141F738
#define RCT2_ADDRESS_WATER_LOWER_COST			0x0141F73C

#define RCT2_ADDRESS_WINDOW_LIST					0x01420078
#define RCT2_ADDRESS_NEW_WINDOW_PTR					0x014234B8
#define RCT2_ADDRESS_VIEWPORT_LIST					0x014234BC
#define RCT2_ADDRESS_NEW_VIEWPORT_PTR				0x01423570

#define RCT2_ADDRESS_WINDOW_GUEST_LIST_SELECTED_FILTER	0x00F1EE06
#define RCT2_ADDRESS_WINDOW_GUEST_LIST_SELECTED_TAB		0x00F1EE12
#define RCT2_ADDRESS_WINDOW_GUEST_LIST_SELECTED_VIEW	0x00F1EE13

#define RCT2_ADDRESS_WINDOW_RIDE_LIST_INFORMATION_TYPE	0x00F43833
#define RCT2_ADDRESS_WINDOW_RIDE_LIST_SELECTED_TAB		0x00F43824
#define RCT2_ADDRESS_WINDOW_RIDE_LIST_HIGHLIGHTED_ITEM	0x00F43825

#define RCT2_ADDRESS_WINDOW_STAFF_LIST_SELECTED_TAB		0x00F4390A

#define RCT2_ADDRESS_WINDOW_MAP_SELECTED_TAB		0x014209E4

#define RCT2_ADDRESS_OS_TIME_MINUTE					0x01424654
#define RCT2_ADDRESS_OS_TIME_HOUR					0x01424656
#define RCT2_ADDRESS_OS_TIME_DAY					0x01424304
#define RCT2_ADDRESS_OS_TIME_MONTH					0x01423A04
#define RCT2_ADDRESS_OS_TIME_YEAR					0x01424320
#define RCT2_ADDRESS_OS_TIME_DAYOFWEEK				0x01423B20

#define RCT2_ADDRESS_OS_PLATFORM_ID					0x01423B40
#define RCT2_ADDRESS_OS_MAJOR_VERSION				0x01423B44
#define RCT2_ADDRESS_OS_MINOR_VERSION				0x01423B48
#define RCT2_ADDRESS_OS_BUILD_NUMBER				0x01423B4C
#define RCT2_ADDRESS_OS_USER_NAME					0x01423B68
#define RCT2_ADDRESS_OS_COMPUTER_NAME				0x01423BB8

#define RCT2_ADDRESS_SYS_OEM_ID						0x01423B50
#define RCT2_ADDRESS_SYS_CPU_LEVEL					0x01423B52
#define RCT2_ADDRESS_SYS_CPU_REVISION				0x01423B54
#define RCT2_ADDRESS_SYS_CPU_NUMBER					0x01423B58

#define RCT2_ADDRESS_MEM_TOTAL_PHYSICAL				0x01423B5C
#define RCT2_ADDRESS_MEM_TOTAL_PAGEFILE				0x01423B60
#define RCT2_ADDRESS_MEM_TOTAL_VIRTUAL				0x01423B64

#define RCT2_ADDRESS_SCREEN_CAP_BPP					0x01423C10
#define RCT2_ADDRESS_SCREEN_CAP_RASTER_STRETCH		0x01423C14

static void RCT2_CALLPROC_EBPSAFE(int address)
{
	__asm push ebp
	__asm call address
	__asm pop ebp
}

static void RCT2_CALLPROC_X(int address, int _eax, int _ebx, int _ecx, int _edx, int _esi, int _edi, int _ebp)
{
	__asm {
		push address
		mov eax, _eax
		mov ebx, _ebx
		mov ecx, _ecx
		mov edx, _edx
		mov esi, _esi
		mov edi, _edi
		mov ebp, _ebp
		call [esp]
		add esp, 4
	}
}

static void RCT2_CALLFUNC_X(int address, int *_eax, int *_ebx, int *_ecx, int *_edx, int *_esi, int *_edi, int *_ebp)
{
	__asm {
		// Store C's base pointer
		push ebp

		// Store address to call
		push address

		// Set all registers to the input values
		mov eax, [_eax]
		mov eax, [eax]
		mov ebx, [_ebx]
		mov ebx, [ebx]
		mov ecx, [_ecx]
		mov ecx, [ecx]
		mov edx, [_edx]
		mov edx, [edx]
		mov esi, [_esi]
		mov esi, [esi]
		mov edi, [_edi]
		mov edi, [edi]
		mov ebp, [_ebp]
		mov ebp, [ebp]

		// Call function
		call [esp]
		add esp, 4

		// Store output eax
		push eax
		
		// Put original C base pointer into eax
		mov eax, [esp+4]

		// Store output ebp
		push ebp

		// Set ebp to the original C base pointer
		mov ebp, eax

		// Put output ebp into ebp parameter
		mov eax, [esp]
		push ebx
		mov ebx, [_ebp]
		mov [ebx], eax
		pop ebx
		add esp, 4

		// Get resulting ebx, ecx, edx, esi, edi registers
		mov eax, [_edi]
		mov [eax], edi
		mov eax, [_esi]
		mov [eax], esi
		mov eax, [_edx]
		mov [eax], edx
		mov eax, [_ecx]
		mov [eax], ecx
		mov eax, [_ebx]
		mov [eax], ebx
		pop eax

		// Get resulting eax register
		mov ebx, [_eax]
		mov [ebx], eax

		add esp, 4
	}
}

#endif
