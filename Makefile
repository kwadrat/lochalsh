.PHONY: clean all

all: a b c d

a: a.cpp

b: b.cpp

c: c.cpp

d: d.cpp

clean:
	rm a b c d
