derle:
	g++ -I ./include/ -o ./lib/YoneticiDugum.o -c ./src/YoneticiDugum.cpp
	g++ -I ./include/ -o ./lib/SatirDugum.o -c ./src/SatirDugum.cpp
	g++ -I ./include/ -o ./lib/YoneticiDugumListesi.o -c ./src/YoneticiDugumListesi.cpp
	g++ -I ./include/ -o ./lib/SatirDugumListesi.o -c ./src/SatirDugumListesi.cpp

	g++ -I ./include/ -o ./bin/main ./lib/YoneticiDugum.o ./lib/SatirDugum.o ./lib/YoneticiDugumListesi.o ./lib/SatirDugumListesi.o -g ./src/main.cpp
