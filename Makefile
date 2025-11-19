include Makefile.properties

all: build run

clean:
	@rm -f $(EXECUTABLE_NAME)
	@rm -f $(EXECUTABLE_NAME)-debug
	@rm -f $(EXECUTABLE_NAME)-optimize
	@rm -f a.out
	@rm -f $(DYLIB_NAME)
	@rm -f $(DYLIB_NAME).zip

build:
	@$(CC) $(CC_FLAGS) \
	main.c \
	$(SOURCE_FILES) \
	-o $(EXECUTABLE_NAME)

run:
	@./$(EXECUTABLE_NAME)

build_debug:
	@$(CC) $(CC_FLAGS) \
	main.c \
	$(SOURCE_FILES) \
	-O0 \
	-g \
	-o $(EXECUTABLE_NAME)-debug

check_leaks: build run_leaks

run_leaks:
	@leaks --atExit -- ./$(EXECUTABLE_NAME)

optimize: build_optimize run_optimize

build_optimize:
	@$(CC) $(CC_FLAGS) \
	main.c \
	$(SOURCE_FILES) \
	-O3 \
	-o $(EXECUTABLE_NAME)-optimize

run_optimize:
	@./$(EXECUTABLE_NAME)-optimize

sanitize: build_sanitize run_sanitize

build_sanitize:
	@$(CC) $(CC_FLAGS) \
	main.c \
	-fsanitize=address \
	-fno-omit-frame-pointer \
	$(SOURCE_FILES) \
	-o $(EXECUTABLE_NAME)-sanitize

run_sanitize:
	@./$(EXECUTABLE_NAME)-sanitize

release: build_release move_files

release_local_github: download_release

build_release:
	@$(CC) $(CC_FLAGS) \
	$(SOURCE_FILES) \
	-O3 \
	-dynamiclib \
	-current_version $(RELEASE_VERSION) \
	-o $(DYLIB_NAME)

move_files:
	@sudo mv $(DYLIB_NAME) $(DYLIB_PATH)
	@sudo cp $(EXECUTABLE_NAME).h $(DYLIB_INCLUDE_PATH)

# local testing
download_release:
	mkir -p tmp && \
	cd tmp && \
	curl -O -J -L https://github.com/standardloop/c-util/releases/download/v0.0.1/libstandardloop-util.zip && \
	unzip libstandardloop-util.zip && \
	sudo mv libstandardloop-util.dylib /usr/local/lib/standardloop/ && \
	sudo mv util.h /usr/local/include/standardloop/ && rm libstandardloop-util.zip

lab:
	@$(CC) $(CC_FLAGS) \
	lab.c \
	-L/usr/local/lib/standardloop \
	-lstandardloop-util \
	-o lab

clean_release:
	sudo rm /usr/local/lib/standardloop/libstandardloop-util.dylib
	sudo rm /usr/local/include/standardloop/util.h
