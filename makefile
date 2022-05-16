hepsi: derle calistir
derle:
		gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c
		gcc -I ./include/ -o ./lib/Kontrol.o -c ./src/Kontrol.c
		gcc -I ./include/ -o ./bin/test ./lib/Dosya.o ./lib/Kontrol.o ./src/Program.c
calistir:
		./bin/test