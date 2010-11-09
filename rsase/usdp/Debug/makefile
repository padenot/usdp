################################################################################
# Fichier généré automatiquement. Ne pas modifier !
################################################################################

-include ../makefile.init

RM := rm -rf

# Toutes les sources impliquées par la génération sont définies ici
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Ajouter des entrées et des sorties lors des appels de variables de génération par des outils 

# Toutes les cibles
all: usdp.exe

# Appels d'outil
usdp.exe: $(OBJS) $(USER_OBJS)
	@echo 'Génération de cible : $@'
	@echo 'Appel en cours : Editeur de liens Cygwin C++'
	g++  -o"usdp.exe" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Génération de cible terminée : $@'
	@echo ' '

# Autres cibles
clean:
	-$(RM) $(C_DEPS)$(C++_DEPS)$(CXX_DEPS)$(CPP_DEPS)$(CC_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS) usdp.exe
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
