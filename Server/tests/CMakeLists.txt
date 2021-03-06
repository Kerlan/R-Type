cmake_minimum_required(VERSION 3.5)

include_directories(
	../include/
)

set(OUTPUT ServerUnitTests)
project(${CLIENT} LANGUAGES CXX)

set(SRC
	../src/Ecs/Entity.cpp
	../src/Ecs/EntityManager.cpp
	../src/Ecs/HitboxSystem.cpp
	../src/Ecs/Components/Health.cpp
	../src/Ecs/Components/Position.cpp
	../src/Ecs/Components/Acceleration.cpp
	../src/Ecs/Components/Damages.cpp
	../src/Ecs/Components/HitBox.cpp
	../src/Ecs/Components/Drawable.cpp
)

set(HEAD
	../include/Constants.hpp
	../include/Entity.hpp
	../include/EntityManager.hpp
	../include/ISystem.hpp
	../include/ASystem.hpp
	../include/HitboxSystem.hpp
	../include/AISystem.hpp
	../include/Components/IComponent.hpp
	../include/Components/AComponent.hpp
	../include/Components/Health.hpp
	../include/Components/Position.hpp
	../include/Components/Acceleration.hpp
	../include/Components/Damages.hpp
	../include/Components/HitBox.hpp
	../include/Components/AI.hpp
	../include/Components/Weapon.hpp
	../include/Components/Drawable.hpp
)

set(TESTS
	EntityTests.cpp
	EntityManagerTests.cpp
	HitboxSystemTests.cpp
)

add_executable(${OUTPUT} ${SRC} ${HEAD} ${TESTS})

target_link_libraries(${OUTPUT}
	criterion
)