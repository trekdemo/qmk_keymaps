USER = trekdemo
KEYBOARDS = atreus skeletyl

# keymap path
PATH_atreus = keyboardio/atreus
MAKE_atreus = keyboardio/atreus:$(USER)
PATH_skeletyl = bastardkb/skeletyl
MAKE_skeletyl = bastardkb/skeletyl/v1/elitec:$(USER)

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive

	# cleanup old symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

	# Add new symlinks
	ln -s $(shell pwd)/user qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# Run lint check
	cd qmk_firmware; qmk lint -km $(USER) -kb $(PATH_$@) --strict

	# Run build
	make BUILD_DIR=$(shell pwd)/build \
		--jobs=1 \
		--directory=qmk_firmware \
		$(MAKE_$@)

	# Cleanup symlinks
	rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf $(shell pwd)/build
