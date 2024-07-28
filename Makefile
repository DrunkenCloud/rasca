TARGET = main

SRC = main.cpp

OUT = image.ppm

all: run

$(TARGET):$(SRC)
	g++ $(SRC) -o $(TARGET)

run: $(TARGET)
	rm -f $(OUT)
	./$(TARGET) > $(OUT)

clean:
	rm -f $(TARGET) $(OUT)
