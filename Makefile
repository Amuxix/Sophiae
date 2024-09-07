QMK_REPO ?= zsa/qmk_firmware
QMK_BRANCH ?= firmware23
LAYOUT ?= mcoding
TARGET ?= keyboards/moonlander/keymaps/$(LAYOUT)

.PHONY: build
build: clean qmk_setup copy
	cd zsa_firmware && qmk compile -kb moonlander -km $(LAYOUT)

.PHONY: build_silent
build_silent: clean qmk_setup copy
# Silent but has no colours
	make -C zsa_firmware moonlander:$(LAYOUT) silent=true

.PHONY: fast
fast: clean copy
	cd zsa_firmware && qmk compile -kb moonlander -km $(LAYOUT)

.PHONY: flash
flash: clean qmk_setup copy
	make -C zsa_firmware moonlander:$(LAYOUT):flash


.PHONY: clean
clean:
	cd zsa_firmware && rm -rf $(TARGET) moonlander_$(LAYOUT).bin

.PHONY: copy
copy:
	cp -r $(LAYOUT) zsa_firmware/$(TARGET)

.PHONY: qmk_setup
qmk_setup:
	make -C zsa_firmware git-submodules
	cd zsa_firmware && qmk setup $(QMK_REPO) -b $(QMK_BRANCH) -y
