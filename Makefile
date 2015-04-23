LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video
INCLUDES = /usr/include/opencv-2.3.1/

all: vats

vats: main.o BlobList.o BasicBlob.o blobstationary.o blobextract.o blobclassify.o
	g++ -Wall -g -Wextra -pedantic -o vats main.o BlobList.o BasicBlob.o blobstationary.o blobextract.o blobclassify.o $(LIBS) -lm

main.o: main.cpp
	g++ -Wall -g -Wextra -pedantic -c main.cpp -I$(INCLUDES) -O
	
BlobList.o: BlobList.cpp
	g++ -Wall -g -Wextra -pedantic -c BlobList.cpp -I$(INCLUDES) -O
	
BasicBlob.o: BasicBlob.cpp
	g++ -Wall -g -Wextra -pedantic -c BasicBlob.cpp -I$(INCLUDES) -O
	
blobstationary.o: blobstationary.cpp
	g++ -Wall -g -Wextra -pedantic -c blobstationary.cpp -I$(INCLUDES) -O
	
blobextract.o: blobextract.cpp
	g++ -Wall -g -Wextra -pedantic -c blobextract.cpp -I$(INCLUDES) -O
	
blobclassify.o: blobclassify.cpp
	g++ -Wall -g -Wextra -pedantic -c blobclassify.cpp -I$(INCLUDES) -O
	
clean: 
	rm *.o; rm result.mpg; rm vats
