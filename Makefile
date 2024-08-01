TARGET = ./main
SRC = ./main.cpp
OUT = ./image.ppm

all: $(TARGET) run

$(TARGET): $(SRC)
	rm -f $(TARGET)
	g++ $(SRC) -o $(TARGET)

run: $(TARGET)
	rm -f $(OUT)
	./$(TARGET) > $(OUT)

clean:
	rm -f $(TARGET) $(OUT)
