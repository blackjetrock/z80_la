# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/tree/downloaded_tools/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
project(z80_la C CXX ASM)
set(PICO_COPY_TO_RAM 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# SD FAT LIB
#add_subdirectory(/tree/downloaded_tools/pico/ajm-no-OS-FatFS-SD-SPI-RPi-Pico/FatFs_SPI build)

# Add executable. Default name is the project name, version 0.1

add_executable(z80_la
z80_la.c
#flashcode.c
#../common/link_common.c
)

#pico_generate_pio_header(z80_la ${CMAKE_CURRENT_LIST_DIR}/picoputer.pio)

pico_set_program_name(z80_la "z80_la")
pico_set_program_version(z80_la "0.1")

#pico_enable_stdio_uart(z80_la 0)
pico_enable_stdio_usb(z80_la 1)

# Add the standard library to the build
target_link_libraries(z80_la pico_stdlib)

IF (NOT DEFINED N_SD_CARDS)
    SET(N_SD_CARDS 1)
ENDIF()
target_compile_definitions(z80_la PUBLIC DEBUG N_SD_CARDS=${N_SD_CARDS})

# Add any user requested libraries
target_link_libraries(z80_la
        #hardware_i2c
        hardware_pio
        hardware_clocks
	hardware_adc
	hardware_dma
#        pico_sd_card
        pico_multicore
#	FatFs_SPI
        )

pico_add_extra_outputs(z80_la)

