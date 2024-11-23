Install QMK:
    sudo pacman -S qmk
    make git-submodule

One time flashes to set the half in the eeprom (should not have to be done again):
    make handwired/dactyl_manuform/psxpaul_5x7:default:dfu-split-left
    make handwired/dactyl_manuform/psxpaul_5x7:default:dfu-split-right

To compile:
    qmk compile -kb handwired/dactyl_manuform/psxpaul_5x7 -km default

To flash:
    qmk flash -kb handwired/dactyl_manuform/psxpaul_5x7 -km default
    *important: do not use a hub/dock while flashing!*
