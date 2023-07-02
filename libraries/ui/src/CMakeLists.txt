SET(SOURCES screens/ui_UnlockScreen.c
    screens/ui_LockScreen.c
    ui.c
    ui_helpers.c)

add_library(ui ${SOURCES})
