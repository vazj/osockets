CC = g++
CFLAGS = -Wall -O2 -I inc
MODULES=obj/address.o\
	obj/socketconnection.o\
	obj/socket.o\
	obj/socketexception.o\
	obj/sockettoolbox.o\
	obj/tcpserversocket.o\
	obj/tcpsocket.o\
	obj/winsockinit.o\
	obj/imp/addrinfobase.o\
	obj/imp/addrinfo.o\
	obj/imp/hintstcpclient.o\
	obj/imp/hintstcpserver.o\
	obj/imp/mutex.o\
	obj/imp/osocketfunctors.o\
	obj/imp/osocketsdef.o

HEADS=inc/socketexception.h\
	inc/address.h\
	inc/socketconnection.h\
	inc/socket.h\
	inc/sockettoolbox.h\
	inc/tcpserversocket.h\
	inc/tcpsocket.h\
	inc/winsockinit.h\
	inc/imp/addrinfobase.h\
	inc/imp/addrinfobaseif.h\
	inc/imp/addrinfo.h\
	inc/imp/hintstcpclient.h\
	inc/imp/hintstcpserver.h\
	inc/imp/mutex.h\
	inc/imp/osocketfunctors.h\
	inc/imp/osocketsdef.h\
	inc/imp/osockettypes.h\
	inc/imp/stringable.h

all: libosockets.so

libosockets.so: $(MODULES)
	$(CC) $(CFLAGS) -shared $(MODULES) -o libosockets.so


obj/address.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/address.cpp -o obj/address.o

obj/socketconnection.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/socketconnection.cpp -o obj/socketconnection.o

obj/socket.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/socket.cpp -o obj/socket.o

obj/socketexception.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/socketexception.cpp -o obj/socketexception.o

obj/sockettoolbox.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/sockettoolbox.cpp -o obj/sockettoolbox.o

obj/tcpserversocket.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/tcpserversocket.cpp -o obj/tcpserversocket.o

obj/tcpsocket.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/tcpsocket.cpp -o obj/tcpsocket.o

obj/winsockinit.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/winsockinit.cpp -o obj/winsockinit.o

obj/imp/addrinfobase.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/addrinfobase.cpp -o obj/imp/addrinfobase.o

obj/imp/addrinfo.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/addrinfo.cpp -o obj/imp/addrinfo.o

obj/imp/hintstcpclient.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/hintstcpclient.cpp -o obj/imp/hintstcpclient.o

obj/imp/hintstcpserver.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/hintstcpserver.cpp -o obj/imp/hintstcpserver.o

obj/imp/mutex.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/mutex.cpp -o obj/imp/mutex.o

obj/imp/osocketfunctors.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/osocketfunctors.cpp -o obj/imp/osocketfunctors.o

obj/imp/osocketsdef.o: $(HEADS)
	$(CC) $(CFLAGS) -fPIC -c src/imp/osocketsdef.cpp -o obj/imp/osocketsdef.o

clean:
	rm obj/*.o obj/imp/*.o libosockets.so

