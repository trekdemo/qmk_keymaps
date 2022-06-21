# Userspace - sharing code between keymaps
# https://docs.qmk.fm/#/feature_userspace?id=rulesmk

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

# Enables Link Time Optimization (LTO) when compiling the keyboard. This makes
# the process take longer, but it can significantly reduce the compiled size
# (and since the firmware is small, the added time is not noticeable).
LTO_ENABLE = yes

# Additional files
SRC += trekdemo.c
SRC += combos.c

# # You can define RGB_ENABLE in your keymap’s rules.mk and then check for the
# # variable in your userspace’s rules.mk
# ifdef RGB_ENABLE
#   # Include my fancy rgb functions source here
#   SRC += cool_rgb_stuff.c
# endif
