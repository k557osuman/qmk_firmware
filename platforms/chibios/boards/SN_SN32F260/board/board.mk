# List of all the board related files.
BOARDSRC = $(CHIBIOS_CONTRIB)/os/hal/boards/SN_SN32F260/board.c

# Required include directories
BOARDINC = $(CHIBIOS_CONTRIB)/os/hal/boards/SN_SN32F260

# Optimize for size
OPT_DEFS = -Os

# Some options to reduce RAM usage
LDFLAGS += --specs=nano.specs
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
USE_LINK_GC = yes
LTO_ENABLE = yes

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)