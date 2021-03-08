OFILESMS = main.o LinkedList.o MergeSortLL.o
OFILESQS = main.o LinkedList.o QuickSortLL.o
OFILESMSA = main.o LinkedList.o MergeSortLLbyArray.o
OFILESQSA = main.o LinkedList.o QuickSortLLbyArray.o
TARGETMS = test_mergesortll
TARGETQS = test_quicksortll
TARGETMSA = test_mergesortllbyarray
TARGETQSA = test_quicksortllbyarray

CC = gcc
CFLAGS = -Wall -Wextra -Wmissing-prototypes --pedantic -std=c99

.PHONY: all clean run

LDFLAGS = -lm

all: $(TARGETMS) $(TARGETQS) $(TARGETMSA) $(TARGETQSA)
clean:
	rm -f $(OFILESMS) $(OFILESQS) $(OFILESMSA) $(OFILESQSA) $(TARGETMS) $(TARGETQS) $(TARGETMSA) $(TARGETQSA)
run: $(TARGETQS) $(TARGETMS) $(TARGETQSA) $(TARGETMSA)
	./$(TARGETQS) -s 10000
	./$(TARGETQSA) -s 10000
	./$(TARGETMS) -s 10000
	./$(TARGETMSA) -s 10000
$(TARGETQS): $(OFILESQS)
	$(CC) -o $(TARGETQS) $(OFILESQS) $(LDFLAGS)
$(TARGETMS): $(OFILESMS)
	$(CC) -o $(TARGETMS) $(OFILESMS) $(LDFLAGS)
$(TARGETQSA): $(OFILESQSA)
	$(CC) -o $(TARGETQSA) $(OFILESQSA) $(LDFLAGS)
$(TARGETMSA): $(OFILESMSA)
	$(CC) -o $(TARGETMSA) $(OFILESMSA) $(LDFLAGS)

LinkedList.o: LinkedList.c
MergeSortLL.o: MergeSortLL.c SortLL.h LinkedList.h
QuickSortLL.o: QuickSortLL.c SortLL.h LinkedList.h
sortLLbyArrayMS.o: MergeSortLL.c sortLL.h LinkedList.h
sortLLbyArrayQS.o: QuickSortLL.c sortLL.h LinkedList.h 
main.o: main.c SortLL.h LinkedList.h

