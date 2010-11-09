################################################################################
# Fichier généré automatiquement. Ne pas modifier !
################################################################################

# Ajouter des entrées et des sorties lors des appels de variables de génération par des outils 
CPP_SRCS += \
../usdp.cpp 

CPP_DEPS += \
./usdp.d 

OBJS += \
./usdp.o 


# Chaque sous-répertoire doit fournir des règles de génération des sources auxquelles il contribue
%.o: ../%.cpp
	@echo 'Génération du fichier : $<'
	@echo 'Appel en cours : Compilateur Cygwin C++'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Génération terminée : $<'
	@echo ' '


