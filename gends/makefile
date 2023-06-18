# makefile libgends

TARGET= libgends.so
CC= gcc
CFLAGS= -ansi -g -pedantic -fPIC

OBJS= vector.o heap.o GenQ.o listItr.o Itrfun.o DubLinkList.o HashMap.o

HEAP_PATH = heap
VECTOR_PATH = vector
QUE_PATH = queue
LIST_PATH= list
HASH_PATH= map

$(TARGET): $(OBJS)
	$(CC) -shared -o $(TARGET) $(OBJS)
	
vector.o: $(VECTOR_PATH)/vector.c $(VECTOR_PATH)/vector.h
	$(CC) $(CFLAGS) -I $(VECTOR_PATH) -c $(VECTOR_PATH)/vector.c
	
heap.o: $(HEAP_PATH)/heap.c $(VECTOR_PATH)/vector.c $(HEAP_PATH)/genHeap.h $(VECTOR_PATH)/vector.h
	$(CC) $(CFLAGS) -I $(HEAP_PATH) -c $(HEAP_PATH)/heap.c

GenQ.o: $(QUE_PATH)/GenQ.c $(QUE_PATH)/genqueue.h
	$(CC) $(CFLAGS) -I $(QUE_PATH) -c $(QUE_PATH)/GenQ.c
	
listItr.o: $(LIST_PATH)/listItr.c $(LIST_PATH)/listItr.h
	$(CC) $(CFLAGS) -I $(LIST_PATH) -c $(LIST_PATH)/listItr.c
	
Itrfun.o: $(LIST_PATH)/Itrfun.c $(LIST_PATH)/listitrfun.h
	$(CC) $(CFLAGS) -I $(LIST_PATH) -c $(LIST_PATH)/Itrfun.c
	
DubLinkList.o: $(LIST_PATH)/DubLinkList.c $(LIST_PATH)/list.h
	$(CC) $(CFLAGS) -I $(LIST_PATH) -c $(LIST_PATH)/DubLinkList.c
	
HashMap.o: $(HASH_PATH)/HashMap.c $(HASH_PATH)/HashMap.h $(LIST_PATH)/listitrfun.h $(LIST_PATH)/listItr.h $(LIST_PATH)/list.h
	$(CC) $(CFLAGS) -I $(HASH_PATH) -I $(LIST_PATH) -c $(HASH_PATH)/HashMap.c

clean:
	rm -f $(TARGET) $(OBJS)
	
	
	
	
