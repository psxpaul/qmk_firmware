Link to onshape projects:
    https://cad.onshape.com/documents/7f8587620c189b429d36b165/w/939478591eba55418e27dea9/e/07706a9968f21f081d2ca0f4 (left)
    https://cad.onshape.com/documents/471dc58aa378af9f52cd9337/w/57eae4bdefaa70e6c7a43ae0/e/47b9801af1b60e2df998d693 (right)

Install QMK:
    sudo pacman -S qmk
    make git-submodule

One time flashes to set the half in the eeprom (should not have to be done again):
    qmk flash -kb handwired/dactyl_manuform/psxpaul_4x6 -km default -bl dfu-split-left
    qmk flash -kb handwired/dactyl_manuform/psxpaul_4x6 -km default -bl dfu-split-right

If you get "Chip already blank, to force erase use --force." error:
    dfu-programmer atmega32u4 erase --force
    (see https://github.com/qmk/qmk_firmware/issues/22472 or https://github.com/qmk/qmk_firmware/issues/22050#issuecomment-1722308968)

To compile:
    qmk compile -kb handwired/dactyl_manuform/psxpaul_4x6 -km default

To flash:
    qmk flash -kb handwired/dactyl_manuform/psxpaul_4x6 -km default
    *important: do not use a hub/dock while flashing!*
