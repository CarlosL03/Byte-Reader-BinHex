#######################################################
# Makefile for CS530 Assignment #1
# Carlos Lopez
#######################################################


EXEC = xed

$(EXEC):
	g++ xed.cpp -o xed
	./xed sampletxtfile.txt
	./xed -b sampletxtfile.txt


###################[ EOF: Makefile ] ###################