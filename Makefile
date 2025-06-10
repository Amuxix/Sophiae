QMK_REPO ?= zsa/qmk_firmware
QMK_BRANCH ?= firmware24
LAYOUT ?= sophiae
TARGET ?= keyboards/zsa/moonlander/keymaps/$(LAYOUT)

.PHONY: build
build: copy_keymap submodules_update compile clean_keymap

.PHONY: build_silent
build_silent: copy_keymap submodules_update compile_silent clean_keymap

.PHONY: fast
fast: copy_keymap compile clean_keymap

.PHONY: flash
flash: copy_keymap submodules_update qmk_flash clean_keymap


.PHONY: qmk_flash
qmk_flash:
	make -C zsa_firmware zsa/moonlander:$(LAYOUT):flash || true

.PHONY: compile
compile:
	cd zsa_firmware && qmk compile -kb moonlander -km $(LAYOUT) || true

.PHONY: compile_silent
compile_silent:
# Silent but has no colours
	make -C zsa_firmware zsa/moonlander:$(LAYOUT) silent=true || true

.PHONY: clean_keymap
clean_keymap:
	cd zsa_firmware && rm -rf $(TARGET) moonlander_$(LAYOUT).bin

.PHONY: copy_keymap
copy_keymap:
	cp -r $(LAYOUT) zsa_firmware/$(TARGET)

.PHONY: qmk_setup
qmk_setup: submodules_update
	cd zsa_firmware && qmk setup $(QMK_REPO) -b $(QMK_BRANCH) -y

.PHONY: submodules_update
submodules_update:
	cd zsa_firmware && git stash -q
	git submodule set-branch -b $(QMK_BRANCH) zsa_firmware
	git submodule update --remote
	make -C zsa_firmware git-submodules
	cd zsa_firmware && git stash pop -q || true

.PHONY: submodules_reset
submodules_reset:
	git submodule foreach --recursive git reset --hard HEAD