################################################################################
# Fichier g�n�r� automatiquement. Ne pas modifier !
################################################################################

# Ajouter des entr�es et des sorties lors des appels de variables de g�n�ration par des outils 
CPP_SRCS += \
../Bagage.cpp \
../Chariot.cpp \
../Element.cpp \
../ElementActif.cpp \
../Noeud.cpp \
../Prototype.cpp \
../Tapis.cpp \
../Toboggan.cpp \
../Troncon.cpp \
../Vol.cpp 

CPP_DEPS += \
./Bagage.d \
./Chariot.d \
./Element.d \
./ElementActif.d \
./Noeud.d \
./Prototype.d \
./Tapis.d \
./Toboggan.d \
./Troncon.d \
./Vol.d 

OBJS += \
./Bagage.o \
./Chariot.o \
./Element.o \
./ElementActif.o \
./Noeud.o \
./Prototype.o \
./Tapis.o \
./Toboggan.o \
./Troncon.o \
./Vol.o 


# Chaque sous-r�pertoire doit fournir des r�gles de g�n�ration des sources auxquelles il contribue
%.o: ../%.cpp
	@echo 'G�n�ration du fichier : $<'
	@echo 'Appel en cours : Compilateur Cygwin C++'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'G�n�ration termin�e : $<'
	@echo ' '


