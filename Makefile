CC = "g++"
PROJECT = Tarea2SO
SRC = secuencial.cpp

LIBS = `pkg-config opencv4 --cflags --libs`

$(PROJECT) : $(SRC)
	$(CC) $(SRC) -o $(PROJECT) $(LIBS)