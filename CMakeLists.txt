project(racer CXX)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)

SET(GCC_COVERAGE_COMPILE_FLAGS "-O1 -Wall")
SET(GCC_COVERAGE_LINK_FLAGS "-lrt -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

SET(MZAPO
        lib/include/mzapo_parlcd.h renderer/mzapo/mzapo_parlcd.c
        lib/include/mzapo_phys.h renderer/mzapo/mzapo_phys.c
        lib/include/mzapo_regs.h
        )

SET(OBJS
        lib/compiled/mzapo_parlcd.o
        lib/compiled/mzapo_phys.o)

SET(LIB_HEADERS
        lib/include/mzapo_regs.h
        lib/include/mzapo_phys.h
        lib/include/mzapo_parlcd.h)

add_executable(racer
        ${OBJS}
        main.cpp
        behaviour/behaviour.h behaviour/behaviour.cpp
        output/printing.cpp output/printing.h
        scenes/main_menu.cpp scenes/main_menu.h
        scenes/car_selection.cpp scenes/car_selection.h
        scenes/scenes.cpp scenes/scenes.h
        application/application.cpp application/application.h
        io/input.h io/input.cpp
        scenes/track.cpp scenes/track.h scenes/game_over.cpp scenes/game_over.h
        renderer/renderer.cpp renderer/renderer.h
        io/screen.cpp io/screen.h
        renderer/graphics/graphics.cpp renderer/graphics/graphics.h
        io/async_input.cpp io/async_input.h
        exceptions/exceptions.h exceptions/exceptions.cpp
        )

target_include_directories(racer PRIVATE lib/include)

SET_SOURCE_FILES_PROPERTIES(
        ${OBJS}
        PROPERTIES
        EXTERNAL_OBJECT true
        GENERATED true)

SET(target_ip 192.168.202.213)
SET(target_user root)
execute_process(COMMAND whoami OUTPUT_VARIABLE target_dir)

# Remove last \n character
string(LENGTH "${target_dir}" len)
math(EXPR len "${len} - 1")
string(SUBSTRING ${target_dir} 0 ${len} target_dir)

set(target_dir "/tmp/${target_dir}")

execute_process(COMMAND pwd OUTPUT_VARIABLE output)

set(ssh_options "-i /opt/zynq/ssh-connect/mzapo-root-key")
set(address "root@${target_ip}")

add_custom_command(TARGET racer POST_BUILD
        COMMAND echo "built"
        COMMAND ssh -i /opt/zynq/ssh-connect/mzapo-root-key -t ${address} killall gdbserver 1>/dev/null 2>/dev/null || true
        COMMAND echo "killed dgbserver"
        COMMAND ssh -i /opt/zynq/ssh-connect/mzapo-root-key -t ${address} mkdir -p ${target_dir}
        COMMAND echo "created temporary directory"
        COMMAND scp -i /opt/zynq/ssh-connect/mzapo-root-key ${PROJECT_NAME} ${address}:${target_dir}/${PROJECT_NAME}
        COMMAND echo "copied executable")
