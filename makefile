emitpoly:
	$(CC) -o emitpoly pspolygon.c

emitpolyweb: emitpoly
	cp emitpoly emitpolyweb
