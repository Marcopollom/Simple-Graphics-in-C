windowmake:
	gcc src/main.c src/color.c src/shape.c src/helper.c -w -framework GLUT -framework OpenGL -framework Cocoa -o window
