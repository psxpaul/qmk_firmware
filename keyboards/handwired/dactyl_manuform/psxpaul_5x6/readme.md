Install QMK:
    sudo pacman -S qmk
    make git-submodule

One time flashes to set the half in the eeprom (should not have to be done again):
    qmk flash -kb handwired/dactyl_manuform/psxpaul_5x6 -km default -bl dfu-split-left
    qmk flash -kb handwired/dactyl_manuform/psxpaul_5x6 -km default -bl dfu-split-right

If you get "Chip already blank, to force erase use --force." error:
    dfu-programmer atmega32u4 erase --force
    (see https://github.com/qmk/qmk_firmware/issues/22472 or https://github.com/qmk/qmk_firmware/issues/22050#issuecomment-1722308968)

To compile:
    qmk compile -kb handwired/dactyl_manuform/psxpaul_5x6 -km default

To flash:
    qmk flash -kb handwired/dactyl_manuform/psxpaul_5x6 -km default
    *important: do not use a hub/dock while flashing!*
