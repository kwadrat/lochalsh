.PHONY: clean all

all: a b

a: a.cpp

b: b.cpp

clean:
	rm a b
