project(racer CXX)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER /bin/arm-linux-gnueabihf-g++)

SET(GCC_COVERAGE_COMPILE_FLAGS "-O1 -Wall")
SET(GCC_COVERAGE_LINK_FLAGS "-lrt -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

SET(SRC
        src/main.cpp
        src/printing/printing.cpp src/printing/printing.h
        src/scenes/main_menu.cpp src/scenes/main_menu.h
        src/scenes/car_selection.cpp src/scenes/car_selection.h
        src/scenes/scenes.cpp src/scenes/scenes.h
        src/application/application.cpp src/application/application.h
        src/io/input.h src/io/input.cpp
        src/scenes/track.cpp src/scenes/track.h src/scenes/game_over.cpp src/scenes/game_over.h
        src/graphics/renderer/renderer.cpp src/graphics/renderer/renderer.h
        src/graphics/graphics.h
        src/io/async_input.cpp src/io/async_input.h
        src/scenes/track/track_manager.cpp src/scenes/track/track_manager.h
        src/scenes/track/player.cpp src/scenes/track/player.h
        src/game_data/game_data.cpp src/game_data/game_data.h
        src/graphics/textures/textures.cpp src/graphics/textures/textures.h
        src/math/math.cpp src/math/math.h
        src/scenes/track/obstacles/rival.cpp src/scenes/track/obstacles/rival.h
        src/scenes/track/obstacles/obstacle.cpp src/scenes/track/obstacles/obstacle.h
        src/scenes/track/obstacles/box_obstacle.cpp src/scenes/track/obstacles/box_obstacle.h
        src/graphics/text/text.cpp src/graphics/text/text.h
        lib/include/mzapo_parlcd.h src/graphics/text/label/label.cpp src/graphics/text/label/label.h
        )

SET(MZAPO
        lib/include/mzapo_parlcd.h src/graphics/renderer/mzapo/mzapo_parlcd.c
        lib/include/mzapo_phys.h src/graphics/renderer/mzapo/mzapo_phys.c
        lib/include/mzapo_regs.h
        )

SET(OBJS
        lib/compiled/mzapo_parlcd.o
        lib/compiled/mzapo_phys.o)

SET(LIB_HEADERS
        lib/include/mzapo_regs.h
        lib/include/mzapo_phys.h
        )

add_executable(racer
        ${OBJS} ${LIB_HEADERS}
        ${SRC})

target_include_directories(racer PRIVATE
        lib/include src/game_data
        src/components src/printing src/graphics src/math src/io src/graphics/textures)

SET_SOURCE_FILES_PROPERTIES(
        ${OBJS}
        PROPERTIES
        EXTERNAL_OBJECT true
        GENERATED true)

SET(ips
        192.168.202.203
        192.168.202.212
        192.168.202.207
        192.168.202.127
        192.168.202.211
        192.168.202.204
        192.168.202.213
        192.168.202.209)

# Either set board here manually, or pass by argument cmake -DTARGET_BOARD=...
#SET(TARGET_BOARD 5)

# Sets target board to connect to
list(GET ips ${TARGET_BOARD} target_ip)
message("Using board ${TARGET_BOARD} at ${target_ip}.")

SET(target_user root)
execute_process(COMMAND whoami OUTPUT_VARIABLE target_dir)

# Remove last \n character
string(LENGTH "${target_dir}" len)
math(EXPR len "${len} - 1")
string(SUBSTRING ${target_dir} 0 ${len} target_dir)

set(target_dir "/tmp/${target_dir}")

set(ssh_options "-i /opt/zynq/ssh-connect/mzapo-root-key")
set(address "root@${target_ip}")

add_custom_command(TARGET racer POST_BUILD
        COMMAND echo "Built. Transferring to device ${TARGET_BOARD} at ${target_ip}."
        # Do some magic
        COMMAND ssh -i /opt/zynq/ssh-connect/mzapo-root-key -t ${address} killall gdbserver 1>/dev/null 2>/dev/null || true
        COMMAND ssh -i /opt/zynq/ssh-connect/mzapo-root-key ${address} mkdir -p ${target_dir}
        # Copy executable
        COMMAND scp -i /opt/zynq/ssh-connect/mzapo-root-key ${PROJECT_NAME} ${address}:${target_dir}/${PROJECT_NAME}
        # Copy dependent textures
        COMMAND scp -i /opt/zynq/ssh-connect/mzapo-root-key -r ${CMAKE_SOURCE_DIR}/textures/binary ${address}:${target_dir}/textures
        # Copy dependent glyphs
        COMMAND scp -i /opt/zynq/ssh-connect/mzapo-root-key -r ${CMAKE_SOURCE_DIR}/textures/fonts/binary ${address}:${target_dir}/textures/glyphs
        COMMAND echo "Transfer successful.")
