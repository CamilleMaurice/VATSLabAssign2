LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video
INCLUDES = /usr/include/opencv-2.3.1/

all: vats

vats: main.o BlobList.o BasicBlob.o blobstationary.o blobextract.o blobclassify.o
	g++ -o vats main.o BlobList.o BasicBlob.o blobstationary.o blobextract.o blobclassify.o $(LIBS) -lm

main.o: main.cpp
	g++ -c main.cpp -I$(INCLUDES) -O
	
BlobList.o: BlobList.cpp
	g++ -c BlobList.cpp -I$(INCLUDES) -O
	
BasicBlob.o: BasicBlob.cpp
	g++ -c BasicBlob.cpp -I$(INCLUDES) -O
	
blobstationary.o: blobstationary.cpp
	g++ -c blobstationary.cpp -I$(INCLUDES) -O
	
blobextract.o: blobextract.cpp
	g++ -c blobextract.cpp -I$(INCLUDES) -O
	
blobclassify.o: blobclassify.cpp
	g++ -c blobclassify.cpp -I$(INCLUDES) -O
