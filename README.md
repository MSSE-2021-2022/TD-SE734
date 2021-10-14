# GPIO

Partie GPIO du TP

- [ ] Ca serait cool de faire une sorte de doc ici pour synthétiser ce dont on a besoin dans la fiche technique

__Allumer une LED__  
1. Activer le périphérique GPIO du port correspondant  
2. Mettre une pin en sortie  
3. Lui mettre l'état haut  

__Activation du périphérique GPIO__  
Le module RCC va activer ou désactiver des périphériques via leur Clock, comme défini dans le manuel page 251. En ce qui concerne les E/S, c'est le registre __RCC_AHB2ENR__.  
Ce registre est localisé à l'adresse __0x40021000__ (datasheet page 81) avec un offset de __0x4C__.  
Pour activer le port B, mettre le bit 1 du registre à 1.  
  
__Pin en INPUT/OUTPUT__  
La documentation des GPIOs est dans le manuel page 303, avec les adresses de début dans le datasheet page 81.  
Pour mettre une pin en entrée, il faut mettre les valeurs 00 dans le registre __GPIOx_MODER__, et en sortie les valeurs 01 au niveau des bits correspondants.  

__Allumer une LED__  
Registre __GPIOx_ODR__ documenté page 305 du manuel.  
