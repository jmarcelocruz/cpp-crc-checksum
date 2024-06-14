CXXFLAGS = -std=c++11 -Iinclude/ ${EXTRA_CXXFLAGS}
LDFLAGS  = ${EXTRA_LDFLAGS}

SOURCES = crc/crc.cpp crc/crc.test.cpp
OBJECTS = $(patsubst %.cpp,%.o,${SOURCES})
DEPENDS = $(patsubst %.cpp,%.d,${SOURCES})

TESTS = ${patsubst %.cpp,%.elf,$(filter %.test.cpp,${SOURCES})}

.PHONY: all
all:

.PHONY: check
check: ${TESTS}
	for test in $^; do ./$${test}; done

.PHONY: clean
clean:
	rm -f ${OBJECTS} ${DEPENDS} ${TESTS}

crc/crc.test.elf: crc/crc.test.o crc/crc.o
	${CXX} $^ -lgtest -lgtest_main ${LDFLAGS} -o $@

${OBJECTS}: %.o: %.cpp
	${CXX} -MMD -MP -c $< ${CXXFLAGS} -o $@

-include ${DEPENDS}
