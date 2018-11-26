cmake_minimum_required(VERSION 3.5)

include_directories(
	../include/
)

set(OUTPUT ServerUnitTests)
project(${CLIENT} LANGUAGES CXX)

set(SRC
	../src/Ecs/Entity.cpp
	../src/Ecs/Components/Health.cpp
	../src/Ecs/Components/Position.cpp
	../src/Ecs/Components/Acceleration.cpp
	../src/Ecs/Components/Damages.cpp
	../src/Ecs/Components/HitBox.cpp
)

set(HEAD
	../include/Constants.hpp
	../include/Entity.hpp
	../include/Components/IComponent.hpp
	../include/Components/AComponent.hpp
	../include/Components/Health.hpp
	../include/Components/Position.hpp
	../include/Components/Acceleration.hpp
	../include/Components/Damages.hpp
	../include/Components/HitBox.hpp
	../include/Components/AI.hpp
)

set(TESTS
	EntityTests.cpp
)

add_executable(${OUTPUT} ${SRC} ${HEAD} ${TESTS})

target_link_libraries(${OUTPUT}
	criterion
)