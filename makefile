huffman: Huffman_driver.o HuffmanProject.o
	g++ Huffman_driver.o HuffmanProject.o -o huffman

Huffman_driver.o: Huffman_driver.cpp 
	g++ -c Huffman_driver.cpp -o Huffman_driver.o


HuffmanProject.o: HuffmanProject.cpp 
	g++ -c HuffmanProject.cpp -o HuffmanProject.o

clean:
	rm *.o huffman
