all: ProductoMatriz
ProductoMatriz : ProductoMatriz.o 
	gcc	ProductoMatriz.o	 -o 	ProductoMatriz -lm
