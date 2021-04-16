
CXXFLAGS=-ansi

TARGET=filtrar-covid mitjana-covid

all: $(TARGET)

filtrar-covid : filtrar-covid.cpp

mitjana-covid : mitjana-covid.cpp

clean:
	$(RM) $(TARGET)

test: $(TARGET)
	for fitxer in *.csv; do \
		cat $$fitxer | ./filtrar-covid | ./mitjana-covid; \
	done

test2: mitjana-covid
	for fitxer in *.csv2; do \
		cat $$fitxer | ./mitjana-covid; \
	done
