# ZMK Corne Keyboard Mini Configuration

This repository contains the ZMK firmware configuration for a Corne (CRKBD) keyboard with a custom keymap optimized for German language support.

## Keymap Overview

The keymap consists of 5 layers with Colemak-inspired base layout and homerow mods:

### Layer 0: Base (DEF)
**Display Name:** Base

The primary typing layer featuring:
- Colemak-like letter layout (Q-W-F-P-G / J-L-U-Y on top row)
- Homerow mods on S (Alt), T (Layer 4), D (Win) on left hand
- Homerow mods on H (Win), N (Layer 4), E (Ctrl) on right hand
- Q key: Tap dance (Q / ESC)
- Space key: Tap dance (Space / Tab)
- German locale support (DE_COMMA, DE_PERIOD, DE_MINUS)

**Layout:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ Q/E │  W  │  F  │  P  │  G  │     │  J  │  L  │  U  │  Y  │ MO3 │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  A  │  R  │ S/A │ T/4 │ D/W │     │ H/W │ N/4 │ E/C │  I  │  O  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  Z  │  X  │  C  │  V  │  B  │     │  K  │  M  │  ,  │  .  │  -  │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │ GUI │ MO1 │SPC/T│     │SHFT │ MO2 │BKSP │
                  └─────┴─────┴─────┘     └─────┴─────┴─────┘
```
*Legend: Q/E = Tap Q or double-tap ESC, S/A = Hold Alt, T/4 = Layer 4, D/W = Hold Win, SPC/T = Tap Space or double-tap Tab*

**Combos:** The base layer includes numerous combos for symbols (activated by pressing two keys simultaneously):
- Escape, Delete
- Symbols: %, =, $, #, @, \, *, /, +, -, _
- Brackets: [, ], (, <, >, )

### Layer 1: Navigation & Numbers (NAV)
**Display Name:** NavNum

Navigation and number pad layer:
- Arrow keys and page navigation on left side
- Number pad (0-9) on right side  
- German operators (* on numpad *, + on numpad +)

**Layout:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ ESC │PgUp │  ↑  │PgDn │     │     │     │  7  │  8  │  9  │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │HOME │  ←  │  ↓  │  →  │ END │     │  *  │  4  │  5  │  6  │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │  +  │  1  │  2  │  3  │  ß  │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │ --- │ DEL │     │BKSP │ MO3 │  0  │
                  └─────┴─────┴─────┘     └─────┴─────┴─────┘
```

### Layer 2: Symbols (SYM)
**Display Name:** Symbols

German keyboard symbols and special characters:
- German-specific characters: ä, ö, ü, ß, €
- Mathematical and punctuation symbols
- Uses APR (Auto-Print-Replace) behavior for special characters like backslash and pipe

**Layout:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │  ^  │  °  │  `  │  §  │     │     │  \  │  *  │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  =  │  %  │  !  │  "  │  $  │     │  &  │  /  │  ?  │  #  │  |  │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │  ä  │  ö  │  ü  │  '  │  €  │     │     │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │ DEL │     │BKSP │     │     │
                  └─────┴─────┴─────┘     └─────┴─────┴─────┘
```

### Layer 3: System (ADJ)
**Display Name:** System

Function keys, Bluetooth controls, and system functions:
- F1-F12 function keys
- Bluetooth pairing (BT_SEL 0-2) and clearing (BT_CLR, BT_CLR_ALL)
- Studio unlock for configuration
- Bootloader access

**Layout:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │ F1  │ F2  │ F3  │ F4  │ F5  │     │ F6  │ F7  │ F8  │ F9  │ F10 │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │F11/G│F12/S│     │     │UNLCK│     │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │BT 0 │BT 1 │BT 2 │BTCLR│BTCLA│     │     │     │     │     │BOOT │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │     │     │     │     │     │
                  └─────┴─────┴─────┘     └─────┴─────┴─────┘
```
*Legend: F11/G = F11 with GUI modifier hold, F12/S = F12 with Shift modifier hold, UNLCK = Studio Unlock, BTCLA = BT Clear All, BOOT = Bootloader*

### Layer 4: Brackets (EXTRA)
**Display Name:** Brackets

Dedicated layer for brackets and parentheses (accessed via homerow T/N keys):
- All bracket types: (), [], {}, <, >
- Uses APR (Auto-Print-Replace) behavior for custom bracket implementations

**Layout:**
```
┌─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │  <  │     │     │     │     │  >  │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │  {  │  [  │  (  │     │     │     │  )  │  ]  │  }  │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │     │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │ SPC │     │ ENT │     │     │
                  └─────┴─────┴─────┘     └─────┴─────┴─────┘
```

## Special Features

### Homerow Mods
The keymap uses homerow modifications for ergonomic access to modifier keys:
- **Left hand:** Alt (S), Layer 4 (T), Win/GUI (D)
- **Right hand:** Win/GUI (H), Layer 4 (N), Ctrl (E)
- Configured with 200ms tapping term, tap-preferred flavor, and 120ms idle requirement

### Tap Dances
- **Q key:** Single tap = Q, Double tap = ESC
- **Space key:** Single tap = Space, Double tap = Tab

### Mod-Morphs
- **Left Parenthesis:** Normal = (, With Shift = <
- **Right Parenthesis:** Normal = ), With Shift = >

### Custom Behaviors
- **Caps Word:** Activated via dedicated behavior, continues through minus and backspace
- **APR (Auto-Print-Replace):** Custom ZMK behavior that provides special character handling for symbols and brackets that require specific keycode sequences

## Building

This configuration is designed for ZMK firmware. Build using the standard ZMK build process with the appropriate board configuration for your Corne keyboard.

## Display Support

The firmware includes working display support. No additional configuration needed for OLED displays.

## German Keyboard Support

This keymap uses German locale (`locale/keys_de.h`) for proper character mapping including:
- Umlauts: ä, ö, ü
- Special characters: ß, €, §, °
- German-specific symbols and punctuation
