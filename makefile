# Compiler & flags
CC = clang++
CFLAGS = -Wall -Wextra -Iinclude `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

# Dossiers
SRC_DIR = .
BUILD_DIR = build

# Fichiers source
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Fichiers objets dans build/
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Nom de l'exécutable
TARGET = main

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compilation des .o dans build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier build s'il n'existe pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Nettoyage
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
