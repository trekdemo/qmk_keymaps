# Keymaps
A user repository with my keymaps for QMK keyboards.

Keyboards:
- BastardKB Skeletyl /  62g Zilent V2 (Silent)
- Keyboardio Atreus

Project setup based on [Post@Medium](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd)


## Compile the keyboard firmwares
To compile all firmwares for all keyboards:

    $ make all

To compile a specific keyboard:

    $ make <keyboard>

To flash the keyboard:

    $ make <keyboard> CMD=flash
