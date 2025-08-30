# Компилятор
CXX = g++
# Флаги компиляции
CXXFLAGS = -Iinclude -Wall -Wextra -O2 -std=c++17 -fopenmp
# Флаги для DLL
DLLFLAGS = -shared
# Имя DLL
DLLNAME = libCurve.dll
# Имя исполняемого файла
EXENAME = myapp.exe
# Файл импорта
IMPLIB = libCurve.dll.a

# Исходные файлы
DLL_SOURCES = src/Curve.cpp src/Circle.cpp src/Ellipse.cpp src/Helix.cpp src/CurveUtils.cpp
DLL_OBJECTS = $(DLL_SOURCES:.cpp=.o)

EXE_SOURCES = main.cpp
EXE_OBJECTS = $(EXE_SOURCES:.cpp=.o)

# Правило по умолчанию
all: $(DLLNAME) $(EXENAME)

# Сборка DLL
$(DLLNAME): $(DLL_OBJECTS)
	$(CXX) $(DLLFLAGS) $(DLL_OBJECTS) -o $(DLLNAME) -Wl,--out-implib,$(IMPLIB) -fopenmp

# Сборка EXE
$(EXENAME): $(EXE_OBJECTS)
	$(CXX) $(EXE_OBJECTS) -o $(EXENAME) -L. -lCurve

# Компиляция для DLL (с экспортом)
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -DCURVE_EXPORT -c $< -o $@

# Компиляция для EXE (без экспорта)
app/%.o: app/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Запуск программы
run: $(DLLNAME) $(EXENAME)
	./$(EXENAME)

# Очистка - используем команды, которые работают везде
clean:
	-@rm -f $(DLL_OBJECTS) $(EXE_OBJECTS) $(DLLNAME) $(EXENAME) $(IMPLIB) 2>/dev/null || true
	-@del /Q $(DLL_OBJECTS) $(EXE_OBJECTS) $(DLLNAME) $(EXENAME) $(IMPLIB) 2>nul || true

.PHONY: all run clean