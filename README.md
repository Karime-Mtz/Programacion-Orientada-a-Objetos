# Programacion-Orientada-a-Objetos

## Contexto
Una biblioteca que requiere un sistema que le permita mantener una organización clara de los libros, registrar información sobre los usuarios y administrar la interacción entre ambos a través de herramientas sencillas.
Existen tres tipos más específicos de libros: Novela, Comic y Biografia.

## Funcionalidad del Programa
Este proyecto administra libros, usuarios y valoraciones mediante un sistema interactivo. El programa ofrece un menú principal con diferentes acciones que puede realizar el usuario, las cuales se concentran en estas cuatro secciones:
- Administración de libros
- Préstamos
- Reseñas y valoraciones
- Administración del usuario

El objetivo es que el usuario interactúe de forma intuitiva con el programa, llevando un registro de sus préstamos y haciendo uso de herramientas extras como las calificaciones y los comentarios.

## ¿Qué es el polimorfismo?
Generalmente el polimorfismo se logra a través de la herencia y su objetivo es que diferentes clases puedan implementar el mismo método de forma distinta. Consiste en definir un método en la clase "madre" (o superclass), para que sus clases "hijas" puedan sobreescribirlo y adaptarlo a sus necesidades. Al momento de ejecutarlo, se llama al método correcto según el tipo de objeto.

Este programa no cuenta con polimorfismo, sin embargo, su implementación es posible.

## Diagrama UML
<img width="2594" height="1525" alt="Diagrama UML" src="https://github.com/user-attachments/assets/6706993e-86d7-4baf-9df9-39bf411fc6ae" />

## Instrucciones
Compilar con: `g++ Main.cpp -o main`

Correr en windows: `.\/main.exe`

## Correcciones
Se estandarizó un estilo para el nombre de las variables, se corrigió la identación y se agregaron comentarios al código.
