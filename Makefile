USER = trekdemo
KEYBOARDS = atreus skeletyl dilemma

# Keybard mapping
PATH_atreus = keyboardio/atreus
MAKE_atreus = keyboardio/atreus
PATH_skeletyl = bastardkb/skeletyl
MAKE_skeletyl = bastardkb/skeletyl/v1/elitec
PATH_dilemma = bastardkb/dilemma
MAKE_dilemma = bastardkb/dilemma

all: $(KEYBOARDS)

CMD = "compile"
.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# Remove old keymaps
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

	# Init submodule
	git submodule update --init --recursive

	# Create symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# Run lint and compile/flash/...
	cd qmk_firmware; \
		qmk lint --strict --keymap $(USER) --keyboard $(MAKE_$@) && \
		qmk $(CMD) --parallel 1 --keymap $(USER) --keyboard $(MAKE_$@)

	# Cleanup symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf $(shell pwd)/build
