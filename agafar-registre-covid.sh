#!/bin/bash

REGISTRE=registre-covid.csv

echo Iniciem la baixada de $REGISTRE
if command -v curl &> /dev/null
then
   curl --output $REGISTRE "https://analisi.transparenciacatalunya.cat/api/views/jj6z-iyrp/rows.csv?accessType=DOWNLOAD"
else
  wget "https://analisi.transparenciacatalunya.cat/api/views/jj6z-iyrp/rows.csv?accessType=DOWNLOAD" --output-document $REGISTRE
fi
echo Baixada finalitzada
echo \# >> $REGISTRE
