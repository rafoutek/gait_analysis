C = gcc
CC = g++
FLAGS = -Wall -O2 -g
CFLAGS = -Wall -O2 -g -c
LDFLAGS = -lm -lglut -lGL -lX11
LDLIBS = -lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_videoio

TARGET = gait_analysis

$(TARGET): main.o IHM.o fonctionsTraitementImage.o donneesPatients.o Mask.o imageProcessing.o statistics.o libisentlib.a 
	$(CC) -o $@ $(FLAGS) $^ $(LDFLAGS) $(LDLIBS)


main.o: main.cpp GfxLib.h BmpLib.h ESLib.h definitions.h IHM.h fonctionsTraitementImage.h 
	$(CC) $(CFLAGS) $<
	
IHM.o: IHM.cpp GfxLib.h ESLib.h BmpLib.h definitions.h IHM.h fonctionsTraitementImage.h
	$(CC) $(CFLAGS) $<
	
fonctionsTraitementImage.o: fonctionsTraitementImage.cpp definitions.h BmpLib.h fonctionsTraitementImage.h
	$(CC) $(CFLAGS) $<

donneesPatients.o: donneesPatients.cpp donneesPatients.h
	$(CC) $(CFLAGS) $<

statistics.o: statistics.cpp statistics.h
	$(CXX) $(CFLAGS) $<


#lib isen ------------------------------------------
libisentlib.a: BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o
	ar r libisentlib.a BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o
	ranlib libisentlib.a

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	$(C) $(CFLAGS) BmpLib.c

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	$(C) $(CFLAGS) ESLib.c

ErreurLib.o: ErreurLib.c ErreurLib.h
	$(C) $(CFLAGS) ErreurLib.c

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	$(C) $(CFLAGS) GfxLib.c -I/usr/include/GL
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c GfxLib.c -Wno-deprecated-declarations

OutilsLib.o: OutilsLib.c OutilsLib.h
	$(C) $(CFLAGS) OutilsLib.c
	
Mask.o: Mask.cpp Mask.h
	$(CC) $(CFLAGS) $<

imageProcessing.o: imageProcessing.cpp imageProcessing.h
	$(CC) $(CFLAGS) $<
#lib isen ------------------------------------------

zip:
	tar -cvzf libisentlib.tgz *.[ch] *.bmp *.pdf makefile

clean:
	rm -f *~ *.o

deepclean: clean
	rm -f $(TARGET)

