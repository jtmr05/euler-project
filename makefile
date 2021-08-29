
BIN := a.out

	
.PHONY: clean run alias
clean:
	@if [ -f "$(BIN)" ]; then\
		rm $(BIN);\
	fi

run:
	@if [ -f "$(BIN)" ]; then\
		./$(BIN);\
	fi