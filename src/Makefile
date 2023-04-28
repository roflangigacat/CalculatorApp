CC=gcc
CFLAGS= -Wall -Werror -Wextra -lm
SOURCES = SmartCalc.c
SOURCE_LIB = SC.a
SOURCES_TEST = test.c
OUTFILE_TEST = f_test
OS=$(shell uname)
INSTALL_DIR=SC
DIR=
INSTALL_ROFL=Rofl

TEST_FLAGS = -fprofile-arcs -ftest-coverage


ifeq ($(OS), Linux)
	TFLAGS = -lcheck -lm -lpthread -lrt -lsubunit -D_GNU_SOURCE
	QMAKE=qmake
	OPT=-spec linux-g++ CONFIG+=qtquickcompiler
	BUILD_DIR=build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release
	DIR=
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
else
	TFLAGS = -lcheck
	QMAKE=qmake
	OPT=CONFIG+=qtquickcompiler
	BUILD_DIR=build-SmartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release/
	DIR=
	LIBS=-lcheck -lm
endif

all: build

build: clean
	$(QMAKE) -o $(BUILD_DIR)/Makefile ./SmartCalc/SmartCalc.pro $(OPT)
	make -C $(BUILD_DIR)/ first

buildrofl: clean
	$(QMAKE) -o $(BUILD_DIR)/Makefile ./ArmenianCounter/ArmenianCounter.pro $(OPT)
	make -C $(BUILD_DIR)/ first

rebuild: clean all

install: build
	@mkdir -p /Users/$(shell whoami)/$(INSTALL_DIR)
	@cp -r $(BUILD_DIR)$(DIR)SmartCalc.app /Users/$(shell whoami)/$(INSTALL_DIR)
	@cp -r ./UserGuide /Users/$(shell whoami)/$(INSTALL_DIR)
	@mv /Users/$(shell whoami)/$(INSTALL_DIR)/SmartCalc.app ~/Desktop/
	rm -rf a.out *.tgz *.o *.a *.gcda *.gcno *.info *.info report build* *.cfg SmartCalcgu

run:
	open /Users/$(shell whoami)/$(INSTALL_DIR)/SmartCalc.app

rofl: buildrofl
	@mkdir -p /Users/$(shell whoami)/$(INSTALL_ROFL) 
	@cp -r $(BUILD_DIR)$(DIR)ArmenianCounter.app /Users/$(shell whoami)/$(INSTALL_ROFL)
	@cp -r ./UserGuide /Users/$(shell whoami)/$(INSTALL_ROFL)
	@open /Users/$(shell whoami)/$(INSTALL_ROFL)
	rm -rf a.out *.tgz *.o *.a *.gcda *.gcno *.info *.info report build* *.cfg SmartCalcgu

uninstallrofl:
	@rm -rf /Users/$(shell whoami)/$(INSTALL_ROFL)

uninstall:
	@rm -rf /Users/$(shell whoami)/$(INSTALL_DIR)
	@rm -rf ~/Desktop/SmartCalc.app


dist: clean
	tar -czf "SmartCalcZIP.tgz" SmartCalc.c SmartCalc.h ./SmartCalc/*.cpp ./SmartCalc/*.h ./SmartCalc/*.pro ./SmartCalc/*.ui  ./SmartCalc/.* user Makefile

dvi:
	open ../UserGuide/ins.html

tests:
	$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST) $(TFLAGS) -o $(OUTFILE_TEST)
	./$(OUTFILE_TEST)

gcov_report: clean tests
	gcc --coverage $(SOURCES) $(SOURCES_TEST) -o test -lcheck
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

clean:
	rm -rf a.out *.tgz *.o *.a *.gcda *.gcno *.info *.info report build* *.cfg SmartCalcgu test